/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:58:46 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:04:11 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**  frees all elements in a nameval array
*/
void	free_nameval(char **nameval)
{
	int	i;

	i = 0;
	while (nameval[i])
	{
		free(nameval[i]);
		i++;
	}
	free(nameval);
}

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

char	*remove_quotes(char	*nameval)
{
	int		len;
	char	*result;

	len = ft_strlen(nameval);
	if (len >= 2 && nameval[0] == '"' && nameval[len - 1] == '"')
		result = ft_substr(nameval, 1, len - 2);
	else
		result = ft_strdup(nameval);
	return (result);
}

void	process_nameval_quotes(char **nameval)
{
	char	*temp;

	if (nameval[0])
	{
		temp = remove_quotes(nameval[0]);
		free(nameval[0]);
		nameval[0] = temp;
	}
	if (nameval[1])
	{
		temp = remove_quotes(nameval[1]);
		free(nameval[1]);
		nameval[1] = temp;
	}
}

int	is_valid_var_name(char *name)
{
	int	i;

	if (!name || !name[0])
		return (0);
	if (ft_isdigit(name[0]))
		return (0);
	i = 0;
	while (name[i])
	{
		if (name[i] == '-' || (!ft_isalnum(name[i]) && name[i] != '_'))
			return (0);
		i++;
	}
	return (1);
}
