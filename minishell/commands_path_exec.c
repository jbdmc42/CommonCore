/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_path_exec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:30:00 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:08:37 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

static int	test_path_segment(char *start, char *end, char *full_path,
		char *command)
{
	size_t	len;

	len = end - start;
	if (len == 0 || len >= PATH_MAX - 2)
		return (0);
	ft_memcpy(full_path, start, len);
	full_path[len] = '/';
	ft_memcpy(full_path + len + 1, command, ft_strlen(command) + 1);
	if (access(full_path, X_OK) == 0)
		return (1);
	return (0);
}

static int	search_in_path_loop(char *start, char *full_path,
		char *command, char **found_start)
{
	char	*end;

	while (start && *start)
	{
		end = start;
		while (*end && *end != ':')
			end++;
		if (test_path_segment(start, end, full_path, command))
		{
			*found_start = end;
			return (1);
		}
		if (*end == ':')
			start = end + 1;
		else
			start = end;
	}
	return (0);
}

static int	search_in_path_dirs(char *path_copy, char *full_path,
		char *command, int *found)
{
	char	*start;
	char	*found_pos;

	start = path_copy;
	found_pos = NULL;
	if (search_in_path_loop(start, full_path, command, &found_pos))
	{
		*found = 1;
		return (0);
	}
	*found = 0;
	return (-1);
}

int	try_exec_in_path(char *path_copy, char *command, t_exec_ctx *ctx)
{
	char	full_path[PATH_MAX];
	int		found;

	if (search_in_path_dirs(path_copy, full_path, command, &found) == -1
		&& !found)
		return (-1);
	return (exec_found_command(full_path, command, ctx));
}
