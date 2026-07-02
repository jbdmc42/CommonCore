/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:18:09 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:08:37 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_external_command(t_token *tokens, t_shell *shell)
{
	char	**argv;
	char	**envp;

	argv = build_argv(tokens);
	if (!argv)
		return ;
	envp = build_envp(shell);
	if (!envp)
	{
		free(argv);
		return ;
	}
	if (search_and_execute(tokens->value, argv, envp, shell) == -1)
	{
		printf("%s: command not found\n", tokens->value);
		shell->exit_status = 127;
	}
	free(argv);
	free_envp_array(envp);
}

static void	finalize_processing(t_token *tokens, t_shell *shell,
	int saved_stdin, int saved_stdout)
{
	free_tokens(tokens);
	restore_redirections(saved_stdin, saved_stdout);
	shell->saved_stdin = -1;
	shell->saved_stdout = -1;
	shell->redirs_saved = 0;
}

static int	setup_and_store(t_token **tokens, t_shell *shell,
	int *saved_stdin, int *saved_stdout)
{
	*saved_stdin = -1;
	*saved_stdout = -1;
	if (setup_redirections(tokens, saved_stdin, saved_stdout, shell) == -1)
	{
		if (*saved_stdin >= 0)
			close(*saved_stdin);
		if (*saved_stdout >= 0)
			close(*saved_stdout);
		free_tokens(*tokens);
		shell->saved_stdin = -1;
		shell->saved_stdout = -1;
		shell->redirs_saved = 0;
		return (-1);
	}
	store_saved_redirections(shell, *saved_stdin, *saved_stdout);
	return (0);
}

void	get_commands(t_token *tokens, t_shell *shell)
{
	int		saved_stdin;
	int		saved_stdout;
	t_token	*current;

	if (!tokens->value[0])
		return ;
	current = tokens;
	while (current)
	{
		if (current->type == PIPE)
			return (execute_pipe_chain(tokens, shell), free_tokens(tokens));
		current = current->next;
	}
	if (setup_and_store(&tokens, shell, &saved_stdin, &saved_stdout) == -1)
		return ;
	if (!tokens || !tokens->value)
		return (finalize_processing(tokens, shell, saved_stdin, saved_stdout));
	if (is_builtin_command(tokens->value))
		execute_builtin(tokens, shell);
	else
		handle_external_command(tokens, shell);
	finalize_processing(tokens, shell, saved_stdin, saved_stdout);
}
