/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:40:00 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:42:03 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

int	heredoc_loop(int write_fd, char *delimiter, int should_expand,
		t_shell *shell);

static char	*get_real_delimiter(const char *delimiter)
{
	if (!delimiter)
		return (NULL);
	if ((unsigned char)*delimiter == 0x01)
		return ((char *)(delimiter + 1));
	return ((char *)delimiter);
}

static int	heredoc_cleanup_error(t_heredoc_ctx *ctx)
{
	restore_heredoc_parent_signals(&ctx->old_int, &ctx->old_quit);
	close(ctx->pipe_fd[0]);
	close(ctx->pipe_fd[1]);
	return (-1);
}

static void	heredoc_run_child(t_heredoc_ctx *ctx)
{
	close(ctx->pipe_fd[0]);
	run_heredoc_child(ctx->pipe_fd[1], get_real_delimiter(ctx->delimiter),
		ctx->should_expand, ctx->shell);
}

static int	heredoc_finish_parent(t_heredoc_ctx *ctx)
{
	if (wait_heredoc_child(ctx->pid, &ctx->status) == -1)
		return (heredoc_cleanup_error(ctx));
	restore_heredoc_parent_signals(&ctx->old_int, &ctx->old_quit);
	if (WIFSIGNALED(ctx->status) && WTERMSIG(ctx->status) == SIGINT)
	{
		if (ctx->shell)
			ctx->shell->exit_status = 130;
		write(STDOUT_FILENO, "\n", 1);
		close(ctx->pipe_fd[0]);
		return (-1);
	}
	return (ctx->pipe_fd[0]);
}

int	create_heredoc_fd(char *delimiter, int should_expand, t_shell *shell)
{
	t_heredoc_ctx	ctx;

	ctx.delimiter = delimiter;
	ctx.should_expand = should_expand;
	ctx.shell = shell;
	if (pipe(ctx.pipe_fd) == -1)
		return (-1);
	set_heredoc_parent_signals(&ctx.old_int, &ctx.old_quit);
	ctx.pid = fork();
	if (ctx.pid == -1)
		return (heredoc_cleanup_error(&ctx));
	if (ctx.pid == 0)
		heredoc_run_child(&ctx);
	close(ctx.pipe_fd[1]);
	return (heredoc_finish_parent(&ctx));
}
