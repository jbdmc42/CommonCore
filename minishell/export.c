/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:49:55 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:03:16 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	validate_export_argument(char *arg, t_shell *shell)
{
	char	**nameval;
	int		is_append;

	nameval = split_export_arg(arg, &is_append);
	if (!nameval)
		return (0);
	if (!is_valid_var_name(nameval[0]))
	{
		printf("%s: export: `%s': ", NAME, arg);
		printf("not a valid identifier\n");
		free_nameval(nameval);
		shell->exit_status = 1;
		return (0);
	}
	free_nameval(nameval);
	return (1);
}

static int	validate_export_arguments(t_token *tokens, t_shell *shell)
{
	int	all_valid;

	all_valid = 1;
	while (tokens != NULL)
	{
		if (!validate_export_argument(tokens->value, shell))
			all_valid = 0;
		tokens = tokens->next;
	}
	return (all_valid);
}

/*
**  processes a validated export variable
*/
void	process_export_var(char **nameval, t_shell *shell, int is_append)
{
	process_nameval_quotes(nameval);
	redefine_value(shell, nameval, is_append);
	free_nameval(nameval);
}

/*
**  sorts all the elements in the env struct for the print
*/
char	**alpha_sort(t_shell *shell)
{
	t_env	*cur;
	char	**var;
	int		i;
	int		j;

	i = 0;
	cur = shell->env;
	var = malloc(sizeof(char *) * ((env_lstsize(shell->env)) + 1));
	if (!var)
		return (NULL);
	var = ft_lsttochpp(var, cur);
	i = 0;
	while (i < (env_lstsize(shell->env)) - 1)
	{
		j = 0;
		while (j < (env_lstsize(shell->env)) - i - 1)
		{
			if (ft_strcmp(var[j], var[j + 1]) > 0)
				ft_swap(&var[j], &var[j + 1]);
			j++;
		}
		i++;
	}
	return (var);
}

/*
**  executes the 'export' command:
** the export command needs at least one WORD type token after the command in
** order to work. 
*/
void	ft_export(t_token *tokens, t_shell *shell)
{
	shell->exit_status = 0;
	if (tokens->next == NULL)
	{
		print_env(shell);
		return ;
	}
	tokens = tokens->next;
	if (!validate_export_arguments(tokens, shell))
		return ;
	while (tokens != NULL)
	{
		parse_argument(tokens, shell);
		tokens = tokens->next;
	}
}
