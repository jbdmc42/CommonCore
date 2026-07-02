/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_helpers_four.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 13:59:53 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:03:37 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_sigint_ignore(struct sigaction *old_int)
{
	struct sigaction	ignore;

	sigemptyset(&ignore.sa_mask);
	ignore.sa_flags = 0;
	ignore.sa_handler = SIG_IGN;
	sigaction(SIGINT, &ignore, old_int);
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

static int	run_pipe_stages(t_pipe_ctx *ctx)
{
	while (ctx->i < ctx->num_cmds)
	{
		if (run_pipe_stage(ctx) == 1)
			return (1);
		ctx->tokens = ctx->next_token;
		ctx->i++;
	}
	return (0);
}

static int	finish_pipe_chain(t_pipe_ctx *ctx, t_token *tokens,
			struct sigaction *old_int, int stage_status)
{
	int	status;

	close_heredoc_fds(tokens);
	if (stage_status != 0)
	{
		if (ctx->i > 0)
		{
			ctx->num_cmds = ctx->i;
			wait_pipe_children(ctx);
		}
		sigaction(SIGINT, old_int, NULL);
		ctx->shell->exit_status = 1;
		return (1);
	}
	status = wait_pipe_children(ctx);
	sigaction(SIGINT, old_int, NULL);
	return (status);
}

int	execute_pipe_chain(t_token *tokens, t_shell *shell)
{
	t_pipe_ctx			ctx;
	int					status;
	struct sigaction	old_int;

	init_pipe_ctx(&ctx, tokens, shell);
	ctx.tokens = tokens;
	set_sigint_ignore(&old_int);
	if (pre_create_heredocs(&ctx) == 1)
	{
		sigaction(SIGINT, &old_int, NULL);
		shell->exit_status = 1;
		return (1);
	}
	status = run_pipe_stages(&ctx);
	return (finish_pipe_chain(&ctx, tokens, &old_int, status));
}
