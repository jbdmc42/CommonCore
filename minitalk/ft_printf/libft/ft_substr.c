/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:48:57 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/14 17:00:14 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "libft.h"

static void	copy_str(const char *s, unsigned int start, char *dup, size_t len)
{
	unsigned int	j;
	unsigned int	i;

	i = start;
	j = 0;
	while (s[i] != '\0' && j < len)
	{
		dup[j] = s[i];
		i++;
		j++;
	}
	dup[j] = '\0';
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*dup;

	if (!s || !len || ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
	{
		dup[0] = '\0';
		return (dup);
	}
	i = start;
	copy_str(s, i, dup, len);
	return (dup);
}

/* int	main(int argc, char *argv[])
{
	if (argc == 2)
		printf("Result --> %s", ft_substr(argv[1], 2, 3));
	return (0);
} */

/* int	main(void)
{
	printf("Result --> %s", ft_substr("abcdef", 2, 3));
	return (0);
} */