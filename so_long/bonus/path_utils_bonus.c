/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 01:45:40 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/16 14:39:44 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_fd(int fd)
{
	if (fd < 0)
	{
		ft_printf("Error\n \xE2\x88\x9F invalid map path\n");
		return (1);
	}
	return (0);
}

char	*extract_map_name(const char *filepath)
{
	char	*name_start;
	char	*dot;
	char	*result;

	if (!filepath)
		return (NULL);
	name_start = ft_strrchr(filepath, '/');
	if (name_start)
		name_start++;
	else
		name_start = (char *)filepath;
	dot = ft_strrchr(name_start, '.');
	if (dot)
		result = ft_substr(name_start, 0, dot - name_start);
	else
		result = ft_strdup(name_start);
	if (!result)
	{
		ft_printf("Error\n \xE2\x88\x9F failed to allocate map name\n");
		return (NULL);
	}
	return (result);
}
