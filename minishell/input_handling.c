/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 10:44:02 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:08:37 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**  read_input function helper: checks for an empty line and returns a boolean.
*/
int	ft_strisspace(char *line)
{
	size_t	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (line[i] == '\0');
}

/*
**  reads the line and checks for initial spaces to skip, and empty line or 
** an EOF.
**  In the end, returns the line from the prompt.
*/
char	*read_input(void)
{
	size_t	i;
	char	*line;

	i = 0;
	line = readline(PROMPT);
	if (!line)
		return (NULL);
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!ft_strisspace(line))
		add_history(line);
	return (line);
}
