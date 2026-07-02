/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:55:00 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 18:08:12 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin_command(char *cmd)
{
	if (!cmd)
		return (0);
	return (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "exit")
		|| !ft_strcmp(cmd, "export") || !ft_strcmp(cmd, "env")
		|| !ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, "cd")
		|| !ft_strcmp(cmd, "unset"));
}

void	execute_builtin(t_token *tokens, t_shell *shell)
{
	if (!ft_strcmp(tokens->value, "echo"))
		ft_echo(tokens, shell);
	else if (!ft_strcmp(tokens->value, "exit"))
		ft_exit(tokens, shell);
	else if (!ft_strcmp(tokens->value, "export"))
		ft_export(tokens, shell);
	else if (!ft_strcmp(tokens->value, "env"))
		ft_env(tokens, shell);
	else if (!ft_strcmp(tokens->value, "pwd"))
		ft_pwd(shell);
	else if (!ft_strcmp(tokens->value, "cd"))
		ft_cd(tokens, shell);
	else if (!ft_strcmp(tokens->value, "unset"))
		ft_unset(tokens, shell);
	shell->exit_status = 0;
}

int	count_tokens_for_argv(t_token *tokens)
{
	t_token	*temp;
	int		count;

	temp = tokens;
	count = 0;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

char	**build_argv(t_token *tokens)
{
	char	**argv;
	int		count;
	int		i;

	count = count_tokens_for_argv(tokens);
	argv = malloc(sizeof(char *) * (count + 1));
	if (!argv)
		return (NULL);
	i = 0;
	while (tokens)
	{
		argv[i++] = tokens->value;
		tokens = tokens->next;
	}
	argv[i] = NULL;
	return (argv);
}
