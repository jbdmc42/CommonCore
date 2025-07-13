/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_game_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:40:54 by jbdmc             #+#    #+#             */
/*   Updated: 2025/07/13 11:43:57 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_valid_file_extension(const char *filename)
{
    int len;

    if (!filename)
        return (0);
    len = ft_strlen(filename);
    if (len < 5)
        return (0);
    return (ft_strncmp(filename + len - 4, ".ber", 4) == 0);
}

int	has_invalid_chars(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '0' && map[y][x] != '1' &&
				map[y][x] != 'P' && map[y][x] != 'E' &&
				map[y][x] != 'C' && map[y][x] != 'X')
			{
				ft_printf("Error\n \xE2\x88\x9F");
				ft_printf(" map has invalid characters: '%c'\n", map[y][x]);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
