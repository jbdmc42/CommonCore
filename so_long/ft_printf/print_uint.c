/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:14:36 by joaobarb          #+#    #+#             */
/*   Updated: 2025/05/06 10:15:04 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_uint(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += print_uint(n / 10);
	n = n % 10 + '0';
	write(1, &n, 1);
	count++;
	return (count);
}
