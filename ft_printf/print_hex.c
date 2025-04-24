/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:52:10 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/24 15:49:31 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_hex(unsigned long n, int uppercase)
{
	char	*base;

	if (uppercase)
		base = "0123456789ABCDEF";
	else 
		base = "0123456789abcdef";
	if (n >= 16)
		ft_putnbr_hex(n / 16, uppercase);
	ft_putchar_fd(base[n % 16], 1);
}

int	print_hex(unsigned int n, int uppercase, t_flags flags)
{
	
}