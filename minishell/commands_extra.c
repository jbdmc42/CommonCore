/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:34:55 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:11:40 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

void	close_saved_redirections_in_child(t_shell *shell)
{
	if (!shell)
		return ;
	if (shell->saved_stdin >= 0)
		close(shell->saved_stdin);
	if (shell->saved_stdout >= 0)
		close(shell->saved_stdout);
}

static int	wait_and_set_status(pid_t pid, t_shell *shell)
{
	int					status;
	struct sigaction	old_int;
	struct sigaction	ignore;

	sigemptyset(&ignore.sa_mask);
	ignore.sa_flags = 0;
	ignore.sa_handler = SIG_IGN;
	sigaction(SIGINT, &ignore, &old_int);
	status = 0;
	while (waitpid(pid, &status, 0) == -1 && errno == EINTR)
		;
	if (WIFSIGNALED(status) && (WTERMSIG(status) == SIGINT
			|| WTERMSIG(status) == SIGQUIT))
		write(STDOUT_FILENO, "\n", 1);
	sigaction(SIGINT, &old_int, NULL);
	if (WIFEXITED(status))
		shell->exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		shell->exit_status = 128 + WTERMSIG(status);
	else
		shell->exit_status = 1;
	return (0);
}

int	exec_found_command(char *full_path, char *command, t_exec_ctx *ctx)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		close_saved_redirections_in_child(ctx->shell);
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		execve(full_path, ctx->argv, ctx->envp);
		print_exec_error(command);
		exit(126);
	}
	if (pid < 0)
		return (-1);
	return (wait_and_set_status(pid, ctx->shell));
}

int	search_and_execute(char *command, char **argv, char **envp, t_shell *shell)
{
	char		*path;
	char		*path_copy;
	t_exec_ctx	ctx;

	if (!command || !argv || !envp)
		return (-1);
	ctx.argv = argv;
	ctx.envp = envp;
	ctx.shell = shell;
	if (ft_strchr(command, '/'))
		return (exec_direct_path(command, &ctx));
	path = env_get_value(shell->env, "PATH");
	if (!path)
		return (-1);
	path_copy = ft_strdup(path);
	free(path);
	if (!path_copy)
		return (-1);
	if (try_exec_in_path(path_copy, command, &ctx) == 0)
	{
		free(path_copy);
		return (0);
	}
	free(path_copy);
	return (-1);
}
