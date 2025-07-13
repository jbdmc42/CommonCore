/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:47:17 by jbdmc             #+#    #+#             */
/*   Updated: 2025/07/13 16:57:43 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	create_map_copies(t_game *game, char ***copy, char ***backup)
{
	*copy = copy_map(game->map);
	*backup = copy_map(game->map);
	if (!*copy || !*backup)
	{
		free_map(*copy);
		free_map(*backup);
		ft_printf("Error\n \xE2\x88\x9F failed to copy map\n");
		return (0);
	}
	return (1);
}

int	is_map_rectangular(char **map)
{
	size_t	width;
	int	    height;

	if (!map || !map[0])
		return (0);
	width = ft_strlen(map[0]);
	height = 0;
	while (map[height])
        height++;
	if (width >= (size_t)height)
		return (1);
	return (0);
}

int	is_map_surrounded(char **map)
{
	int	i;
	int	j;
	int	width = ft_strlen(map[0]);
	int	height = 0;

	while (map[height])
		height++;
	i = 0;
	while (i < height)
	{
		if (i == 0 || i == height - 1)
		{
			j = 0;
			while (j < width)
				if (map[i][j++] != '1')
					return (0);
		}
		else
		{
			if (map[i][0] != '1' || map[i][width - 1] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

int	validate_map_basic(char **map)
{
	if (!is_map_rectangular(map))
	{
		ft_printf("Error\n \xE2\x88\x9F map is not rectangular\n");
		return (0);
	}
	if (!is_map_surrounded(map))
	{
		ft_printf("Error\n \xE2\x88\x9F map is not surrounded by walls\n");
		return (0);
	}
	return (1);
}

int	validate_map(t_game *game)
{
	char	**map_copy;
	char	**map_backup;

	if (has_invalid_chars(game->map))
		return (0);
	if (!validate_map_basic(game->map))
		return (0);
	if (!create_map_copies(game, &map_copy, &map_backup))
		return (0);
	game->original_map = map_backup;
	flood_fill(map_copy, game->player_x, game->player_y);
	if (!have_all_targets_been_reached(map_copy))
	{
		ft_printf("Error\n \xE2\x88\x9F not all targets are reachable\n");
		free_map(map_copy);
		free_map(game->original_map);
		game->original_map = NULL;
		return (0);
	}
	free_map(map_copy);
	return (1);
}
