/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 19:13:49 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/21 16:28:44 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static volatile sig_atomic_t	g_ack = 0;

static void	ack_handler(int sig)
{
	(void)sig;
	g_ack = 1;
}

static void	message_received_handler(int sig)
{
	(void)sig;
	ft_printf("\nMessage received by the server!\n");
}

void	send_char(pid_t server_pid, unsigned char c)
{
	int	bit;
	int	status;

	bit = 8;
	while (bit--)
	{
		g_ack = 0;
		if ((c >> bit) & 1)
			status = kill(server_pid, SIGUSR2);
		else
			status = kill(server_pid, SIGUSR1);
		if (status == -1)
		{
			ft_printf("Failed to send signal to server PID %d\n", server_pid);
			exit(EXIT_FAILURE);
		}
		while (!g_ack)
			pause();
	}
}

void	send_string(pid_t server_pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(server_pid, (unsigned char)str[i]);
		i++;
	}
	send_char(server_pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	struct sigaction	sa;

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
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = ack_handler;
	sigaction(SIGUSR2, &sa, NULL);
	sa.sa_handler = message_received_handler;
	sigaction(SIGUSR1, &sa, NULL);
	send_string(server_pid, argv[2]);
	return (0);
}
