/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:38:09 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/03 02:30:53 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	if (x > 0)
		flood_fill(map, x - 1, y);
	if (map[y + 1])
		flood_fill(map, x, y + 1);
	if (map[y][x + 1])
		flood_fill(map, x + 1, y);
	if (y > 0)
		flood_fill(map, x, y - 1);
}

int	have_all_targets_been_reached(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	count_map_lines(char **map)
{
	int	count;

	count = 0;
	while (map && map[count])
		count++;
	return (count);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		free(map[i++]);
	free(map);
}

char	**copy_map(char **map)
{
	int		i;
	int		height;
	char	**copy;

	height = count_map_lines(map);
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
			return (free_map(copy), NULL);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
