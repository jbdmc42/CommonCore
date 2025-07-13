/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:48:17 by jbdmc             #+#    #+#             */
/*   Updated: 2025/07/13 12:12:48 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	count_map_elements(char **map, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				game->elements.e_player++;
			else if (map[y][x] == 'E')
				game->elements.e_exit++;
			else if (map[y][x] == 'C')
				game->elements.e_collectible++;
			x++;
		}
		y++;
	}
}

int	is_map_elements_valid(char **map, t_game *game)
{
	game->elements.e_player = 0;
	game->elements.e_exit = 0;
    game->elements.e_collectible = 0;
	count_map_elements(map, game);
	if (game->elements.e_player != 1 || game->elements.e_exit != 1 
        || game->elements.e_collectible < 1)
	{
        ft_printf("Error\n \xE2\x88\x9F at least one game element ");
        ft_printf("is missing or has too many instances from those bellow:\n");
        ft_printf("   \xE2\x88\x9F collectibles\n   \xE2\x88\x9F exit\n");
        ft_printf("   \xE2\x88\x9F player\n");
        return (0);
    }
	return (1);
}
