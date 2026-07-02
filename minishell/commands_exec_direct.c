/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_exec_direct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 17:55:00 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:11:48 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

static void	set_sigint_ignore(struct sigaction *old_int)
{
	struct sigaction	ignore;

	sigemptyset(&ignore.sa_mask);
	ignore.sa_flags = 0;
	ignore.sa_handler = SIG_IGN;
	sigaction(SIGINT, &ignore, old_int);
}

static pid_t	fork_and_exec(char *command, t_exec_ctx *ctx)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		close_saved_redirections_in_child(ctx->shell);
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		execve(command, ctx->argv, ctx->envp);
		print_exec_error(command);
		exit(126);
	}
	return (pid);
}

static void	wait_and_capture_status(pid_t pid, t_exec_ctx *ctx,
			struct sigaction *old_int)
{
	int	status;

	status = 0;
	while (waitpid(pid, &status, 0) == -1 && errno == EINTR)
		;
	if (WIFSIGNALED(status) && (WTERMSIG(status) == SIGINT
			|| WTERMSIG(status) == SIGQUIT))
		write(STDOUT_FILENO, "\n", 1);
	sigaction(SIGINT, old_int, NULL);
	if (WIFEXITED(status))
		ctx->shell->exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		ctx->shell->exit_status = 128 + WTERMSIG(status);
	else
		ctx->shell->exit_status = 1;
}

int	exec_direct_path(char *command, t_exec_ctx *ctx)
{
	pid_t				pid;
	struct sigaction	old_int;

	set_sigint_ignore(&old_int);
	pid = fork_and_exec(command, ctx);
	if (pid < 0)
		return (-1);
	wait_and_capture_status(pid, ctx, &old_int);
	return (0);
}
