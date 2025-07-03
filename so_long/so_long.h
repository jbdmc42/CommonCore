/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:27:59 by jbdmc             #+#    #+#             */
/*   Updated: 2025/07/03 23:48:52 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// PRE-PROCESSOR
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "ft_printf.h"

# define WIDTH 640
# define HEIGHT 480
# define KEY_ESC 65307

// STRUCTS
typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_game;

// FUNCTIONS
int		handle_key(int keycode, void *mlx);
int		handle_close(void *mlx);
void	put_image(t_game *game, char *path, int x, int y);
char	*so_long_gnl(int fd);

#endif
