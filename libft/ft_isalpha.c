/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:51:14 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/14 13:51:14 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "libft.h"

int	ft_isalpha(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	else if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}

/* int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc >= 2)
	{
		while (i < argc)
		{
			printf("--> %d\n", ft_isalpha(ft_atoi(argv[i])));
			i++;
		}
		return (0);
	}
	printf("Too few, non-acceptable or incorrect arguments.\n");
	return (0);
} */
