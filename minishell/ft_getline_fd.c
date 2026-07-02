/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:07:30 by joaobarb          #+#    #+#             */
/*   Updated: 2026/06/02 17:08:37 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>

static int	init_linebuf(char **lineptr, size_t *n)
{
	if (!*lineptr)
	{
		*lineptr = malloc(1);
		if (!*lineptr)
			return (-1);
		(*lineptr)[0] = '\0';
		*n = 1;
	}
	return (0);
}

static int	ensure_capacity(char **lineptr, size_t *n, ssize_t total,
		ssize_t add)
{
	char	*newbuf;

	if ((size_t)(total + add + 1) > *n)
	{
		newbuf = malloc(total + add + 1);
		if (!newbuf)
			return (-1);
		ft_memcpy(newbuf, *lineptr, total);
		free(*lineptr);
		*lineptr = newbuf;
		*n = total + add + 1;
	}
	return (0);
}

static ssize_t	process_read_loop(int fd, char **lineptr, size_t *n)
{
	ssize_t	total;
	ssize_t	r;
	char	buf[1];

	total = 0;
	while (1)
	{
		r = read(fd, buf, 1);
		if (r <= 0)
			break ;
		if (ensure_capacity(lineptr, n, total, r) == -1)
			return (-1);
		ft_memcpy(*lineptr + total, buf, r);
		total += r;
		(*lineptr)[total] = '\0';
		if ((*lineptr)[total - 1] == '\n')
			break ;
	}
	if (r == -1)
		return (-1);
	if (total == 0)
		return (-1);
	return (total);
}

ssize_t	ft_getline_fd(char **lineptr, size_t *n, int fd)
{
	if (!lineptr || !n || fd < 0)
		return (-1);
	if (init_linebuf(lineptr, n) == -1)
		return (-1);
	return (process_read_loop(fd, lineptr, n));
}
