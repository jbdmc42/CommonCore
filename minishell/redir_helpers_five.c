/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_helpers_five.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:34:53 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:25:22 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_heredoc_child_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
}

int	create_tmp_heredoc_fd(void)
{
	char	template[30];
	int		tmp_fd;

	ft_strlcpy(template, "/tmp/minishell_heredoc_XXXXXX", sizeof(template));
	tmp_fd = ft_mkstemp(template);
	if (tmp_fd == -1)
		return (-1);
	return (tmp_fd);
}

void	run_heredoc_child(int tmp_fd, char *delimiter,
			int should_expand, t_shell *shell)
{
	set_heredoc_child_signals();
	heredoc_loop(tmp_fd, delimiter, should_expand, shell);
	close(tmp_fd);
	_exit(0);
}

int	finalize_heredoc_parent(int status, int tmp_fd, t_shell *shell)
{
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		if (shell)
			shell->exit_status = 130;
		write(STDOUT_FILENO, "\n", 1);
		close(tmp_fd);
		return (-1);
	}
	if (ft_lseek(tmp_fd, 0, SEEK_SET) == -1)
	{
		return (-1);
	}
	return (tmp_fd);
}
