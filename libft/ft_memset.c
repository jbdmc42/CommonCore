/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:50:35 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/14 13:50:35 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/* int	main(void)
{
	char	arr[20];
	int		i;

	i = 0;
	ft_memset(arr, 65, 10);
	
	while (i < 20)
	{
		write(1, &arr[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
} */