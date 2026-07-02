/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers_three.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:20:00 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:08:37 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*extract_quoted_part(char *line, size_t *i, t_shell *shell)
{
	size_t	start;
	char	quote;
	char	*raw;
	char	*out;

	quote = line[*i];
	(*i)++;
	start = *i;
	while (line[*i] && line[*i] != quote)
		(*i)++;
	if (line[*i] == quote)
		(*i)++;
	raw = ft_substr(line, start, *i - start - (line[*i - 1] == quote));
	if (quote == '\'')
		out = raw;
	else
	{
		out = expand_variable_in_part(raw, shell);
		free(raw);
	}
	return (out);
}

static char	*extract_unquoted_part(char *line, size_t *i, t_shell *shell)
{
	size_t	start;
	char	*raw;
	char	*out;

	start = *i;
	while (line[*i] && line[*i] != ' ' && line[*i] != '\t'
		&& !is_operator_char(line[*i])
		&& line[*i] != '\'' && line[*i] != '"')
		(*i)++;
	raw = ft_substr(line, start, *i - start);
	out = expand_variable_in_part(raw, shell);
	free(raw);
	return (out);
}

char	*extract_word_part(char *line, size_t *i, t_shell *shell)
{
	if (line[*i] == '\'' || line[*i] == '"')
		return (extract_quoted_part(line, i, shell));
	return (extract_unquoted_part(line, i, shell));
}
