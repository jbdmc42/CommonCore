/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:53:19 by joaobarb          #+#    #+#             */
/*   Updated: 2025/05/16 15:40:51 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static int	found_newline(t_list *head)
{
	int	i;

	while (head)
	{
		i = 0;
		while (head->stash[i])
		{
			if (head->stash[i] == '\n')
				return (1);
			i++;
		}
		head = head->next;
	}
	return (0);
}

static char	*get_line(t_list *head)
{
	int		str_len;
	char	*next_str;

	if (!head)
		return (NULL);
	str_len = ft_strlen(head);
	next_str = malloc(str_len + 1);
	if (!next_str)
		return (NULL);
	ft_strcpy(head, next_str);
	return (next_str);
}

static t_list	*get_node(t_list **head, int fd)
{
	int		char_read;
	char	*buf;

	while (!found_newline(*head))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buf);
			return (*head);
		}
		buf[char_read] = '\0';
		append(head, buf);
	}
	return (*head);
}

static void	remove_node(t_list **head)
{
	t_list	*lst_node;
	t_list	*clean_node;
	int		i;
	int		j;
	char	*buf;

	if (!head || !*head || !(lst_node = find_lst_node(*head)))
		return ;
	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (!buf || !clean_node)
		return ;
	lst_node = find_lst_node(*head);
	i = 0;
	j = 0;
	while (lst_node->stash[i] && lst_node->stash[i] != '\n')
		i++;
	if (lst_node->stash[i] == '\n')
		i++;
	while (lst_node->stash[i])
		buf[j++] = lst_node->stash[i++];
	buf[j] = '\0';
	clean_node->stash = buf;
	clean_node->next = NULL;
	dealloc(head, clean_node, buf);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	get_node(&head, fd);
	if (!head)
		return (NULL);
	line = get_line(head);
	remove_node(&head);
	return (line);
}

/* int	main(void)
{
	int		fd;
	char	*line;
	int		lines;

	lines = 1;
	fd = open("test.txt", O_RDONLY);
	fd = -1;

	while ((line = get_next_line(fd)))
		printf("%d->%s\n", lines++, line);
	return (0);
} */