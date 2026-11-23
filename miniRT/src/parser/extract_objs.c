#include "minirt.h"

int	extract_plane(t_data *data, char *line)
{
	int		i;
	int		j;
	t_plane	*plane;

	i = 2;
	j = 0;
	while (j < data->scene.obj_count && data->scene.objs[j].obj)
		j++;
	if (j >= data->scene.obj_count)
		return (E);
	data->scene.objs[j].obj = malloc(sizeof(t_plane));
	if (!data->scene.objs[j].obj)
		return (U);
	plane = (t_plane *)data->scene.objs[j].obj;
	plane->point.x = ft_def_atod(line, &i, DEF);
	plane->point.y = ft_def_atod(line, &i, DEF);
	plane->point.z = ft_def_atod(line, &i, DEF);
	plane->normal.x = ft_def_atod(line, &i, ORIENTATION);
	plane->normal.y = ft_def_atod(line, &i, ORIENTATION);
	plane->normal.z = ft_def_atod(line, &i, ORIENTATION);
	plane->color.r = ft_def_atoi(line, &i, RGB);
	plane->color.g = ft_def_atoi(line, &i, RGB);
	plane->color.b = ft_def_atoi(line, &i, RGB);
	data->scene.objs[j].type = 0;
	return (S);
}

int	extract_sphere(t_data *data, char *line)
{
	int			i;
	int			j;
	t_sphere	*sphere;

	i = 2;
	j = 0;
	while (j < data->scene.obj_count && data->scene.objs[j].obj)
		j++;
	if (j >= data->scene.obj_count)
		return (E);
	data->scene.objs[j].obj = malloc(sizeof(t_sphere));
	if (!data->scene.objs[j].obj)
		return (U);
	sphere = (t_sphere *)data->scene.objs[j].obj;
	sphere->center.x = ft_def_atod(line, &i, DEF);
	sphere->center.y = ft_def_atod(line, &i, DEF);
	sphere->center.z = ft_def_atod(line, &i, DEF);
	sphere->diameter = ft_def_atod(line, &i, DEF);
	sphere->color.r = ft_def_atoi(line, &i, RGB);
	sphere->color.g = ft_def_atoi(line, &i, RGB);
	sphere->color.b = ft_def_atoi(line, &i, RGB);
	data->scene.objs[j].type = 1;
	return (S);
}

static void	cy_extractor_helper(t_cylinder *cylinder, char *line, int *i)
{
	cylinder->center.x = ft_def_atod(line, i, DEF);
	cylinder->center.y = ft_def_atod(line, i, DEF);
	cylinder->center.z = ft_def_atod(line, i, DEF);
	cylinder->normal.x = ft_def_atod(line, i, ORIENTATION);
	cylinder->normal.y = ft_def_atod(line, i, ORIENTATION);
	cylinder->normal.z = ft_def_atod(line, i, ORIENTATION);
	cylinder->diameter = ft_def_atod(line, i, DEF);
	cylinder->height = ft_def_atod(line, i, DEF);
	cylinder->color.r = ft_def_atoi(line, i, RGB);
	cylinder->color.g = ft_def_atoi(line, i, RGB);
	cylinder->color.b = ft_def_atoi(line, i, RGB);
}

int	extract_cylinder(t_data *data, char *line)
{
	int			i;
	int			j;
	t_cylinder	*cylinder;

	i = 2;
	j = 0;
	while (j < data->scene.obj_count && data->scene.objs[j].obj)
		j++;
	if (j >= data->scene.obj_count)
		return (E);
	data->scene.objs[j].obj = malloc(sizeof(t_cylinder));
	if (!data->scene.objs[j].obj)
		return (U);
	cylinder = (t_cylinder *)data->scene.objs[j].obj;
	cy_extractor_helper(cylinder, line, &i);
	data->scene.objs[j].type = 2;
	return (S);
}
