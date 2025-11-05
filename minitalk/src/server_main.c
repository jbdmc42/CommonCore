/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 19:12:26 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/23 11:21:03 by joaobarb         ###   ########.fr       */
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

void	process_bit(int sig)
{
	g_server.c = (g_server.c << 1) | (sig == SIGUSR2);
	g_server.bit++;
}

void	process_char(void)
{
	static char	buffer[65536];
	static int	buffer_index = 0;

	if (g_server.c == '\0')
	{
		buffer[buffer_index] = '\0';
		ft_printf("%s\n", buffer);
		kill(g_server.client_pid, SIGUSR1);
		buffer_index = 0;
		g_server.client_pid = 0;
	}
	else if (buffer_index < 65535)
		buffer[buffer_index++] = g_server.c;
	else
		flush_buffer(buffer, &buffer_index, g_server.c);
	reset_server(&g_server);
}

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	check_client(info->si_pid);
	process_bit(sig);
	if (g_server.bit == 8)
		process_char();
	if (g_server.client_pid != 0)
		kill(g_server.client_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	g_server.c = 0;
	g_server.bit = 0;
	g_server.client_pid = 0;
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
