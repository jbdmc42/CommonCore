/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:50:10 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/14 14:04:04 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "libft.h"

static char	**copy_words(const char *s, char c, char **arr, size_t wnum)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i] && j < wnum)
	{
		start = i;
		while (s[i] && s[i] != c)
			i++;
		arr[j] = malloc((i - start + 1) * sizeof(char));
		if (!arr[j])
			return (NULL);
		ft_strlcpy(arr[j], &s[start], i - start + 1);
		j++;
		while (s[i] && s[i] == c)
			i++;
	}
	arr[j] = NULL;
	return (arr);
}

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	wnum;

	i = 0;
	wnum = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
		wnum++;
	}
	return (wnum);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	size_t	arrlen;

	arrlen = count_words(s, c);
	arr = (char **)malloc((arrlen + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr = copy_words(s, c, arr, arrlen);
	if (!arr)
		return (NULL);
	return (arr);
}

/* int	main(int argc, char *argv[])
{
	char	**result;
	int		i;

	i = 0;
	if (argc == 3)
	{
		result = ft_split(argv[1], argv[2][0]);
		while (result[i])
		{
			printf("Word %d: %s\n", i, result[i]);
			free(result[i]);
			i++;
		}
	}
	return (0);
} */