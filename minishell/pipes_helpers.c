/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 17:49:50 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:08:37 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		free_inherited_resources(t_pipe_ctx *ctx);
void		child_dup_fds(t_pipe_ctx *ctx);
void		child_finish(t_pipe_ctx *ctx);
int			create_pipe_if_needed(t_pipe_ctx *ctx);
void		post_parent_housekeeping(t_pipe_ctx *ctx);
static void	close_heredoc_fds(t_token *tokens);
static int	process_heredoc_token(t_pipe_ctx *ctx, t_token *cur);

void	init_pipe_ctx(t_pipe_ctx *ctx, t_token *tokens, t_shell *shell)
{
	ctx->tokens = tokens;
	ctx->cmd = NULL;
	ctx->next_token = NULL;
	ctx->shell = shell;
	ctx->num_cmds = count_commands(tokens);
	ctx->i = 0;
	ctx->pipe_fd[0] = -1;
	ctx->pipe_fd[1] = -1;
	ctx->prev_read_fd = -1;
	ctx->status = 0;
	ctx->child_count = 0;
	ctx->pid = -1;
	ctx->last_pid = -1;
}

int	pre_create_heredocs(t_pipe_ctx *ctx)
{
	t_token	*cur;
	int		result;

	cur = ctx->tokens;
	while (cur)
	{
		if (cur->type == DLESS)
		{
			result = process_heredoc_token(ctx, cur);
			if (result == -1)
				return (0);
			if (result == 1)
				return (1);
		}
		cur = cur->next;
	}
	return (0);
}

static void	close_heredoc_fds(t_token *tokens)
{
	t_token	*cur;

	cur = tokens;
	while (cur)
	{
		if (cur->heredoc_fd >= 0)
		{
			close(cur->heredoc_fd);
			cur->heredoc_fd = -1;
		}
		cur = cur->next;
	}
}

static int	process_heredoc_token(t_pipe_ctx *ctx, t_token *cur)
{
	t_token	*target;
	int		should_expand;
	int		fd;

	target = cur->next;
	if (!target)
		return (-1);
	if (target->heredoc_fd >= 0)
		return (0);
	should_expand = 1;
	if (target->value && target->value[0] == '\x01')
		should_expand = 0;
	fd = create_heredoc_fd(target->value, should_expand, ctx->shell);
	if (fd < 0)
	{
		close_heredoc_fds(ctx->tokens);
		return (1);
	}
	target->heredoc_fd = fd;
	return (0);
}

void	setup_pipe_child(t_pipe_ctx *ctx)
{
	child_dup_fds(ctx);
	child_finish(ctx);
}
