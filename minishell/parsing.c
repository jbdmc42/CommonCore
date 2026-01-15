/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 13:54:22 by jbdmc             #+#    #+#             */
/*   Updated: 2025/12/15 15:29:45 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_operator_char(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

int	syntaxe_error(char *line, size_t i)
{
	if (line[i] == '>' || line[i] == '<' || line[i] == '|')
	{
		printf("minishell: syntax error near unexpected token `%s'\n", &line[i]);
		return (0);
	}
	return (1);
}

int	skip_spaces(char *line, size_t *i)
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

void	parse_word(char *line, size_t *i, t_token **tokens)
{
	size_t	start;
	char	*token;

	start = *i;
	while (line[*i] && line[*i] != ' ' && line[*i] != '\t' &&
		!is_operator_char(line[*i]) && line[*i] != '\'' && line[*i] != '\"')
		(*i)++;
	token = ft_substr(line, start, *i - start);
	add_token(token, WORD, tokens);
	free(token);
}

void	parse_input(char *line, size_t i, t_token **tokens)
{
	while (line[i] != '\0')
	{
		if (skip_spaces(line, &i))
			continue ;
		if (parse_single_quotes(line, &i, tokens))
			continue ;
		if (parse_double_quotes(line, &i, tokens))
			continue ;
		if (parse_pipe(line, &i, tokens))
			continue ;
		if (parse_less(line, &i, tokens))
			continue ;
		if (parse_great(line, &i, tokens))
			continue ;
		parse_word(line, &i, tokens);
	}
	get_commands(tokens);
}
