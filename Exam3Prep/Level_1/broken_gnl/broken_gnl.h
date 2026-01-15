/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broken_gnl.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:15:27 by joaobarb          #+#    #+#             */
/*   Updated: 2025/11/05 17:39:21 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BROKEN_GNL_H
# define BROKEN_GNL_H				// header protection

/*
**
** Macros can also be defined as follows, for security:
**		#ifndef MACRO
**		# define MACRO <value>
**		#endif
**
*/

# define BUFFER_SIZE 42				// BUFFER_SIZE value atribution as a macro
# include <unistd.h>				// libraries
# include <stdlib.h> 
# include <fcntl.h>

char	*ft_strdup(char *str);		// there's no actual need to declare this function, as it can also be a static function
char	*get_next_line(int fd);

#endif