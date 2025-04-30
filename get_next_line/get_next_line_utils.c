/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:58:35 by jbdmc             #+#    #+#             */
/*   Updated: 2025/04/30 11:24:54 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// ft_strlen

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// ft_strchr

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	return (NULL);
}

// ft_strjoin + aux

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

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	i;	
	char			*ns;
	unsigned int	s1len;
	unsigned int	s2len;

	if (!s1 && !s2)
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
	free(s1);
	return (ns);
}

// ft_substr + aux

static char	*ft_strdup(const char *s)
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