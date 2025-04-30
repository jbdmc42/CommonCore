/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:45:19 by jbdmc             #+#    #+#             */
/*   Updated: 2025/04/30 11:22:58 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

static char	*read_and_store(int fd, char *storage)
{
	char	*buffer;
	ssize_t	bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(storage, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			if (storage)
				free(storage);
			return (NULL);
		}
		buffer[bytes] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free(buffer);
	return (storage);
}

static char	*extract_line(char *storage)
{
	size_t	i;
	char	*line;

	if (!storage || !storage[0])
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	line = ft_substr(storage, 0, storage[i] == '\n' ? i + 1 : i);
	return (line);
}

static char	*remove_extracted(char *storage)
{
	size_t	i;
	char	*rest;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	rest = ft_substr(storage, i + 1, ft_strlen(storage) - i - 1);
	free(storage);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char *storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = read_and_store(fd, storage);
	if (!storage)
		return (NULL);
	line = extract_line(storage);
	storage = remove_extracted(storage);
	return (line);
}

int		main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening the file.");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Read: %s", line);
		free(line);
	}
	close(fd);
	return (0);
}