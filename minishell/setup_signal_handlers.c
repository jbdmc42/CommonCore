/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_signal_handlers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:27:38 by jbdmc             #+#    #+#             */
/*   Updated: 2025/12/07 10:43:40 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/*
** [SIGINT Handler / Ctrl + C Handler] 
** as we don't want our process to close,
** the handler will only interrupt the
** current line, create a new one, and
** redisplay the prompt.
*/

// custom signal handler function
void	sigint_handler(int sig)
{
	(void)sig;

	write(STDOUT_FILENO, "\n", 1);		// writes down a new line so as to don't mix it with the prompt
	rl_on_new_line();					// tells readline that we want to start a new line
	rl_replace_line("", 0);				// clears the current input from the user
	rl_redisplay();						// redisplays the prompt
	g_global.exit_status = 130;			// defines the exit code (130 is usually used for SIGINT)
}

// signal handler configuration function
void	setup_signal_handlers(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);			// clear the mask (define the signal handler as nothing)
	sa.sa_flags = SA_RESTART;			// restarts interrupted syscalls asap
	sa.sa_handler = sigint_handler;		// define the signal handler as our signal handling function (sigint_handler)
	sigaction(SIGINT, &sa, NULL);		// define the signal handler trigger
	signal(SIGQUIT, SIG_IGN); 			// ignore SIGQUIT on the prompt (ignoring the SIGQUIT helps making the shell not exit with core dump)
}
