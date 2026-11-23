#include "../../include/minirt.h"

#define SHADOW_BIAS 1e-4

static int	clamp_color(double channel)
{
	if (channel < 0.0)
		return (0);
	if (channel > 255.0)
		return (255);
	return ((int)channel);
}

static int	shade_channel(int object_channel, int ambient_channel,
		int light_channel, double ambient_ratio, double light_ratio,
		double diffuse)
{
	double	ambient;
	double	direct;

	ambient = ambient_ratio * ambient_channel / 255.0;
	direct = light_ratio * light_channel / 255.0 * diffuse;
	return (clamp_color(object_channel * (ambient + direct)));
}

static int	point_is_shadowed(const t_scene *scene, const t_hit *hit,
		t_vector to_light, double light_distance)
{
	t_ray	shadow_ray;
	t_hit	shadow_hit;

	shadow_ray.direction = to_light;
	if (vector_dot(hit->normal, to_light) < 0.0)
		shadow_ray.origin = vector_sub(hit->point,
				vector_scale(hit->normal, SHADOW_BIAS));
	else
		shadow_ray.origin = vector_add(hit->point,
				vector_scale(hit->normal, SHADOW_BIAS));
	if (!intersect_scene(scene, &shadow_ray, &shadow_hit))
		return (0);
	return (shadow_hit.distance < light_distance - SHADOW_BIAS);
}

t_rgb	shade_hit(const t_scene *scene, const t_hit *hit)
{
	t_rgb		color;
	t_vector	to_light;
	double		distance;
	double		diffuse;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	if (!scene || !hit)
		return (color);
	to_light = vector_sub(scene->light.position, hit->point);
	distance = vector_len(to_light);
	diffuse = 0.0;
	if (distance > 0.0 && isfinite(distance))
	{
		to_light = vector_scale(to_light, 1.0 / distance);
		diffuse = vector_dot(hit->normal, to_light);
		if (hit->object_type == 0)
			diffuse = fabs(diffuse);
		else if (diffuse < 0.0)
			diffuse = 0.0;
		if (diffuse > 0.0
			&& point_is_shadowed(scene, hit, to_light, distance))
			diffuse = 0.0;
	}
	color.r = shade_channel(hit->color.r, scene->ambient.color.r,
			scene->light.color.r, scene->ambient.ratio,
			scene->light.ratio, diffuse);
	color.g = shade_channel(hit->color.g, scene->ambient.color.g,
			scene->light.color.g, scene->ambient.ratio,
			scene->light.ratio, diffuse);
	color.b = shade_channel(hit->color.b, scene->ambient.color.b,
			scene->light.color.b, scene->ambient.ratio,
			scene->light.ratio, diffuse);
	return (color);
}
