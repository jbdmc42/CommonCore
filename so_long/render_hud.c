/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:14:45 by jbdmc             #+#    #+#             */
/*   Updated: 2025/07/18 17:38:59 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_hud_moves_and_collectibles(t_game *game)
{
	char	*move_num;
	char	*move_str;
	char	*collected_str;
	char	*total_str;
	char	*temp_str;
	char	*collect_str;

	move_num = ft_itoa(game->move_counter);
	move_str = ft_strjoin("Moves: ", move_num);
	mlx_string_put(game->mlx, game->win, 270, 20, 0x00FF00, move_str);
	collected_str = ft_itoa(game->elements.e_total_collectibles - game->elements.e_collectible);
	total_str = ft_itoa(game->elements.e_total_collectibles);
	temp_str = ft_strjoin(collected_str, "/");
	collect_str = ft_strjoin("Collectibles: ",
		ft_strjoin(temp_str, total_str));
	mlx_string_put(game->mlx, game->win, 350, 20, 0x00FF00, collect_str);
	free(move_num);
	free(move_str);
	free(collected_str);
	free(total_str);
	free(temp_str);
	free(collect_str);
}

void	render_hud_level_player_pos(t_game *game)
{
	char	*lvl_str;
	char	*pos_str;
	
	lvl_str = ft_strdup("Level [");
	lvl_str = ft_strjoin(lvl_str, game->map_name);
	lvl_str = ft_strjoin(lvl_str, "]");
	mlx_string_put(game->mlx, game->win, 10, 20, 0x00FF00, lvl_str);
	pos_str = ft_strdup("Player Position [");
	pos_str = ft_strjoin(pos_str, ft_itoa(game->player_x));
	pos_str = ft_strjoin(pos_str, " , ");
	pos_str = ft_strjoin(pos_str, ft_itoa(game->player_y));
	pos_str = ft_strjoin(pos_str, "]");
	mlx_string_put(game->mlx, game->win, 100, 20, 0x00FF00, pos_str);
	free(lvl_str);
	free(pos_str);
}
