/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 15:10:00 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:08:37 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

void	restore_redirections(int saved_stdin, int saved_stdout)
{
	if (saved_stdin >= 0)
	{
		dup2(saved_stdin, STDIN_FILENO);
		close(saved_stdin);
	}
	if (saved_stdout >= 0)
	{
		dup2(saved_stdout, STDOUT_FILENO);
		close(saved_stdout);
	}
}

void	store_saved_redirections(t_shell *shell, int saved_stdin,
			int saved_stdout)
{
	if (!shell)
		return ;
	shell->saved_stdin = saved_stdin;
	shell->saved_stdout = saved_stdout;
	shell->redirs_saved = 1;
}

void	cleanup_redirections(t_shell *shell)
{
	if (!shell || !shell->redirs_saved)
		return ;
	restore_redirections(shell->saved_stdin, shell->saved_stdout);
	shell->saved_stdin = -1;
	shell->saved_stdout = -1;
	shell->redirs_saved = 0;
}
