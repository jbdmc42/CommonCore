/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:11:33 by jbdmc             #+#    #+#             */
/*   Updated: 2025/11/05 17:40:12 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILTER_H
# define FILTER_H									// header protection

/*
**
** Macros can also be defined as follows, for security:
**		#ifndef MACRO
**		# define MACRO <value>
**		#endif
**
*/

# define BUFFER_SIZE 42								// BUFFER_SIZE value atribution as a macro
# include <unistd.h>								// libraries

int		ft_strlen(char *str);						// there's no actual need to declare this function, as it can also be a static function
void	ft_filter(char *haystack, char *needle);


#endif