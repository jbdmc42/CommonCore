/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 19:12:26 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/06 08:21:10 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_server	g_server;

int	init_server(t_server *server)
{
	server->c = 0;
	server->bit = 0;
	server->client_pid = 0;
	return (getpid());
}

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;

	if (g_server.client_pid != info->si_pid)		// se o sinal vem de um cliente diferente, reinicia o estado do servidor
	{
		g_server.c = 0;
		g_server.bit = 0;
		g_server.client_pid = info->si_pid;
	}
	g_server.c <<= 1;								// shift do bit para a esquerda --> 010 fica 0100 para receber o próximo bit
	if (sig == SIGUSR2)								// se o sinal for SIGUSR2, o bit recebido é 1
		g_server.c |= 1;
	g_server.bit++;
	if (g_server.bit == 8)							// se já recebeu 8 bits, ou seja, um byte completo
	{
		if (g_server.c == '\0')						// se o caractere recebido for nulo, finaliza a mensagem
		{
			write(STDOUT_FILENO, "\n", 1);
			g_server.client_pid = 0;				// reseta o client_pid para aceitar novas conexões
		}
		else
			write(STDOUT_FILENO, &g_server.c, 1);			// imprime o caractere recebido
		g_server.c = 0;								// resetar para receber o próximo caractere
		g_server.bit = 0;
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