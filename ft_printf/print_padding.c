/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:13:34 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/26 14:16:58 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_padding(char c, int times)
{
	int	count;

	count = 0;
	while (times-- > 0)
	{
		ft_putchar_fd(c, 1);
		count++;
	}
	return (count);
}
