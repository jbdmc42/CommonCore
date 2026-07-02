/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_process_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:47:48 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:03:58 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	finalize_pending_stdin_fd(int pending_stdin_fd, t_shell *shell,
				int saved_stdin, int saved_stdout);

static void	init_redir_process_ctx_base(t_redir_process_ctx *ctx,
		t_token **tokens, t_shell *shell, int *pending_stdin_fd)
{
	ctx->tokens = tokens;
	ctx->shell = shell;
	ctx->pending_stdin_fd = pending_stdin_fd;
}

static int	process_redirection_token(t_token *current,
		t_redir_process_ctx *ctx)
{
	t_token	*target;
	int		fd;
	int		type;

	target = current->next;
	type = current->type;
	*ctx->next = NULL;
	if (target)
		*ctx->next = target->next;
	fd = handle_one_redirection(ctx->tokens, current, ctx->shell);
	if (fd < 0)
		return (restore_redirections(ctx->saved_stdin, ctx->saved_stdout), -1);
	if (type == LESS || type == DLESS)
	{
		if (*ctx->pending_stdin_fd >= 0)
			close(*ctx->pending_stdin_fd);
		*ctx->pending_stdin_fd = fd;
	}
	return (0);
}

static int	process_redirection_loop(t_token **tokens, t_redir_process_ctx *ctx)
{
	t_token	*current;

	current = *tokens;
	while (current)
	{
		if (current->type == LESS || current->type == DLESS
			|| current->type == GREAT || current->type == DGREAT)
		{
			if (process_redirection_token(current, ctx) == -1)
				return (-1);
			current = *ctx->next;
			continue ;
		}
		current = current->next;
	}
	return (finalize_pending_stdin_fd(*ctx->pending_stdin_fd, ctx->shell,
			ctx->saved_stdin, ctx->saved_stdout));
}

static int	finalize_pending_stdin_fd(int pending_stdin_fd, t_shell *shell,
		int saved_stdin, int saved_stdout)
{
	if (pending_stdin_fd >= 0)
	{
		if (perform_dup2_and_close(pending_stdin_fd, STDIN_FILENO, shell) == -1)
			return (restore_redirections(saved_stdin, saved_stdout), -1);
	}
	return (0);
}

int	process_token_redirections(t_token **tokens, t_shell *shell,
			int saved_stdin, int saved_stdout)
{
	t_redir_process_ctx	ctx;
	t_token				*next;
	int					pending_stdin_fd;

	if (!tokens || !*tokens)
		return (0);
	pending_stdin_fd = -1;
	init_redir_process_ctx_base(&ctx, tokens, shell, &pending_stdin_fd);
	ctx.next = &next;
	ctx.saved_stdin = saved_stdin;
	ctx.saved_stdout = saved_stdout;
	return (process_redirection_loop(tokens, &ctx));
}
