/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_second.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 11:37:11 by jbdmc             #+#    #+#             */
/*   Updated: 2025/07/19 13:11:03 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(char **map, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < height)
	{
		if (i == 0 || i == height - 1)
		{
			j = 0;
			while (j < width)
				if (map[i][j++] != '1')
					return (0);
		}
		else
		{
			if (map[i][0] != '1' || map[i][width - 1] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}
