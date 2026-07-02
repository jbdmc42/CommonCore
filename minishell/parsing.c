/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 13:54:22 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:08:37 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	report_syntax_error(t_token *token, t_shell *shell)
{
	const char	*msg;

	if (!token || !token->value)
		msg = "newline";
	else
		msg = token->value;
	printf("%s: syntax error near unexpected token `%s'\n", NAME, msg);
	shell->exit_status = 2;
	return (0);
}

static int	validate_pipeline_tokens(t_token *tokens, t_shell *shell)
{
	t_token	*prev;
	t_token	*next;

	if (!tokens)
		return (1);
	if (tokens->type == PIPE)
		return (report_syntax_error(tokens, shell));
	prev = NULL;
	while (tokens)
	{
		if (tokens->type == PIPE)
		{
			next = tokens->next;
			if (!prev || prev->type == PIPE || !next)
				return (report_syntax_error(tokens, shell));
			if (next->type != WORD)
				return (report_syntax_error(next, shell));
		}
		prev = tokens;
		tokens = tokens->next;
	}
	return (1);
}

int	syntaxe_error(char *line, size_t i)
{
	if (line[i] == '>' || line[i] == '<' || line[i] == '|')
	{
		printf("%s: syntax error near", NAME);
		printf(" unexpected token `%s'\n", &line[i]);
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

void	parse_input(char *line, size_t i, t_token **tokens, t_shell *shell)
{
	while (line[i] != '\0')
	{
		if (skip_spaces(line, &i))
			continue ;
		if (parse_pipe(line, &i, tokens, shell))
			continue ;
		if (parse_less(line, &i, tokens, shell))
			continue ;
		if (parse_great(line, &i, tokens, shell))
			continue ;
		parse_word(line, &i, tokens, shell);
	}
	if (!validate_pipeline_tokens(*tokens, shell))
	{
		free_tokens(*tokens);
		*tokens = NULL;
		return ;
	}
	get_commands(*tokens, shell);
}
