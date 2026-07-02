/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:00:00 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:08:37 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_error_command(char *line)
{
	size_t	start;
	size_t	end;

	start = 0;
	while (line[start] == ' ' || line[start] == '\t')
		start++;
	if (!line[start])
		return (NULL);
	end = start;
	while (line[end] && line[end] != ' ' && line[end] != '\t'
		&& line[end] != '|' && line[end] != '<' && line[end] != '>')
		end++;
	return (ft_substr(line, start, end - start));
}

static void	print_unclosed_quote_error(char *line, char quote)
{
	char	*command;

	command = get_error_command(line);
	if (command && command[0])
		printf("%s: %s: syntax error near unexpected token `%c'\n",
			NAME, command, quote);
	else
		printf("%s: syntax error near unexpected token `%c'\n", NAME, quote);
	free(command);
}

/*
**  Check if quotes are balanced in the input string.
**  Returns 1 if balanced, 0 if unbalanced.
*/
int	is_quotes_balanced(char *str)
{
	int	i;
	int	in_single;
	int	in_double;

	i = 0;
	in_single = 0;
	in_double = 0;
	while (str && str[i])
	{
		if (str[i] == '\'' && !in_double)
			in_single = !in_single;
		else if (str[i] == '"' && !in_single)
			in_double = !in_double;
		i++;
	}
	return (!in_single && !in_double);
}

/*
**  Helper function that checks which quote was unclosed.
** 	Returns 0 for single and 1 for double.
*/
static int	decide_unclosed_quote(int s, int d, t_shell *shell, char *u)
{
	if (s || d)
	{
		if (s)
			*u = '\'';
		else
			*u = '"';
		shell->exit_status = 2;
		return (0);
	}
	return (1);
}

/*
**  Check for unclosed quotes and report syntax error if found.
**  Returns the original line if balanced, NULL if unbalanced.
*/
char	*read_input_with_continuation(char *line, t_shell *shell)
{
	int		i;
	int		in_single;
	int		in_double;
	char	u;

	i = 0;
	in_single = 0;
	in_double = 0;
	if (!line)
		return (NULL);
	while (line[i])
	{
		if (line[i] == '\'' && !in_double)
			in_single = !in_single;
		else if (line[i] == '"' && !in_single)
			in_double = !in_double;
		i++;
	}
	if (!decide_unclosed_quote(in_single, in_double, shell, &u))
	{
		print_unclosed_quote_error(line, u);
		return (NULL);
	}
	return (line);
}
