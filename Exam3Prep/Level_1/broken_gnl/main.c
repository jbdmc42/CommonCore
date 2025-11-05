/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:04:23 by joaobarb          #+#    #+#             */
/*   Updated: 2025/11/05 16:17:09 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "broken_gnl.h"							// defining the header
#include <stdio.h>								// stdio.h used only for printing and test purposes (printf, not according to the norm)

char	*ft_strdup(char *str)					// default strdup
{
	char	*new_str;							// defining new string which will be returned in the end
	int		i;									// counter for the string

	i = 0;
	while (str[i] != '\0')						// getting the size of the string for the memory allocation
		i++;										// the size of the string will be the number of characters (i) plus 1 for the null character
	new_str = (char *)malloc(sizeof(char) * (i + 1));	// allocating memory based on the size
	if (!new_str)								// protection to secure the function
		return (NULL);
	i = -1;										// defines the counter to -1 so we can start the incrementation correctly on pos = 0
	while (str[++i] != '\0')					// while the string pos is not a null character
		new_str[i] = str[i];					// copying the string to the new string
	new_str[i] = '\0';							// giving the new string a final new character
	return (new_str);							// returns the new string
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];		// defining the buffer based on the buffer size defined on the header (for instance: 42) that will store the characters to print
	static int		buffer_pos;					// buffer position/counter to set the position where we stop reading to use on the next call as a starting position
	static int		buffer_read;				// size read from the fd to check if we're on the right position to keep reading
	char			line[65536];				// current line being read to dup with strdup
	int				i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)				// protection to secure the function
		return (NULL);
	while (1)									// infinite loop to keep reading
	{
		if (buffer_pos >= buffer_read)			// if the position on the buffer is bigger or the same as the size read from the fd (aka 1st call)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);	// the size read will become the read from the fd
			buffer_pos = 0;									// the position on the buffer will be 0 (because we're starting to read)
			if (buffer_read <= 0)							// if the size read is 0 or less, than there's nothing to read, so we skip to giving the line a null character and return it using the strdup
				break ;										// ends the loop cicle
		}
		line[i++] = buffer[buffer_pos++];		// else, the current line character (starting on 0) will be the same character as the current character in the fd at buffer position
		if (buffer[buffer_pos - 1] == '\n')		// if the fd character at buffer position - 1 (which is the position where we are currently reading since we increment it on the line before) is a '\n', we end the cicle, as the line ended
			break ;											// ends the loop cicle
	}
	line[i] = '\0';								// the file ended, there's nothing more to read, so we give it a null character to end the buffer.
	if (i == 0)									// if the only thing we have on the line is a NULL, we don't need to use the strdup, we only need to return a null character
		return (NULL);
	return (ft_strdup(line));					// returns a dupped string of the what the line has inside it
}

int		main(int argc, char **argv)				// function is not according to the norm, only for testing purposes/exam
{
	int		fd;									// defining the file descriptor
	char	*line;								// defining the line which will be printed

	if (argc != 2)								// protection to secure the function and the program
	{
		write(1, "Error\n", 6);					// error log
		return (1);								// ends with error
	}
	fd = open(argv[1], O_RDONLY);				// define the file descriptor which we're going to read from
	while ((line = get_next_line(fd)))			// while the line from gnl is valid
	{
		printf("%s", line);						// print the current line (current characters in the buffer)
		free(line);								// free the line for the next gnl call
	}
	return (0);									// ends normally
}


/* ************** */
/*     NOTICE     */
/* ************** */

/*
**
** This program cannot be used as the default gnl for the 42 project,
** as it is not according to the norm. Notice that you can use it
** on the exam or any project with no norm restrictions.
**
*/
