/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:38:54 by jbdmc             #+#    #+#             */
/*   Updated: 2025/05/02 12:40:31 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_ptr_recursive(unsigned long n)
{
	char	*base = "0123456789abcdef";
	int		count;

	count = 0;
	if (n >= 16)
		count += print_ptr_recursive(n / 16);
	write(1, &base[n % 16], 1);
	return (count + 1);
}

int	print_ptr(void *ptr)
{
	unsigned long	addr;
	int				count;

	if (!ptr)
		return (write(1, "(nil)", 5));
	addr = (unsigned long)ptr;
	write(1, "0x", 2);
	count = print_ptr_recursive(addr);
	return (count + 2);
}
