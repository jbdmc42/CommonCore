/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 19:13:15 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/16 15:03:55 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _POSIX_C_SOURCE 200809L

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include "ft_printf.h"

typedef struct s_server
{
	unsigned char	c;
	int				bit;
	pid_t			client_pid;
}	t_server;

extern t_server	g_server;

void	reset_server(t_server *server);
void	flush_buffer(char *buffer, int *buffer_index, char c);

#endif