#include "minirt.h"

static int	is_translation_key(int keycode)
{
	return (keycode == XK_a || keycode == XK_A || keycode == XK_d
		|| keycode == XK_D || keycode == XK_r || keycode == XK_R
		|| keycode == XK_f || keycode == XK_F || keycode == XK_w
		|| keycode == XK_W || keycode == XK_s || keycode == XK_S);
}

static int	is_rotation_key(int keycode)
{
	return (keycode == XK_Left || keycode == XK_Right || keycode == XK_Up
		|| keycode == XK_Down || keycode == XK_q || keycode == XK_Q
		|| keycode == XK_e || keycode == XK_E);
}

static int	resize_diameter(t_objects *object, int keycode)
{
	double	*diameter;

	if (object->type == 1)
		diameter = &((t_sphere *)object->obj)->diameter;
	else if (object->type == 2)
		diameter = &((t_cylinder *)object->obj)->diameter;
	else
		return (0);
	if (keycode == XK_t)
		*diameter += SIZE_STEP;
	else if (*diameter > MIN_OBJECT_SIZE)
		*diameter -= SIZE_STEP;
	if (*diameter < MIN_OBJECT_SIZE)
		*diameter = MIN_OBJECT_SIZE;
	printf("%s diameter: %.2f\n",
		object->type == 1 ? "Sphere" : "Cylinder", *diameter);
	return (1);
}

static int	resize_height(t_objects *object, int keycode)
{
	t_cylinder	*cylinder;

	if (object->type != 2)
		return (0);
	cylinder = (t_cylinder *)object->obj;
	if (keycode == XK_y)
		cylinder->height += SIZE_STEP;
	else if (cylinder->height > MIN_OBJECT_SIZE)
		cylinder->height -= SIZE_STEP;
	if (cylinder->height < MIN_OBJECT_SIZE)
		cylinder->height = MIN_OBJECT_SIZE;
	printf("Cylinder height: %.2f\n", cylinder->height);
	return (1);
}

static int	resize_object(t_objects *object, int keycode)
{
	if (!object || !object->obj)
		return (0);
	if (keycode == XK_t || keycode == XK_g)
		return (resize_diameter(object, keycode));
	if (keycode == XK_y || keycode == XK_h)
		return (resize_height(object, keycode));
	return (0);
}
