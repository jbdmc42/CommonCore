/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:19:24 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 18:11:13 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_signal_received = 0;

size_t	skip_blank_prefix(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	return (i);
}

void	main_loop(t_shell *shell, int interactive)
{
	while (1)
	{
		g_signal_received = 0;
		if (interactive)
			run_interactive_cycle(shell);
		else
			run_noninteractive_cycle(shell);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	int		interactive;

	(void)argc;
	(void)argv;
	shell.exit_status = 0;
	shell.saved_stdin = -1;
	shell.saved_stdout = -1;
	shell.redirs_saved = 0;
	init_env(&shell, envp);
	interactive = isatty(STDIN_FILENO);
	setup_signal_handlers(interactive);
	main_loop(&shell, interactive);
	free_shell_env(&shell);
	return (shell.exit_status);
}
