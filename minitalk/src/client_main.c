/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 19:13:49 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/06 08:22:41 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(pid_t server_pid, unsigned char c)
{
	int	bit;
	int	status;

	bit = 8;
	while (bit--)
	{
		if ((c >> bit) & 1)
			status = kill(server_pid, SIGUSR2);		// envia SIGUSR2 para o servidor
		else
			status = kill(server_pid, SIGUSR1);		// envia SIGUSR1 para o servidor
		if (status == -1)
		{
			ft_printf("Failed to send signal to server PID %d\n", server_pid);
			exit(EXIT_FAILURE);
		}
		usleep(150);
	}
}

void	send_string(pid_t server_pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(server_pid, str[i]);
		i++;
	}
	send_char(server_pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}
	server_pid = (pid_t)ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_printf("Invalid server PID: %s\n", argv[1]);
		return (1);
	}
	send_string(server_pid, argv[2]);
	return (0);
}