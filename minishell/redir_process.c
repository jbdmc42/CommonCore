/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 15:40:00 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:08:37 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>

int	should_expand_heredoc(const char *delimiter)
{
	if (!delimiter || !*delimiter)
		return (1);
	if (*delimiter == '\x01')
		return (0);
	return (1);
}

void	cleanup_dless_nodes(t_token **tokens, t_token *redir,
	t_token *target)
{
	t_token	*next;

	next = target->next;
	unlink_token_node(tokens, redir, next);
	free(target->value);
	free(target);
	free(redir->value);
	free(redir);
}

int	apply_input_redirection(t_token **tokens, t_token *redir,
		t_token *target, t_shell *shell)
{
	int	fd;

	if (redir->type == DLESS)
	{
		if (target->heredoc_fd >= 0)
		{
			fd = target->heredoc_fd;
			target->heredoc_fd = -1;
		}
		else
			fd = create_heredoc_fd(target->value,
					should_expand_heredoc(target->value), shell);
	}
	else
		fd = open(target->value, O_RDONLY);
	if (fd < 0)
	{
		if (redir->type == DLESS)
			return (-1);
		printf("%s: %s: %s\n", NAME, target->value, strerror(errno));
		shell->exit_status = 1;
		return (-1);
	}
	cleanup_dless_nodes(tokens, redir, target);
	return (fd);
}

int	apply_redir_by_type(t_token **tokens, t_token *redir,
			t_token *target, t_shell *shell)
{
	if (redir->type == LESS || redir->type == DLESS)
		return (apply_redirection_stdin(tokens, redir, target, shell));
	else
		return (apply_redirection_stdout(tokens, redir, target, shell));
}

int	handle_one_redirection(t_token **tokens, t_token *redir,
			t_shell *shell)
{
	t_token	*target;

	if (!tokens || !redir)
		return (-1);
	target = redir->next;
	if (check_target_valid(target, shell) == -1)
		return (-1);
	if (redir->type == DLESS || redir->type == LESS)
		return (apply_input_redirection(tokens, redir, target, shell));
	return (apply_redir_by_type(tokens, redir, target, shell));
}
