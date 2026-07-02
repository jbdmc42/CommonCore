/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers_four.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:30:00 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:08:37 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*expand_question(t_shell *shell)
{
	char	*buf;

	buf = ft_itoa(shell->exit_status);
	return (buf);
}

static char	*get_env_name_and_value(char *part, size_t *idx,
		t_shell *shell)
{
	size_t	start;
	char	*name;
	char	*val;

	start = *idx;
	while (part[*idx] && (part[*idx] == '_' || ft_isalnum(part[*idx])))
		(*idx)++;
	name = ft_substr(part, start, *idx - start);
	val = env_get_value(shell->env, name);
	free(name);
	if (!val)
		return (ft_strdup(""));
	return (val);
}

static char	*append_single_char(const char *part, size_t idx, char *res)
{
	char	*tmp;

	tmp = ft_substr((char *)part, idx, 1);
	res = ft_strjoin_free(res, tmp);
	return (res);
}

static char	*handle_dollar(const char *part, size_t *i, t_shell *shell,
		char *res)
{
	char	*val;

	(*i)++;
	if (part[*i] == '?')
	{
		val = expand_question(shell);
		res = ft_strjoin_free(res, val);
		(*i)++;
		return (res);
	}
	if (part[*i] == '_' || ft_isalpha(part[*i]))
	{
		val = get_env_name_and_value((char *)part, i, shell);
		res = ft_strjoin_free(res, val);
		return (res);
	}
	res = ft_strjoin_free(res, ft_substr((char *)part, *i - 1, 1));
	return (res);
}

char	*expand_variable_in_part(char *part, t_shell *shell)
{
	size_t	i;
	char	*res;

	if (!part)
		return (NULL);
	if (!*part)
		return (ft_strdup(""));
	res = ft_strdup("");
	i = 0;
	while (part[i])
	{
		if (part[i] == '$')
			res = handle_dollar(part, &i, shell, res);
		else
		{
			res = append_single_char(part, i, res);
			i++;
		}
	}
	return (res);
}
