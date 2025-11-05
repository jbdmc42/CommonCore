/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broken_gnl.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:15:27 by joaobarb          #+#    #+#             */
/*   Updated: 2025/11/05 15:53:49 by joaobarb         ###   ########.fr       */
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

char	*ft_strdup(char *str);		// there's not actual need to declare this function, as it can also be a static function
char	*get_next_line(int fd);

#endif