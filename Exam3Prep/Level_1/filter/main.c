/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:56:56 by jbdmc             #+#    #+#             */
/*   Updated: 2025/11/12 09:12:51 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filter.h"						// defining the header

int	ft_strlen(char *str)				// default strlen
{
	int i;								// defining the counter

	i = 0;
	while (str[i])						// while the string is valid
		i++;								// add 1 to the len
	return (i);							// returns the len
}

void	ft_filter(char *haystack, char *needle)		// main filter function
{
	int	len;							// defining the len
	int	i;								// defining the counter
	int	h;								// defining the adaptative len flag
	int	l;								// defining the secondary counter

	len = ft_strlen(needle);			// len value will be the length of the needle
	i = 0;
	while (haystack[i])					// while the haystack is valid
	{
		h = 0;							// the flag starts at 0 as we have to measure each time we find that the needle and the haystack are corresponding to each other
		while (needle[h] && haystack[i + h] == needle[h])	// while they correspond
			h++;											// we skip those positions
		if (h == len)					// after skipping those, if the flag equals the value of the len, it means we found the needle on the haystack, and that's why we need an adaptative flag
		{
			l = 0;						// initialize the secondary counter as 0, as we want to right '*' for the length of the needle
			while (l < len)				// while the counter is smaller than the needle size
			{
				write(1, "*", 1);			// write the filter
				l++;						// skip to the next position of the needle
			}
			i += h;						// the initial counter will equal its value plus the value of characters skipped
		}
		else							// else, we didn't find the whole needle, so we don't filter, we just normally write the string down
		{
			write(1, &haystack[i], 1);		// writes down the current character of the string
			i++;							// skips to the next position of the haystack
		}
	}
}

int	main(int argc, char **argv)
{
	char	line[65536];				// 64kb of static memory for reading
	int		bytes_read;					// number of bytes read from 
	int		i;							// counter for

	bytes_read = 1;						// at least one for the null character
	i = 0;
	if (argc != 2 || !argv[1][0])		// if the number of arguments or the the first position if the first string is not valid
		return (1);						// ends with an error
	while (bytes_read > 0)				// while the number of bytes read is positive (so there's something to read from, prevention for security)
	{
		bytes_read = read(0, &line[i], BUFFER_SIZE);	// bytes read will value will become the number of bytes read from the line with the limitor BUFFER_SIZE defined on the header
		if (bytes_read < 0)				// if the number of bytes read becomes less than 0, there's an error, if it becomes 0, that's an EOF
		{
			write(2, "Error\n", 6);			// prints the error message
			return (1);						// ends with an error
		}
		i += bytes_read;				// the position to keep reading from becomes the current position plus the bytes read on the last read
	}
	ft_filter(line, argv[1]);			// calls the filter function with the line to filter and the argument
	return (0);							// ends normally
}

/* ************** */
/*     NOTICE     */
/* ************** */

/*
**
** This program cannot be used as the default filter for a 42 project,
** as it is not according to the norm. Notice that you can use it
** on the exam or any project with no norm restrictions.
**
*/