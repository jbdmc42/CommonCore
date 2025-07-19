/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_first.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:48:36 by jbdmc             #+#    #+#             */
/*   Updated: 2025/07/19 12:58:30 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_movement_wrapper(t_game *game, char tile, int new_x, int new_y)
{
	check_for_enemies(game, tile);
	update_player_direction(game, new_x, new_y);
	update_animation(game);
	handle_collectible(game, new_x, new_y);
	update_player_position(game, new_x, new_y);
}

void	check_for_enemies(t_game *game, char tile)
{
	if (tile == 'X' || tile == 'Y')
	{
		ft_printf("Oh no, you lost! Better luck next time.\n");
		handle_close(game);
		return ;
	}
}

int	get_enemy_axis(char c)
{
	if (c == 'X')
		return (0);
	if (c == 'Y')
		return (1);
	return (-1);
}

int	check_fd(int fd)
{
	if (fd < 0)
	{
		ft_printf("Error\n \xE2\x88\x9F invalid map path\n");
		return (1);
	}
	return (0);
}

char	*extract_map_name(const char *filepath)
{
	char	*name_start;
	char	*dot;

	name_start = ft_strrchr(filepath, '/');
	if (name_start)
		name_start++;
	else
		name_start = (char *)filepath;
	dot = ft_strrchr(name_start, '.');
	if (dot)
		return (ft_substr(name_start, 0, dot - name_start));
	else
		return (ft_strdup(name_start));
}