/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:14:45 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/08 14:42:20 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Build "Player Position [x , y]" string
char	*prepare_player_position_str(t_game *game)
{
	char	*x_str;
	char	*y_str;
	char	*pos_str;
	char	*final_str;

	x_str = ft_itoa(game->player_x);
	y_str = ft_itoa(game->player_y);
	pos_str = ft_strjoin("Player Position [", x_str);
	final_str = ft_strjoin(pos_str, " , ");
	free(pos_str);
	pos_str = ft_strjoin(final_str, y_str);
	free(final_str);
	final_str = ft_strjoin(pos_str, "]");
	free(pos_str);
	free(x_str);
	free(y_str);
	return (final_str);
}

// Draw current level and player position on screen
void	render_hud_level_player_pos(t_game *game)
{
	char	*pos_str;

	pos_str = prepare_player_position_str(game);
	mlx_string_put(game->mlx, game->win, 10, 20, 0x00FF00, pos_str);
	free(pos_str);
}

// Build "Collectibles: current/total" string
static char	*get_collectibles_str(t_game *game)
{
	char	*collected;
	char	*total;
	char	*tmp;
	char	*collect_str;
	int		r;

	r = game->elements.e_total_collectibles - game->elements.e_collectible;
	collected = ft_itoa(r);
	total = ft_itoa(game->elements.e_total_collectibles);
	tmp = ft_strjoin(collected, "/");
	free(collected);
	collect_str = ft_strjoin(tmp, total);
	free(tmp);
	free(total);
	return (collect_str);
}

// Build final "Collectibles: x/y" string
char	*prepare_collect_str(t_game *game)
{
	char	*tmp;
	char	*collect_str;

	collect_str = get_collectibles_str(game);
	tmp = ft_strjoin("Collectibles: ", collect_str);
	free(collect_str);
	return (tmp);
}

// Draw collectibles and move counter on screen
void	render_hud_moves_and_collectibles(t_game *game)
{
	char	*str;

	str = prepare_collect_str(game);
	mlx_string_put(game->mlx, game->win, 180, 20, 0x00FF00, str);
	free(str);
	str = prepare_moves_str(game);
	mlx_string_put(game->mlx, game->win, 315, 20, 0x00FF00, str);
	free(str);
}
