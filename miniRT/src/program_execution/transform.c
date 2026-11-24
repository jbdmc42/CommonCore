#include "minirt.h"

static void	translate_object(t_objects *object, t_vector translation)
{
	if (!object || !object->obj)
		return ;
	if (object->type == 0)
		((t_plane *)object->obj)->point = vector_add(
				((t_plane *)object->obj)->point, translation);
	else if (object->type == 1)
		((t_sphere *)object->obj)->center = vector_add(
				((t_sphere *)object->obj)->center, translation);
	else if (object->type == 2)
		((t_cylinder *)object->obj)->center = vector_add(
				((t_cylinder *)object->obj)->center, translation);
}

static int	rotate_object(t_objects *object, int keycode)
{
	if (!object || !object->obj)
		return (0);
	if (object->type == 0)
	{
		((t_plane *)object->obj)->normal = rotate_vector(
				((t_plane *)object->obj)->normal, keycode);
		return (1);
	}
	else if (object->type == 2)
	{
		((t_cylinder *)object->obj)->normal = rotate_vector(
				((t_cylinder *)object->obj)->normal, keycode);
		return (1);
	}
	return (0);
}

static int	select_object(t_data *data, int keycode)
{
	int	direction;
	int	attempts;
	int	object_index;

	if (data->scene.obj_count <= 0)
	{
		printf("No objects to select.\n");
		return (0);
	}
	if (keycode >= XK_1 && keycode <= XK_9)
	{
		object_index = keycode - XK_1;
		if (object_index >= data->scene.obj_count)
		{
			printf("Object %d does not exist.\n", object_index + 1);
			return (0);
		}
		if (!data->scene.objs || !data->scene.objs[object_index].obj)
		{
			printf("Object %d is not available.\n", object_index + 1);
			return (0);
		}
		data->selected_object = object_index;
		printf("Selected object %d (type %d)\n", object_index + 1,
			data->scene.objs[object_index].type);
		return (1);
	}
	if (keycode == XK_bracketleft || keycode == XK_braceleft
		|| keycode == XK_comma || keycode == XK_minus
		|| keycode == XK_KP_Subtract)
		direction = -1;
	else
		direction = 1;
	attempts = 0;
	while (attempts < data->scene.obj_count)
	{
		data->selected_object = (data->selected_object + direction
				+ data->scene.obj_count) % data->scene.obj_count;
		if (data->scene.objs && data->scene.objs[data->selected_object].obj)
		{
			printf("Selected object %d (type %d)\n",
				data->selected_object + 1,
				data->scene.objs[data->selected_object].type);
			return (1);
		}
		attempts++;
	}
	printf("No valid objects to select.\n");
	return (0);
}

static int	is_object_selection_key(int keycode)
{
	return (keycode == XK_bracketleft || keycode == XK_bracketright
		|| keycode == XK_braceleft || keycode == XK_braceright
		|| keycode == XK_comma || keycode == XK_period
		|| keycode == XK_minus || keycode == XK_equal
		|| keycode == XK_KP_Subtract || keycode == XK_KP_Add
		|| (keycode >= XK_1 && keycode <= XK_9));
}

int	apply_transform_key(t_data *data, int keycode)
{
	t_vector	translation;

	if (!data)
		return (0);
	if (keycode == XK_Tab)
	{
		data->transform_target = (data->transform_target + 1) % 3;
		if (data->transform_target == TRANSFORM_CAMERA)
			printf("Transform target: camera\n");
		else if (data->transform_target == TRANSFORM_LIGHT)
			printf("Transform target: light\n");
		else
			printf("Transform target: object %d\n", data->selected_object);
		return (0);
	}
	if (data->transform_target == TRANSFORM_OBJECT
		&& is_object_selection_key(keycode))
		return (select_object(data, keycode));
	if (data->transform_target == TRANSFORM_OBJECT
		&& data->selected_object >= 0
		&& data->selected_object < data->scene.obj_count
		&& (keycode == XK_t || keycode == XK_g
			|| keycode == XK_y || keycode == XK_h))
		return (resize_object(&data->scene.objs[data->selected_object],
				keycode));
	if (is_translation_key(keycode))
	{
		translation = translation_for_key(keycode);
		if (data->transform_target == TRANSFORM_CAMERA)
			data->scene.camera.position = vector_add(
					data->scene.camera.position, translation);
		else if (data->transform_target == TRANSFORM_LIGHT)
			data->scene.light.position = vector_add(
					data->scene.light.position, translation);
		else if (data->selected_object >= 0
			&& data->selected_object < data->scene.obj_count)
			translate_object(&data->scene.objs[data->selected_object],
				translation);
		return (1);
	}
	if (is_rotation_key(keycode))
	{
		if (data->transform_target == TRANSFORM_CAMERA)
			data->scene.camera.orientation = rotate_vector(
					data->scene.camera.orientation, keycode);
		else if (data->transform_target == TRANSFORM_OBJECT
			&& data->selected_object >= 0
			&& data->selected_object < data->scene.obj_count)
			return (rotate_object(&data->scene.objs[data->selected_object],
					keycode));
		else
			return (0);
		return (1);
	}
	return (0);
}
