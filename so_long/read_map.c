/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:28:17 by jbdmc             #+#    #+#             */
/*   Updated: 2025/07/18 17:50:40 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	validate_lines(char **map)
{
	int	i;
	int	len;

	if (!map || !map[0])
		return (0);
	len = (int)ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) == 0)
		{
			ft_printf("Error\n \xE2\x88\x9F map has empty lines\n");
			return (0);
		}
		if((int)ft_strlen(map[i]) != len)
		{
			ft_printf("Error\n \xE2\x88\x9F map has distinct size lines\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	count_lines(int fd)
{
	int		count;
	char	*line;

	count = 0;
	line = ft_gnl(fd);
	while (line)
	{
		count++;
		free(line);
		line = ft_gnl(fd);
	}
	close(fd);
	return (count);
}

static char	*clean_line(char *line)
{
	int		len;
	char	*new;
	int		i;

	if (!line)
		return (NULL);
	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = line[i];
		i++;
	}
	new[i] = '\0';
	free(line);
	return (new);
}

static char	**allocate_and_fill_map(int fd, int lines)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	i = 0;
	map[i] = clean_line(ft_gnl(fd));
	while (map[i])
	{
		i++;
		map[i] = clean_line(ft_gnl(fd));
	}
	map[i] = NULL;
	return (map);
}

char	**read_map(const char *filepath)
{
	int		fd;
	int		lines;
	char	**map;

	fd = open(filepath, O_RDONLY);
	if (check_fd(fd))
		return (NULL);
	lines = count_lines(fd);
	fd = open(filepath, O_RDONLY);
	if (check_fd(fd))
		return (NULL);
	map = allocate_and_fill_map(fd, lines);
	if (!map)
	{
		ft_printf("Error\n \xE2\x88\x9F invalid map\n");
		return (NULL);
	}
	if (!validate_lines(map))
		return (NULL);
	return (map);
}
