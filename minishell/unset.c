/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:50:42 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:04:07 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	remove_env_var(t_shell *shell, char *name)
{
	t_env	*current;
	t_env	*next;

	current = shell->env;
	while (current)
	{
		next = current->next;
		if (ft_strcmp(current->name, name) == 0)
		{
			if (current->prev)
				current->prev->next = current->next;
			else
				shell->env = current->next;
			if (current->next)
				current->next->prev = current->prev;
			free(current->name);
			free(current->val);
			free(current);
		}
		current = next;
	}
}

int	ft_unset(t_token *tokens, t_shell *shell)
{
	int		exit_status;
	t_token	*cur;

	exit_status = 0;
	if (!tokens)
		return (0);
	cur = tokens->next;
	while (cur)
	{
		if (!is_valid_var_name(cur->value))
		{
			printf("%s: unset: `%s': not a valid identifier\n",
				NAME, cur->value);
			exit_status = 1;
		}
		else
		{
			remove_env_var(shell, cur->value);
		}
		cur = cur->next;
	}
	shell->exit_status = exit_status;
	return (exit_status);
}
