/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:43:45 by jbdmc             #+#    #+#             */
/*   Updated: 2025/04/30 11:25:09 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

// Function Prototypes

// get_next_line

char	*get_next_line(int fd);

// ft_strlen

size_t	ft_strlen(const char *s);

// ft_strjoin

char	*ft_strjoin(char *s1, char *s2);

// ft_strchr

char	*ft_strchr(const char *s, int c);

// ft_substr

char	*ft_substr(const char *s, unsigned int start, size_t len);

#endif