/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:55:46 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:08:37 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	fill_env_node(t_env *node, char *envp_entry, char *equals)
{
	if (equals)
	{
		node->name = ft_substr(envp_entry, 0, equals - envp_entry);
		if (!node->name)
			return (0);
		node->val = ft_strdup(equals + 1);
		if (!node->val)
		{
			free(node->name);
			return (0);
		}
	}
	else
	{
		node->name = ft_strdup(envp_entry);
		if (!node->name)
			return (0);
		node->val = ft_strdup("");
		if (!node->val)
		{
			free(node->name);
			return (0);
		}
	}
	return (1);
}

static t_env	*create_env_node(char *envp_entry)
{
	t_env	*new_node;
	char	*equals;

	new_node = malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	equals = ft_strchr(envp_entry, '=');
	if (!fill_env_node(new_node, envp_entry, equals))
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

static void	add_env_node(t_env **head, t_env *new_node)
{
	t_env	*current;

	if (!*head)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new_node;
	new_node->prev = current;
}

void	init_env(t_shell *shell, char **envp)
{
	int		i;
	t_env	*new_node;

	shell->env = NULL;
	i = 0;
	while (envp[i])
	{
		new_node = create_env_node(envp[i]);
		if (new_node)
			add_env_node(&shell->env, new_node);
		i++;
	}
}

char	*env_get_value(t_env *env, const char *name)
{
	while (env)
	{
		if (!ft_strcmp(env->name, name))
			return (ft_strdup(env->val));
		env = env->next;
	}
	return (NULL);
}
