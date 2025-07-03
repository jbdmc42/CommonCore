/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:28:17 by jbdmc             #+#    #+#             */
/*   Updated: 2025/07/03 23:47:32 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(int fd)
{
	int		count;
	char	*line;

	count = 0;
	line = so_long_gnl(fd);
	while (line)
	{
		count++;
		free(line);
		line = so_long_gnl(fd);
	}
	close(fd);
	return (count);
}

char	**read_map(const char *filepath)
{
	int		fd;
	int		i;
	int		lines;
	char	**map;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines = count_lines(fd);
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	i = 0;
	map[i] = so_long_gnl(fd);
	while (map[i])
	{
		i++;
		map[i] = so_long_gnl(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
