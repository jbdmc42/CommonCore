/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:15:45 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/21 16:28:44 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	reset_server(t_server *server)
{
	server->c = 0;
	server->bit = 0;
}

void	flush_buffer(char *buffer, int *buffer_index, char c)
{
	buffer[*buffer_index] = '\0';
	ft_printf("%s", buffer);
	*buffer_index = 0;
	buffer[(*buffer_index)++] = c;
}
