/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:51:11 by jbdmc             #+#    #+#             */
/*   Updated: 2025/12/08 11:53:49 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	found_echo(char *line, size_t i, int *flag)
{
	if ((ft_strncmp(&line[i], "echo", 4) == 0) && (line[i + 4] == ' ' ||
		line[i + 4] == '\t') && (line[i + 5] == '-') && (line[i + 6] == 'n') &&
		(line [i + 7] == 'n' || line[i + 7] == ' ' || line[i + 7] == '\t' ||
		line[i + 7] == '\0'))
	{
		*flag = 1;
		return (1);
	}
	else if ((ft_strncmp(&line[i], "echo", 4) == 0) && (line[i + 4] == '\0' ||
		line[i + 4] == ' ' || line[i + 4] == '\t'))
		return (1);
	return (0);
}

void	ft_echo(char *line, size_t i, int *flag)
{
	if (!*flag)
	{
		i += 5;
		printf("%s\n", &line[i]);
	}	
	else
	{
		i += 6;
		while (line[i] == 'n' || line[i] == ' ' || line[i] == '\t' ||
			line[i] == '-')
			i++;
		while (line[i] != '\0')
		{
			write(1, &line[i], 1);
			i++;
		}
	}
}
