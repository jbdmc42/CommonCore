/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_helpers_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 13:49:12 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:03:13 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**  prints the elements of the env struct after being sorted by alpha_sort
*/
void	print_env(t_shell *shell)
{
	char	**var;
	int		i;

	i = 0;
	var = alpha_sort(shell);
	if (!var)
		return ;
	while (var[i])
	{
		printf("declare -x %s\n", var[i]);
		i++;
	}
	i = 0;
	while (var[i])
		free(var[i++]);
	free(var);
}

/*
**  parses and checks the syntax of each argument:
** if it is correct, defines the variable using a split on the token
*/
void	parse_argument(t_token *tokens, t_shell *shell)
{
	char	**nameval;
	char	*arg;
	int		is_append;

	arg = tokens->value;
	nameval = split_export_arg(tokens->value, &is_append);
	if (!nameval)
		return ;
	if (!nameval[0])
	{
		free(nameval);
		return ;
	}
	if (!is_valid_var_name(nameval[0]))
	{
		printf("%s: line 1: export: `%s': ", NAME, arg);
		printf("not a valid identifier\n");
		free_nameval(nameval);
		shell->exit_status = 1;
		return ;
	}
	process_export_var(nameval, shell, is_append);
}

int	fill_node(t_env *var, char *name, char *val, t_env *cur)
{
	if (!val)
		val = "";
	var->name = ft_strdup(name);
	if (!var->name)
		return (0);
	var->val = ft_strdup(val);
	if (!var->val)
	{
		free(var->name);
		return (0);
	}
	var->next = NULL;
	var->prev = cur;
	return (1);
}

void	define_value(t_shell *shell, char *name, char *val)
{
	t_env	*cur;
	t_env	*var;

	cur = shell->env;
	while (cur && cur->next)
		cur = cur->next;
	var = malloc(sizeof(t_env));
	if (!var)
		return ;
	if (!fill_node(var, name, val, cur))
	{
		free(var);
		return ;
	}
	if (shell->env == NULL)
	{
		shell->env = var;
		var->prev = NULL;
	}
	else
		cur->next = var;
}
