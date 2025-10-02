/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 22:23:36 by jbdmc             #+#    #+#             */
/*   Updated: 2025/07/13 12:27:33 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strjoin_and_free(char *s1, char c)
{
	int		len;
	char	*new;
	int		i;

	len = 0;
	i = 0;
	while (s1 && s1[len])
		len++;
	new = malloc(len + 2);
	if (!new)
		return (free(s1), NULL);
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i++] = c;
	new[i] = '\0';
	free(s1);
	return (new);
}

char	*ft_gnl(int fd)
{
	char	*line;
	char	buf;
	int		read_ret;

	line = NULL;
	if (fd < 0)
		return (NULL);
	read_ret = read(fd, &buf, 1);
	while (read_ret > 0)
	{
		line = ft_strjoin_and_free(line, buf);
		if (!line)
			return (NULL);
		if (buf == '\n')
			break ;
		read_ret = read(fd, &buf, 1);
	}
	if (read_ret <= 0 && !line)
		return (NULL);
	return (line);
}
