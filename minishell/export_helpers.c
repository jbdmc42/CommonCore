/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:58:32 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:03:14 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**handle_no_equals(char *arg)
{
	char	**nameval;

	nameval = malloc(sizeof(char *) * 3);
	if (!nameval)
		return (NULL);
	nameval[0] = ft_strdup(arg);
	nameval[1] = NULL;
	if (!nameval[0])
	{
		free(nameval);
		return (NULL);
	}
	nameval[2] = NULL;
	return (nameval);
}

static char	*make_name(char *arg, char *equals)
{
	if (equals > arg && equals[-1] == '+')
		return (ft_substr(arg, 0, equals - arg - 1));
	return (ft_substr(arg, 0, equals - arg));
}

static void	assign_env_value(t_env *cur, char *val, int is_append)
{
	char	*combined;
	char	*new_val;

	if (!val)
		val = "";
	if (is_append)
	{
		combined = ft_strjoin(cur->val, val);
		if (!combined)
			return ;
		free(cur->val);
		cur->val = combined;
	}
	else
	{
		new_val = ft_strdup(val);
		if (!new_val)
			return ;
		free(cur->val);
		cur->val = new_val;
	}
}

char	**split_export_arg(char *arg, int *is_append)
{
	char	**nameval;
	char	*equals;

	*is_append = 0;
	equals = ft_strchr(arg, '=');
	if (!equals)
		return (handle_no_equals(arg));
	nameval = malloc(sizeof(char *) * 3);
	if (!nameval)
		return (NULL);
	if (equals > arg && equals[-1] == '+')
		*is_append = 1;
	nameval[0] = make_name(arg, equals);
	nameval[1] = ft_strdup(equals + 1);
	if (!nameval[0] || !nameval[1])
	{
		if (nameval[0])
			free(nameval[0]);
		if (nameval[1])
			free(nameval[1]);
		free(nameval);
		return (NULL);
	}
	nameval[2] = NULL;
	return (nameval);
}

void	redefine_value(t_shell *shell, char **nameval, int is_append)
{
	t_env	*cur;
	char	*val;

	val = nameval[1];
	cur = shell->env;
	while (cur)
	{
		if (ft_strcmp(cur->name, nameval[0]) == 0)
		{
			assign_env_value(cur, val, is_append);
			return ;
		}
		cur = cur->next;
	}
	define_value(shell, nameval[0], val);
}
