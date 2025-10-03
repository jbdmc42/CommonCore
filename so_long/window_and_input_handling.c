/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_and_input_handling.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:52:15 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/03 01:39:40 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Print friendly message and then perform normal close
int	handle_close_user(void *param)
{
	ft_printf("Game closed successfully by player input.\n");
	return (handle_close(param));
}

// Free all resources and exit the program
int	handle_close(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_all_and_exit(game);
	return (0);
}
