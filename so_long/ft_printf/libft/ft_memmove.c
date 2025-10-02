/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:50:45 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/14 15:40:40 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*psrc;
	unsigned char	*pdst;

	if (!dst && !src)
		return (NULL);
	psrc = (unsigned char *)src;
	pdst = (unsigned char *)dst;
	if (pdst > psrc && pdst < psrc + len)
	{
		while (len--)
			pdst[len] = psrc[len];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			pdst[i] = psrc[i];
			i++;
		}
	}
	return (dst);
}

/* int	main(void)
{
	char	src[20] = "Hello World!";
	char	dst[20];
	int		i;

	i = 0;
	ft_memcpy(dst, src, 5);
	while (i < 20)
	{
		write(1, &dst[i], 1);
		i++;
	}
	write(1, "\n", 1);
} */