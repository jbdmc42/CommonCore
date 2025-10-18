/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_game_checks_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:40:54 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/16 14:39:59 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Helper: validate that base name contains only allowed characters
static int	is_valid_basename(const char *name_start, const char *dot)
{
	const char	*p;

	p = name_start;
	while (p < dot)
	{
		if (!ft_isalnum((int)*p) && *p != '_' && *p != '-' && *p != '.')
		{
			ft_printf("Error\n \xE2\x88\x9F invalid character in map name:");
			ft_printf(" '%c'\n", *p);
			return (0);
		}
		p++;
	}
	return (1);
}

// Validate that filepath ends with ".ber", that the base name is not empty
// (so ".ber" is rejected) and that the base name contains
// only allowed characters (alnum, '_', '-', '.')
int	is_valid_file_extension(const char *filename)
{
	const char	*name_start;
	const char	*dot;

	if (!filename)
		return (0);
	name_start = ft_strrchr(filename, '/');
	if (name_start)
		name_start++;
	else
		name_start = filename;
	dot = ft_strrchr(name_start, '.');
	if (!dot)
		return (0);
	if (ft_strncmp(dot, ".ber", 4) != 0 || dot[4] != '\0')
		return (0);
	if (dot == name_start)
		return (0);
	return (is_valid_basename(name_start, dot));
}

// Ensure map contains only allowed characters (0,1,P,E,C,X,Y)
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
				map[y][x] != 'C' && map[y][x] != 'X' &&
				map[y][x] != 'Y')
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
