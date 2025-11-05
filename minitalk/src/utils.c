/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:15:45 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/21 18:09:22 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
