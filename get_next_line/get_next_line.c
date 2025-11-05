/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:53:19 by joaobarb          #+#    #+#             */
/*   Updated: 2025/06/17 14:35:43 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static char	*extract_line(char *stash)
{
	int		len;
	char	*line;

	if (!stash || !stash[0])
		return (NULL);
	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	line = gnl_substr(stash, 0, len);
	return (line);
}

static char	*clean_stash(char *stash)
{
	int		i;
	char	*new_stash;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	new_stash = gnl_strdup(&stash[i + 1]);
	return (free(stash), new_stash);
}

static char	*read_and_stash(int fd, char *stash)
{
	char	*buf;
	int		char_read;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(stash), NULL);
	char_read = 1;
	while (!gnl_strchr(stash, '\n') && char_read > 0)
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read < 0)
			return (free(buf), free(stash), NULL);
		buf[char_read] = '\0';
		stash = gnl_strjoin(stash, buf);
	}
	return (free(buf), stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}

/* int	main(void)
{
	int		fd;
	char	*line;
	int		lines;

	lines = 1;
	fd = open("test.txt", O_RDONLY);

	while ((line = get_next_line(fd)))
	{
		printf("%d->%s\n", lines++, line);
		free(line);
	}
	return (0);
} */
