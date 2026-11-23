#include "minirt.h"

int	extract_ambient(t_data *data, char *line)
{	
	int	i;

	i = 1;
	data->scene.ambient.ratio = ft_def_atod(line, &i, RATIO);
	data->scene.ambient.color.r = ft_def_atoi(line, &i, RGB);
	data->scene.ambient.color.g = ft_def_atoi(line, &i, RGB);
	data->scene.ambient.color.b = ft_def_atoi(line, &i, RGB);
	return (S);
}

int	extract_camera(t_data *data, char *line)
{
	int	i;

	i = 1;
	data->scene.camera.position.x = ft_def_atod(line, &i, DEF);
	data->scene.camera.position.y = ft_def_atod(line, &i, DEF);
	data->scene.camera.position.z = ft_def_atod(line, &i, DEF);
	data->scene.camera.orientation.x = ft_def_atod(line, &i, ORIENTATION);
	data->scene.camera.orientation.y = ft_def_atod(line, &i, ORIENTATION);
	data->scene.camera.orientation.z = ft_def_atod(line, &i, ORIENTATION);
	data->scene.camera.fov = ft_def_atoi(line, &i, FOV);
	return (S);
}

int	extract_light(t_data *data, char *line)
{
	int	i;

	i = 1;
	data->scene.light.position.x = ft_def_atod(line, &i, DEF);
	data->scene.light.position.y = ft_def_atod(line, &i, DEF);
	data->scene.light.position.z = ft_def_atod(line, &i, DEF);
	data->scene.light.ratio = ft_def_atod(line, &i, RATIO);
	data->scene.light.color.r = ft_def_atoi(line, &i, RGB);
	data->scene.light.color.g = ft_def_atoi(line, &i, RGB);
	data->scene.light.color.b = ft_def_atoi(line, &i, RGB);
	return (S);
}
