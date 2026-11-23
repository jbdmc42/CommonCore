#include "minirt.h"

void	skip_newline(char *line, int *i) {
	while (line[*i] &&
		(line[*i] == '\n' || line[*i] == '\t' || line[*i] == ' '))
		(*i)++;
}

static int	parse_line(t_data *data, char *line)
{
	int	i;

	if (!line)
		return (E);
	i = 0;
	while (line[i] && (line[i] == '\n' || line[i] == '\r'
			|| line[i] == '\t' || line[i] == ' '))
		i++;
	if (!line[i])
		return (S);
	if (line[0] == 'A')
		return (extract_ambient(data, line));
	else if (line[0] == 'C')
		return (extract_camera(data, line));
	else if (line[0] == 'L')
		return (extract_light(data, line));
	else if (line[0] == 'p' && line[1] == 'l')
		return (extract_plane(data, line));
	else if (line[0] == 's' && line[1] == 'p')
		return (extract_sphere(data, line));
	else if (line[0] == 'c' && line[1] == 'y')
		return (extract_cylinder(data, line));
	return (E);
}

static int	get_objects(t_data *data, const char *scene)
{
	char	*line;
	int		fd;

	fd = open(scene, O_RDONLY);
	if (fd < 0)
		return (printf("Error: couldn't open fd [%s].", scene), E);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == 's' && line[1] == 'p')
			data->scene.obj_count++;
		else if (line[0] == 'p' && line[1] == 'l')
			data->scene.obj_count++;
		else if (line[0] == 'c' && line[1] == 'y')
			data->scene.obj_count++;
		free(line);
		line = get_next_line(fd);
	}
	if (data->scene.obj_count == 0)
		return (close(fd), S);
	data->scene.objs = malloc(sizeof(t_objects) * data->scene.obj_count);
	if (!data->scene.objs)
		return (close(fd), printf("Error: couldn't create object array."), E);
	ft_memset(data->scene.objs, 0, sizeof(t_objects) * data->scene.obj_count);
	return (close(fd), S);
}

static void	check_elements(int *a, int *c, int *l, const char *line)
{
	if (line[0] == 'A' && (line[1] == ' ' || line[1] == '\t'))
		(*a)--;
	else if (line[0] == 'C' && (line[1] == ' ' || line[1] == '\t'))
		(*c)--;
	else if (line[0] == 'L' && (line[1] == ' ' || line[1] == '\t'))
		(*l)--;
}

static int	check_scene(const char *scene)
{
	char	*line;
	int		fd;
	int		a;
	int		c;
	int		l;

	a = E;
	c = E;
	l = E;
	fd = open(scene, O_RDONLY);
	if (fd < 0)
		return (printf("Error: couldn't open fd [%s].", scene), E);
	line = get_next_line(fd);
	while (line)
	{
		check_elements(&a, &c, &l, line);
		free(line);
		line = get_next_line(fd);
	}
	if (a != S || c != S || l != S)
	{
		printf("Error: scene is missing or has too many AMBIENT LIGHT (A), ");
		return (printf("CAMERA (C) or LIGHT (L) declarations."), close(fd), E);
	}
	return (close(fd), S);
}

int	parse_scene(t_data *data, const char *scene)
{
	int		fd;
	char	*line;
	int		err;

	if (check_scene(scene))
		return (E);
	err = get_objects(data, scene);
	if (err == E)
		return (E);
	fd = open(scene, O_RDONLY);
	if (fd < 0)
		return (printf("Error: file not found."), E);
	line = get_next_line(fd);
	while (line)
	{
		err = parse_line(data, line);
		if (err == E)
			return (free(line), close(fd),
				printf("Error: couldn't retrieve line from file."), E);
		else if (err == U)
			return (free(line), close(fd), printf("Error: malloc error."), E);
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), S);
}
