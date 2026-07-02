/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_extra_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:45:00 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:08:37 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <limits.h>
#include <errno.h>

void	finalize_processing(t_token *tokens, t_shell *shell,
	int saved_stdin, int saved_stdout)
{
	free_tokens(tokens);
	restore_redirections(saved_stdin, saved_stdout);
	shell->saved_stdin = -1;
	shell->saved_stdout = -1;
	shell->redirs_saved = 0;
}

int	setup_and_store(t_token **tokens, t_shell *shell,
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
