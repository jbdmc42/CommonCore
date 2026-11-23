#include "../../include/minirt.h"

#define INTERSECTION_EPSILON 1e-6

static t_vector	hit_point(const t_ray *ray, double distance)
{
	return (vector_add(ray->origin, vector_scale(ray->direction, distance)));
}

static t_vector	object_normal(const t_objects *object, t_vector point)
{
	t_vector	normal;
	t_vector	offset;
	t_vector	axis;
	double		axial_position;

	if (object->type == 0)
		return (vector_norm(((t_plane *)object->obj)->normal));
	if (object->type == 1)
	{
		offset = vector_sub(point, ((t_sphere *)object->obj)->center);
		return (vector_norm(offset));
	}
	if (object->type == 2)
	{
		axis = vector_norm(((t_cylinder *)object->obj)->normal);
		offset = vector_sub(point, ((t_cylinder *)object->obj)->center);
		axial_position = vector_dot(offset, axis);
		if (fabs(fabs(axial_position)
				- ((t_cylinder *)object->obj)->height / 2.0) <= 1e-5)
		{
			if (axial_position >= 0.0)
				return (axis);
			return (vector_scale(axis, -1.0));
		}
		normal = vector_sub(offset, vector_scale(axis, axial_position));
		return (vector_norm(normal));
	}
	normal.x = 0.0;
	normal.y = 0.0;
	normal.z = 0.0;
	return (normal);
}

int	intersect_sphere(const t_ray *ray, const t_sphere *sphere,
		double *distance, t_vector *point)
{
	t_vector	offset;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		root;
	double		radius;

	if (!ray || !sphere || !distance || !point || sphere->diameter <= 0.0)
		return (0);
	offset = vector_sub(ray->origin, sphere->center);
	radius = sphere->diameter / 2.0;
	a = vector_dot(ray->direction, ray->direction);
	if (a <= INTERSECTION_EPSILON)
		return (0);
	half_b = vector_dot(offset, ray->direction);
	c = vector_dot(offset, offset) - radius * radius;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0.0)
		return (0);
	root = (-half_b - sqrt(discriminant)) / a;
	if (root <= INTERSECTION_EPSILON)
		root = (-half_b + sqrt(discriminant)) / a;
	if (root <= INTERSECTION_EPSILON || !isfinite(root))
		return (0);
	*distance = root;
	*point = hit_point(ray, root);
	return (1);
}

int	intersect_plane(const t_ray *ray, const t_plane *plane,
		double *distance, t_vector *point)
{
	t_vector	offset;
	double		denominator;
	double		root;

	if (!ray || !plane || !distance || !point)
		return (0);
	denominator = vector_dot(ray->direction, plane->normal);
	if (fabs(denominator) <= INTERSECTION_EPSILON)
		return (0);
	offset = vector_sub(plane->point, ray->origin);
	root = vector_dot(offset, plane->normal) / denominator;
	if (root <= INTERSECTION_EPSILON || !isfinite(root))
		return (0);
	*distance = root;
	*point = hit_point(ray, root);
	return (1);
}

static void	check_cylinder_side(const t_ray *ray, const t_cylinder *cylinder,
		t_vector axis, double *closest)
{
	t_vector	offset;
	t_vector	ray_perpendicular;
	t_vector	offset_perpendicular;
	double		ray_axis;
	double		offset_axis;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		root;
	double		axial_position;
	int			i;

	offset = vector_sub(ray->origin, cylinder->center);
	ray_axis = vector_dot(ray->direction, axis);
	offset_axis = vector_dot(offset, axis);
	ray_perpendicular = vector_sub(ray->direction,
			vector_scale(axis, ray_axis));
	offset_perpendicular = vector_sub(offset,
			vector_scale(axis, offset_axis));
	a = vector_dot(ray_perpendicular, ray_perpendicular);
	if (a <= INTERSECTION_EPSILON)
		return ;
	half_b = vector_dot(offset_perpendicular, ray_perpendicular);
	c = vector_dot(offset_perpendicular, offset_perpendicular)
		- (cylinder->diameter * cylinder->diameter / 4.0);
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0.0)
		return ;
	i = 0;
	while (i < 2)
	{
		if (i == 0)
			root = (-half_b - sqrt(discriminant)) / a;
		else
			root = (-half_b + sqrt(discriminant)) / a;
		axial_position = offset_axis + root * ray_axis;
		if (root > INTERSECTION_EPSILON && root < *closest
			&& fabs(axial_position) <= cylinder->height / 2.0
			&& isfinite(root))
			*closest = root;
		i++;
	}
}

