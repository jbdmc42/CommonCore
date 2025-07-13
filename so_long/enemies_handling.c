/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:54:12 by jbdmc             #+#    #+#             */
/*   Updated: 2025/07/13 18:01:50 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_for_enemies(t_game *game, char tile)
{
	if (tile == 'X')
	{
		ft_printf("Oh no, you lost! Better luck next time.\n");
		handle_close(game);
		return ;
	}
}