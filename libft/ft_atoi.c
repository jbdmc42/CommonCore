/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:52:13 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/14 13:52:14 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	val;

	i = 0;
	res = 0;
	val = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			val *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = str[i] - '0' + res * 10;
		i++;
	}
	return (res * val);
}

/* int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc >= 2)
	{
		while (i < argc)
		{
			printf("--> %d\n", ft_atoi(argv[i]));
			i++;
		}
		return (0);
	}
	printf("Too few, non-acceptable or incorrect arguments.\n");
	return (0);
} */