static void	check_cylinder_cap(const t_ray *ray, const t_cylinder *cylinder,
		t_vector axis, double cap_offset, double *closest)
{
	t_vector	cap_center;
	t_vector	from_cap;
	t_vector	radial;
	double		denominator;
	double		root;

	denominator = vector_dot(ray->direction, axis);
	if (fabs(denominator) <= INTERSECTION_EPSILON)
		return ;
	cap_center = vector_add(cylinder->center, vector_scale(axis, cap_offset));
	from_cap = vector_sub(cap_center, ray->origin);
	root = vector_dot(from_cap, axis) / denominator;
	if (root <= INTERSECTION_EPSILON || root >= *closest || !isfinite(root))
		return ;
	radial = vector_sub(hit_point(ray, root), cap_center);
	if (vector_dot(radial, radial)
		<= cylinder->diameter * cylinder->diameter / 4.0)
		*closest = root;
}

int	intersect_cylinder(const t_ray *ray, const t_cylinder *cylinder,
		double *distance, t_vector *point)
{
	t_vector	axis;
	double		axis_length;
	double		closest;

	if (!ray || !cylinder || !distance || !point || cylinder->diameter <= 0.0
		|| cylinder->height <= 0.0)
		return (0);
	axis_length = sqrt(vector_dot(cylinder->normal, cylinder->normal));
	if (axis_length <= INTERSECTION_EPSILON || !isfinite(axis_length))
		return (0);
	axis = vector_scale(cylinder->normal, 1.0 / axis_length);
	closest = INFINITY;
	check_cylinder_side(ray, cylinder, axis, &closest);
	check_cylinder_cap(ray, cylinder, axis, cylinder->height / 2.0,
		&closest);
	check_cylinder_cap(ray, cylinder, axis, -cylinder->height / 2.0,
		&closest);
	if (!isfinite(closest))
		return (0);
	*distance = closest;
	*point = hit_point(ray, closest);
	return (1);
}

static int	intersect_object(const t_ray *ray, const t_objects *object,
		double *distance, t_vector *point, t_rgb *color)
{
	if (!object || !object->obj)
		return (0);
	if (object->type == 0)
	{
		*color = ((t_plane *)object->obj)->color;
		return (intersect_plane(ray, (t_plane *)object->obj, distance, point));
	}
	if (object->type == 1)
	{
		*color = ((t_sphere *)object->obj)->color;
		return (intersect_sphere(ray, (t_sphere *)object->obj, distance, point));
	}
	if (object->type == 2)
	{
		*color = ((t_cylinder *)object->obj)->color;
		return (intersect_cylinder(ray, (t_cylinder *)object->obj, distance,
				point));
	}
	return (0);
}

int	intersect_scene(const t_scene *scene, const t_ray *ray, t_hit *hit)
{
	double	distance;
	double	closest;
	t_vector	point;
	t_rgb	color;
	const t_objects	*closest_object;
	int		i;
	int		found;

	if (!scene || !ray || !hit || (scene->obj_count > 0 && !scene->objs))
		return (0);
	closest = INFINITY;
	found = 0;
	closest_object = NULL;
	i = 0;
	while (i < scene->obj_count)
	{
		if (intersect_object(ray, &scene->objs[i], &distance, &point, &color)
			&& distance < closest)
		{
			closest = distance;
			hit->object_type = scene->objs[i].type;
			hit->color = color;
			hit->point = point;
			closest_object = &scene->objs[i];
			found = 1;
		}
		i++;
	}
	if (!found)
		return (0);
	hit->distance = closest;
	hit->normal = object_normal(closest_object, hit->point);
	return (1);
}
