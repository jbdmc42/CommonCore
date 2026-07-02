/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_helpers_four.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:13:16 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:03:51 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

void	set_heredoc_parent_signals(struct sigaction *old_int,
			struct sigaction *old_quit)
{
	struct sigaction	ignore;

	sigemptyset(&ignore.sa_mask);
	ignore.sa_flags = 0;
	ignore.sa_handler = SIG_IGN;
	sigaction(SIGINT, &ignore, old_int);
	sigaction(SIGQUIT, &ignore, old_quit);
}

void	restore_heredoc_parent_signals(struct sigaction *old_int,
			struct sigaction *old_quit)
{
	sigaction(SIGINT, old_int, NULL);
	sigaction(SIGQUIT, old_quit, NULL);
}

int	wait_heredoc_child(pid_t pid, int *status)
{
	while (1)
	{
		if (waitpid(pid, status, 0) != -1)
			return (0);
		if (errno != EINTR)
			return (-1);
	}
}

int	perform_dup2_and_close(int fd, int target_fd, t_shell *shell)
{
	if (dup2(fd, target_fd) < 0)
	{
		close(fd);
		perror("dup2");
		shell->exit_status = 1;
		return (-1);
	}
	close(fd);
	return (0);
}

void	unlink_token_node(t_token **tokens, t_token *node, t_token *next)
{
	t_token	*iter;

	if (!tokens || !*tokens)
		return ;
	iter = *tokens;
	if (iter == node)
	{
		*tokens = next;
		return ;
	}
	while (iter && iter->next && iter->next != node)
		iter = iter->next;
	if (iter && iter->next == node)
		iter->next = next;
}
