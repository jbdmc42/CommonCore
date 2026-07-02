/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_helpers_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 19:05:00 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:08:37 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

int	check_target_valid(t_token *target, t_shell *shell)
{
	const char	*error_msg;

	if (!target || target->type != WORD)
	{
		if (target)
			error_msg = target->value;
		else
			error_msg = "newline";
		printf("%s: syntax error near unexpected token `%s'\n",
			NAME, error_msg);
		shell->exit_status = 2;
		return (-1);
	}
	return (0);
}

static void	cleanup_target_and_redir(t_token **tokens, t_token *redir,
		t_token *target)
{
	t_token	*next;

	next = target->next;
	free(target->value);
	free(target);
	unlink_token_node(tokens, redir, next);
	free(redir->value);
	free(redir);
}

int	apply_redirection_stdin(t_token **tokens, t_token *redir,
			t_token *target, t_shell *shell)
{
	int	fd;

	if (!target || !target->value)
	{
		printf("%s: syntax error near unexpected token `newline'\n", NAME);
		shell->exit_status = 2;
		return (-1);
	}
	fd = open(target->value, O_RDONLY);
	if (fd < 0)
	{
		printf("%s: %s: %s\n", NAME, target->value, strerror(errno));
		shell->exit_status = 1;
		return (-1);
	}
	if (perform_dup2_and_close(fd, STDIN_FILENO, shell) == -1)
		return (-1);
	cleanup_target_and_redir(tokens, redir, target);
	return (0);
}

static int	open_output_file(const char *path, t_token *redir)
{
	int	fd;
	int	flags;

	flags = O_CREAT | O_WRONLY;
	if (redir->type == DGREAT)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	fd = open(path, flags, 0644);
	return (fd);
}

int	apply_redirection_stdout(t_token **tokens, t_token *redir,
			t_token *target, t_shell *shell)
{
	int	fd;

	if (!target || !target->value)
	{
		printf("%s: syntax error near unexpected token `newline'\n", NAME);
		shell->exit_status = 2;
		return (-1);
	}
	fd = open_output_file(target->value, redir);
	if (fd < 0)
	{
		printf("%s: %s: %s\n", NAME, target->value, strerror(errno));
		shell->exit_status = 1;
		return (-1);
	}
	if (perform_dup2_and_close(fd, STDOUT_FILENO, shell) == -1)
		return (-1);
	cleanup_target_and_redir(tokens, redir, target);
	return (0);
}
