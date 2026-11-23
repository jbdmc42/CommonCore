/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:15:42 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/14 15:49:18 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "libft.h"

static char	*writenum(char *num, size_t i, int n)
{
	while (n > 0)
	{
		num[--i] = (n % 10) + '0';
		n /= 10;
	}
	return (num);
}

static void	*allocation(char *num, size_t counter)
{
	num = (char *)malloc((counter + 1) * sizeof(char));
	if (!num)
		return (NULL);
	num[counter] = '\0';
	return (num);
}

static size_t	count_pos(int n)
{
	size_t	counter;

	counter = 0;
	if (n <= 0)
		counter++;
	while (n)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char			*num;
	size_t			i;
	unsigned int	is_negative;

	num = NULL;
	is_negative = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = count_pos(n);
	num = allocation(num, i);
	if (!num)
		return (NULL);
	if (n == 0)
		num[0] = '0';
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	num = writenum(num, i, n);
	if (is_negative)
		num[0] = '-';
	return (num);
}

/* int	main(void)
{
	char *arr;
	printf("Result --> %s\n", arr = ft_itoa(23894));
	return (0);
} */