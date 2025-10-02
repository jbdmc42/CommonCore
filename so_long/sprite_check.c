/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:29:12 by jbdmc             #+#    #+#             */
/*   Updated: 2025/09/30 11:19:33 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_player_frames(t_game *game)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		if (!game->player.idle[j])
		{
			ft_printf("Error\n \xE2\x88\x9F player idle ");
			ft_printf("frame %i is NULL\n", j);
			free_all_and_exit(game);
		}
		if (!game->player.move1[j])
		{
			ft_printf("Error\n \xE2\x88\x9F player first ");
			ft_printf("movement frame %i is NULL\n", j);
			free_all_and_exit(game);
		}
		if (!game->player.move2[j])
		{
			ft_printf("Error\n \xE2\x88\x9F player second ");
			ft_printf("movement frame %i is NULL\n", j);
			free_all_and_exit(game);
		}
		j++;
	}
}

void	check_enemies_frames(t_game *game, int flag)
{
	int	j;

	j = 0;
	if (flag == 1)
	{
		while (j < 3)
		{
			if (!game->enemies.frames[j])
			{
				ft_printf("Error\n \xE2\x88\x9F enemy frame %i is NULL\n", j);
				free_all_and_exit(game);
			}
			j++;
		}
		return ;
	}
	while (j < 4)
	{
		if (!game->player.idle[j])
		{
			ft_printf("Error\n \xE2\x88\x9F player idle frame %i is NULL\n", j);
			free_all_and_exit(game);
		}
		j++;
	}
}

void	check_exit_frames(t_game *game)
{
	int	j;

	j = 0;
	while (j < 11)
	{
		if (!game->exit.frames[j])
		{
			ft_printf("Error\n \xE2\x88\x9F exit frame %i is NULL\n", j);
			free_all_and_exit(game);
		}
		j++;
	}
}

void	check_collectible_frames(t_game *game)
{
	int	j;

	j = 0;
	while (j < 9)
	{
		if (!game->collectible.frames[j])
		{
			ft_printf("Error\n \xE2\x88\x9F collectible ");
			ft_printf("frame %i is NULL\n", j);
			free_all_and_exit(game);
		}
		j++;
	}
}
