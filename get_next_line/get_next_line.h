/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:53:22 by joaobarb          #+#    #+#             */
/*   Updated: 2025/05/14 02:17:23 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

// Struct prototype	
typedef struct s_list
{
	int				fd;
	char			*stash;
	struct s_list	*next;
}	t_list;
	
// Main function prototype

char	*get_next_line(int fd);

// Other functions prototypes

// dealloc

void	dealloc(t_list **head, t_list *clean_node, char *buf);

//	find_lst_node

t_list	*find_lst_node(t_list *head);

// ft_strcpy

void	ft_strcpy(t_list *head, char *str);

// ft_strlen

int	ft_strlen(t_list *head);

// append

void	append(t_list **head, char *buf);

#endif