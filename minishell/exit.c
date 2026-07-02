/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:15:11 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:03:12 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_numeric(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	count_tokens(t_token *tokens)
{
	int		count;
	t_token	*cur;

	count = 0;
	cur = tokens;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return (count);
}

static void	cleanup(t_token *tokens, t_shell *shell)
{
	free_tokens(tokens);
	cleanup_redirections(shell);
	free_shell_env(shell);
	clean_exit(shell);
}

void	ft_exit(t_token *tokens, t_shell *shell)
{
	int		token_count;

	token_count = count_tokens(tokens);
	if (token_count > 2)
	{
		printf("%s: exit: too many arguments\n", NAME);
		shell->exit_status = 1;
		return ;
	}
	if (token_count == 2)
	{
		if (!is_numeric(tokens->next->value))
		{
			printf("%s: exit: %s: numeric argument required\n",
				NAME, tokens->next->value);
			shell->exit_status = 2;
			cleanup(tokens, shell);
			return ;
		}
		shell->exit_status = ft_atoi(tokens->next->value);
	}
	cleanup(tokens, shell);
}
