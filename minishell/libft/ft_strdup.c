/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:49:50 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/14 15:12:18 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		i;
	size_t		len;
	char		*dup;

	i = 0;
	len = ft_strlen(s);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/* int	main(int argc, char *argv[])
{
	if (argc == 2)
		printf("Result --> %s", ft_strdup(argv[1]));
	return (0);
} */