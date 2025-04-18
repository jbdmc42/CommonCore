/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:49:45 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/18 09:34:36 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "libft.h"

static unsigned int	joinstrings(char *ns, const char *s, unsigned int i)
{
	unsigned int	j;

	j = 0;
	while (s[j] != '\0')
	{
		ns[i] = s[j];
		i++;
		j++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;	
	char			*ns;
	unsigned int	s1len;
	unsigned int	s2len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ns = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (!ns)
		return (NULL);
	i = 0;
	i = joinstrings(ns, s1, i);
	i = joinstrings(ns, s2, i);
	ns[i] = '\0';
	return (ns);
}

/* int	main(int argc, char *argv[])
{
	if (argc == 3)
		printf("Result --> %s", ft_strjoin(argv[1], argv[2]));
	return (0);
} */