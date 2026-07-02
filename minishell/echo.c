/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 10:00:45 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 18:07:42 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**  echo helper function: takes the token right after the echo command and
** checks if that token is a valid '-n' flag.
**  If it is, defines the flag boolean to 0, so that in the end of the
** echo function it will check the value of the boolean, and 0 means it is not
** supposed to print the newline, leaving without ever printing it.
*/
static int	is_valid_n_flag(char *s)
{
	int	i;

	if (!s || s[0] != '-')
		return (0);
	i = 1;
	if (s[i] == '\0')
		return (0);
	while (s[i] == 'n')
		i++;
	return (s[i] == '\0');
}

void	ft_echo(t_token *tokens, t_shell *shell)
{
	int		flag;
	int		first;
	t_token	*cur;

	(void)shell;
	flag = 1;
	first = 1;
	cur = tokens->next;
	while (cur && cur->type == WORD && is_valid_n_flag(cur->value))
	{
		flag = 0;
		cur = cur->next;
	}
	while (cur)
	{
		if (!first)
			write(1, " ", 1);
		write(1, cur->value, ft_strlen(cur->value));
		first = 0;
		cur = cur->next;
	}
	if (flag)
		write(1, "\n", 1);
	return ;
}
