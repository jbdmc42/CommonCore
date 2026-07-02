/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_helpers_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 17:49:50 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:08:37 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

int	handle_pipe_fork_error(t_pipe_ctx *ctx)
{
	perror("fork");
	close_fd(&ctx->prev_read_fd);
	if (ctx->i < ctx->num_cmds - 1)
	{
		close_fd(&ctx->pipe_fd[0]);
		close_fd(&ctx->pipe_fd[1]);
	}
	return (1);
}

static int	get_exit_code(int status)
{
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
		write(STDOUT_FILENO, "\n", 1);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	else
		return (1);
}

int	wait_pipe_children(t_pipe_ctx *ctx)
{
	int	last_status;
	int	code;

	last_status = 0;
	ctx->child_count = ctx->num_cmds;
	ctx->shell->exit_status = 0;
	while (ctx->child_count > 0)
	{
		ctx->pid = waitpid(-1, &ctx->status, 0);
		if (ctx->pid == -1)
		{
			if (errno == EINTR)
				continue ;
			break ;
		}
		code = get_exit_code(ctx->status);
		if (ctx->pid == ctx->last_pid)
			ctx->shell->exit_status = code;
		last_status = code;
		ctx->child_count--;
	}
	if (ctx->last_pid <= 0)
		ctx->shell->exit_status = last_status;
	return (ctx->shell->exit_status);
}

static int	fork_and_handle(t_pipe_ctx *ctx)
{
	ctx->pid = fork();
	if (ctx->pid == -1)
	{
		if (ctx->cmd)
		{
			free_tokens(ctx->cmd);
			ctx->cmd = NULL;
		}
		return (handle_pipe_fork_error(ctx));
	}
	if (ctx->pid == 0)
		setup_pipe_child(ctx);
	return (0);
}

int	run_pipe_stage(t_pipe_ctx *ctx)
{
	ctx->cmd = extract_command(ctx->tokens, &ctx->next_token);
	if (create_pipe_if_needed(ctx) == 1)
		return (1);
	if (fork_and_handle(ctx) == 1)
		return (1);
	post_parent_housekeeping(ctx);
	return (0);
}
