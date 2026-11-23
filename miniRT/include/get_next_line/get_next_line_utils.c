/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:53:14 by joaobarb          #+#    #+#             */
/*   Updated: 2025/06/17 14:39:14 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return (&s[i]);
	return (NULL);
}

char	*gnl_strdup(char *s)
{
	int		i;
	char	*copy;

	if (!s)
		return (NULL);
	copy = malloc(gnl_strlen(s) + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*joined;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (gnl_strdup(s2));
	if (!s2)
	{
		joined = gnl_strdup(s1);
		return (free(s1), joined);
	}
	joined = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (!joined)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		joined[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		joined[j++] = s2[i++];
	joined[j] = '\0';
	return (free(s1), joined);
}

char	*gnl_substr(char *s, int start, int len)
{
	char	*sub;
	int		i;

	if (!s || start >= gnl_strlen(s))
		return (gnl_strdup(""));
	if (len > gnl_strlen(s + start))
		len = gnl_strlen(s + start);
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
