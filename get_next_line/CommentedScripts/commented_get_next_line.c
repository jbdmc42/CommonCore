/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commented_get_next_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:53:19 by joaobarb          #+#    #+#             */
/*   Updated: 2025/05/16 15:42:04 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commented_get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static int	found_newline(t_list *head) // this function works similar to ft_strchr, finding a '\n' in the buffer
{
	int	i; // counter for the current buffer character

	while (head) // while the list is not empty
	{
		i = 0; // the counter starts in 0
		while (head->stash[i]) // while the current character of the current buffer is not a '\0'
		{
			if (head->stash[i] == '\n') // if the current character of the current buffer is a '\n'
				return (1); // positive return
			i++; // else, skips the character to the next one
		}
		head = head->next; // skips to the next node on the list to continue the verification
	}
	return (0); // if it reaches the end without returning a positive value, it returns a negative value 
}

static char	*get_line(t_list *head) // this function extracts a line from the main buffer
{
	int		str_len; // str_len is used to extract the amount of characters needed
	char	*next_str; // a temporary buffer that will receive the line extracted

	if (!head) // if the list is empty
		return (NULL); // NULL return
	str_len = ft_strlen(head); // str_len equals the size of the main buffer
	next_str = malloc(str_len + 1); // allocation of the memory to the buffer with the size str_len + 1 in order to have space for all characters plus the '\0'
	if (!next_str) // safety verification
		return (NULL); // NULL return
	ft_strcpy(head, next_str); // this function will copy the line present on the current node to the buffer created
	return (next_str); // buffer return
}

static t_list	*get_node(t_list **head, int fd) // this fucntion will get the current node
{
	int		char_read; // amount of characters already read from the fd
	char	*buf; // buffer that will store the line to be returned

	while (!found_newline(*head)) // while the main buffer has no '\n' -> found_newline is similar to the ft_strchr function
	{
		buf = malloc(BUFFER_SIZE + 1); // we allocate memory for the temporary buffer using BUFFER_SIZE that is our maximum of characters to read in each all plus one to add the '\0' and turn the buffer into a valid and readable string
		if (!buf) // safety verification
			return (NULL); // NULL return if the allocation fails
		char_read = read(fd, buf, BUFFER_SIZE); // chars_read will be the number of characters in the temporary buffer "buf"
		if (char_read <= 0) // if the number of chars read is smaller or equal to 0, we free the temporary buffer "buf" to prevent leaks and then we return the main buffer empty -> this will make the get_next_line function return NULL on "if (!head)"
		{
			free(buf); // freeing the temporary buffer to prevent leaks
			return (*head); // empty head return
		}
		buf[char_read] = '\0'; // if the allocation works and we do read characters from the temporary buffer, we give the '\0' character to the end of buf so it becomes a valid and readable string
		append(head, buf); // the function append will
	}
	return (*head); // head with the current line return
}

static void	remove_node(t_list **head) // this function will clear the already read data from the list
{
	t_list	*lst_node; // the last node on the list
	t_list	*clean_node; // a clean node
	int		i; // a counter for the clean node
	int		j; // a counter for the current node
	char	*buf; // a buffer for the current line on the node

	if (!head || !*head || !(lst_node = find_lst_node(*head))) // if the head node or the list are empty or the last node does not equal the last node on the list
		return ; // empty return
	buf = malloc(BUFFER_SIZE + 1); // memory allocation for the buffer for the current line on the node
	clean_node = malloc(sizeof(t_list)); // memory allocation for the clean node based on the t_list node size
	if (!buf || !clean_node) // double safety verification
		return ; // empty return
	lst_node = find_lst_node(*head); // the last node uses this function to the find the last node on the list
	i = 0; // initializes the counter at 0
	j = 0; // initializes the counter at 0
	while (lst_node->stash[i] && lst_node->stash[i] != '\n') // while the current character in the line stored in the current node is not a '\0' nor a '\n'
		i++; // skips the current character
	if (lst_node->stash[i] == '\n') // if the current character in the line stored in the current node is a '\n'
		i++; // skips the current character
	while (lst_node->stash[i]) // while the current character in the line stored in the current node is a '\0'
		buf[j++] = lst_node->stash[i++]; // the first character on the temporary buffer "buf" will become the current character on the line stored in the current node and so on
	buf[j] = '\0'; // puts a '\0' in the end of the temporary buffer to make it a valid and readable string
	clean_node->stash = buf; // the clean_node becomes the temporary buffer
	clean_node->next = NULL; // the node after becomes NULL
	dealloc(head, clean_node, buf); // we dealloc the memory to finish the clearence
}

char	*get_next_line(int fd) // get_next_line head fuction
{
	static t_list	*head; // head is the tied list pointer -> stores the reading state -> keeps the read but not returned data, organized by fd -> each node contains information from one fd, including the not yet processed data
	char			*line; // pointer to the line that will be returned to print on the main -> stores the line extracted from head -> makes it possible to clear head without losing trace of the line to be returned

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024) // if fd is not 0, 1, 2, 3,... or BUFFER_SIZE is not 1 or more or fd is 1024 or more, we return NULL because we can't do anything
		return (NULL); // NULL return
	get_node(&head, fd); // the funtion get_node will guarantee that head has at least one returnable line -> checks if there is at least one line that has a '\n' or a '\0'
	if (!head) // if head comes back from get_node as a non-usable value, we return NULL
		return (NULL); // NULL return
	line = get_line(head); // the function get_line will extract the current line from head and pass it to line
	remove_node(&head); // the function remove_node will
	return (line); // line return to the main function
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