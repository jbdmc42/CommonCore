/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 19:12:26 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/13 10:34:56 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_server	g_server;

void	check_client(pid_t client_pid)
{
	if (g_server.client_pid != 0 && g_server.client_pid != client_pid)
	{
		g_server.c = 0;
		g_server.bit = 0;
		g_server.client_pid = client_pid;
	}
	else if (g_server.client_pid == 0)
		g_server.client_pid = client_pid;
}

int	init_server(t_server *server)
{
	server->c = 0;
	server->bit = 0;
	server->client_pid = 0;
	return (getpid());
}

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static char	buffer[1024];
	static int	buffer_index;

	(void)context;
	check_client(info->si_pid);
	g_server.c = (g_server.c << 1) | (sig == SIGUSR2);
	g_server.bit++;
	kill(g_server.client_pid, SIGUSR2);
	if (g_server.bit == 8)
	{
		if (g_server.c == '\0')
		{
			buffer[buffer_index] = '\0';
			ft_printf("%s\n", buffer);
			kill(g_server.client_pid, SIGUSR1);
			buffer_index = 0;
		}
		else if (buffer_index < 1023)
			buffer[buffer_index++] = g_server.c;
		reset_server(&g_server);
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	ft_printf("Awaiting client messages...\n");
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
