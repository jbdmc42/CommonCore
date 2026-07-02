/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:00:00 by copilot           #+#    #+#             */
/*   Updated: 2026/06/02 17:04:03 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

/* The redirection processing helpers were moved to redir_process.c to
   satisfy Norminette and avoid large files. Their prototypes are in
   minishell.h, so they are referenced here but not redefined. */

int	setup_redirections(t_token **tokens, int *saved_stdin,
			int *saved_stdout, t_shell *shell)
{
	if (!tokens || !*tokens)
		return (0);
	*saved_stdin = dup(STDIN_FILENO);
	*saved_stdout = dup(STDOUT_FILENO);
	if (*saved_stdin < 0 || *saved_stdout < 0)
	{
		perror("dup");
		return (-1);
	}
	return (process_token_redirections(tokens, shell, *saved_stdin,
			*saved_stdout));
}

/* Note: restore_redirections, store_saved_redirections and cleanup_redirections
   were moved to redir_utils.c. */
