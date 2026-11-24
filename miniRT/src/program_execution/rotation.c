#include "minirt.h"

static t_vector	rotate_x(t_vector vector, double angle)
{
	t_vector	result;

	result.x = vector.x;
	result.y = vector.y * cos(angle) - vector.z * sin(angle);
	result.z = vector.y * sin(angle) + vector.z * cos(angle);
	return (result);
}

static t_vector	rotate_y(t_vector vector, double angle)
{
	t_vector	result;

	result.x = vector.x * cos(angle) + vector.z * sin(angle);
	result.y = vector.y;
	result.z = -vector.x * sin(angle) + vector.z * cos(angle);
	return (result);
}

static t_vector	rotate_z(t_vector vector, double angle)
{
	t_vector	result;

	result.x = vector.x * cos(angle) - vector.y * sin(angle);
	result.y = vector.x * sin(angle) + vector.y * cos(angle);
	result.z = vector.z;
	return (result);
}

static t_vector	rotate_vector(t_vector vector, int keycode)
{
	if (keycode == XK_Left)
		vector = rotate_y(vector, ROTATION_STEP);
	else if (keycode == XK_Right)
		vector = rotate_y(vector, -ROTATION_STEP);
	else if (keycode == XK_Up)
		vector = rotate_x(vector, ROTATION_STEP);
	else if (keycode == XK_Down)
		vector = rotate_x(vector, -ROTATION_STEP);
	else if (keycode == XK_q || keycode == XK_Q)
		vector = rotate_z(vector, -ROTATION_STEP);
	else if (keycode == XK_e || keycode == XK_E)
		vector = rotate_z(vector, ROTATION_STEP);
	return (vector_norm(vector));
}

static t_vector	translation_for_key(int keycode)
{
	t_vector	translation;

	translation.x = 0.0;
	translation.y = 0.0;
	translation.z = 0.0;
	if (keycode == XK_a || keycode == XK_A)
		translation.x = TRANSLATION_STEP;
	else if (keycode == XK_d || keycode == XK_D)
		translation.x = -TRANSLATION_STEP;
	else if (keycode == XK_w || keycode == XK_W)
		translation.y = TRANSLATION_STEP;
	else if (keycode == XK_s || keycode == XK_S)
		translation.y = -TRANSLATION_STEP;
	else if (keycode == XK_r || keycode == XK_R)
		translation.z = TRANSLATION_STEP;
	else if (keycode == XK_f || keycode == XK_F)
		translation.z = -TRANSLATION_STEP;
	return (translation);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
}
