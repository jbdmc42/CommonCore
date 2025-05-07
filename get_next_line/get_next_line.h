/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:53:22 by joaobarb          #+#    #+#             */
/*   Updated: 2025/05/07 15:54:40 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include <stdlib.h>
# include <unistd.h>

// Functions prototypes

// get_next_line

char	*get_next_line(int fd);

// ft_strchr

char	*ft_strchr(const char *s, int c);

// ft_strjoin_free

char	*ft_strjoin(char *s1, char *s2);

// ft_strdup

char	*ft_strdup(const char *s);

// extract_line

char	*extract_line(char **rest);

// ft_strlen

size_t	ft_strlen(const char *s);

#endif