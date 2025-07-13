/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:28:17 by jbdmc             #+#    #+#             */
/*   Updated: 2025/07/13 12:32:22 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	map[i] = clean_line(ft_gnl(fd));
	while (map[i])
	{
		i++;
		map[i] = clean_line(ft_gnl(fd));
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
