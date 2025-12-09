/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 10:44:02 by jbdmc             #+#    #+#             */
/*   Updated: 2025/12/08 10:44:42 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

// input reading function
char	*read_input(void)
{
	size_t	i;
	char	*line;

	i = 0;
	line = readline(PROMPT);
	if (!line)																	// case: EOF / Ctrl - D
		return NULL;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))						// skip initial spaces
		i++;
	if ((ft_strncmp(&line[i], "exit", 4) == 0) &&								// exit command
		(line[i + 4] == '\0' ||	line[i + 4] == ' ' || line[i + 4] == '\t'))		// if we find exit with a space, null character or tab after, we exit the program
		return NULL;
	if (!ft_strisspace(line))													// case: line is not empty (has >0 chars), adds to the history
		add_history(line);
	return (line);
}

