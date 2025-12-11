/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:40:26 by jbdmc             #+#    #+#             */
/*   Updated: 2025/12/10 19:04:53 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_spaces(char *line, size_t *i, t_token **tokens)
{
	int	skipped;

	skipped = 0;
	while (line[*i] == ' ' || line[*i] == '\t')
	{
		(*i)++;
		skipped = 1;
	}
	return (skipped);
}

int	parse_pipe(char *line, size_t *i, t_token **tokens)
{
	if (line[*i] == '|')
	{
		add_token("|", PIPE);
		(*i)++;
		return (1);
	}
	return (0);
}

int	parse_operator(char *line, size_t *i, t_token **tokens)
{
	if (line[*i] == '<')
    {
        if (line[*i + 1] == '<')
        {
            add_token("<<", DLESS);
            (*i) += 2;
            return (1);
        }
        add_token("<", LESS);
        (*i)++;
        return (1);
    }
	if (line[*i] == '>')
    {
        if (line[*i + 1] == '>')
        {
            add_token(">>", DGREAT);
            (*i) += 2;
            return (1);
        }
        add_token(">", GREAT);
        (*i)++;
        return (1);
    }
    return (0);
}

int	parse_single_quotes(char *line, size_t *i, t_token **tokens)
{
	size_t	start;
	char	*token;

	if (line[*i] != '\'')
		return (0);
	(*i)++;
	start = *i;
	while (line[*i] && line[*i] != '\'')
		(*i)++;
	token = ft_substr(line, start, *i - start);
	add_token(token, WORD);
	free(token);
	if (line[*i] == '\'')
		(*i)++;
	return (1);
}

int	parse_double_quotes(char *line, size_t *i, t_token **tokenss)
{
	size_t	start;
	char	*token;

	if (line[*i] != '\"')
		return (0);
	(*i)++;
	start = *i;
	while (line[*i] && line[*i] != '\"')
		(*i)++;
	token = ft_substr(line, start, *i - start);
	add_token(token, WORD);
	free(token);
	if (line[*i] == '\"')
		(*i)++;
	return (1);
}
