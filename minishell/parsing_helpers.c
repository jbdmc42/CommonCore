/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:40:26 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:08:37 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_pipe(char *line, size_t *i, t_token **tokens, t_shell *shell)
{
	if (line[*i] == '|')
	{
		add_token("|", PIPE, tokens);
		(*i)++;
		if (!syntaxe_error(line, *i))
			shell->exit_status = 2;
		return (1);
	}
	return (0);
}

int	parse_less(char *line, size_t *i, t_token **tokens, t_shell *shell)
{
	if (line[*i] == '<')
	{
		if (line[*i + 1] == '<')
		{
			add_token("<<", DLESS, tokens);
			(*i) += 2;
			if (!syntaxe_error(line, *i))
				shell->exit_status = 2;
			return (1);
		}
		add_token("<", LESS, tokens);
		(*i)++;
		if (!syntaxe_error(line, *i))
			shell->exit_status = 2;
		return (1);
	}
	return (0);
}

int	parse_great(char *line, size_t *i, t_token **tokens, t_shell *shell)
{
	if (line[*i] == '>')
	{
		if (line[*i + 1] == '>')
		{
			add_token(">>", DGREAT, tokens);
			(*i) += 2;
			if (!syntaxe_error(line, *i))
				shell->exit_status = 2;
			return (1);
		}
		add_token(">", GREAT, tokens);
		(*i)++;
		if (!syntaxe_error(line, *i))
			shell->exit_status = 2;
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
	if (line[*i] == '\0')
	{
		printf("%s: unexpected EOF while looking for matching `'\n", NAME);
		return (-1);
	}
	token = ft_substr(line, start, *i - start);
	add_token(token, WORD, tokens);
	free(token);
	if (line[*i] == '\'')
		(*i)++;
	return (1);
}

int	parse_double_quotes(char *line, size_t *i, t_token **tokens)
{
	size_t	start;
	char	*token;

	if (line[*i] != '"')
		return (0);
	(*i)++;
	start = *i;
	while (line[*i] && line[*i] != '"')
		(*i)++;
	if (line[*i] == '\0')
	{
		printf("%s: unexpected EOF while looking for matching `\"\n", NAME);
		return (-1);
	}
	token = ft_substr(line, start, *i - start);
	add_token(token, WORD, tokens);
	free(token);
	if (line[*i] == '"')
		(*i)++;
	return (1);
}
