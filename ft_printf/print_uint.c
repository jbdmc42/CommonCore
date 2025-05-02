/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:35:13 by jbdmc             #+#    #+#             */
/*   Updated: 2025/05/02 12:40:16 by jbdmc            ###   ########.fr       */
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