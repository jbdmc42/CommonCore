/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:07:34 by joaobarb          #+#    #+#             */
/*   Updated: 2025/05/06 10:16:36 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += check_flagstype(&format[i], args);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

/* int main(void)
{
	ft_printf("String normal: %s\n", "Hello, 42!");
	ft_printf("String vazia: %s\n", "");
	ft_printf("String NULL: %s\n", NULL);
	ft_printf("Char A: |%c|\n", 'A');
	ft_printf("Char espaço: |%c|\n", ' ');
	ft_printf("Char nulo: |%c|\n", '\0');
	ft_printf("Número positivo (d): %d\n", 42);
	ft_printf("Número negativo (d): %d\n", -42);
	ft_printf("Zero (d): %d\n", 0);
	ft_printf("Máximo int (d): %d\n", 2147483647);
	ft_printf("Mínimo int (d): %d\n", -2147483648);
	ft_printf("Número com %%i: %i\n", 123);
	ft_printf("Unsigned normal: %u\n", 42);
	ft_printf("Unsigned zero: %u\n", 0);
	ft_printf("Unsigned max: %u\n", 4294967295U);
	ft_printf("Hex minúsculo: %x\n", 255);
	ft_printf("Hex maiúsculo: %X\n", 255);
	ft_printf("Hex zero: %x\n", 0);
	ft_printf("Hex grande: %x\n", 305441741);
	int x = 42;
	int *ptr = &x;
	ft_printf("Ponteiro válido: %p\n", ptr);
	ft_printf("Ponteiro NULL: %p\n", NULL);
	ft_printf("Percentagem: %%\n");
	ft_printf("Texto com %% no meio: ABC %% DEF\n");
	ft_printf("Char: %c, Str: %s, Int: %d, Hex: %x, Ptr: 
	%p, %%\n", 'Z', "Test", -123, 3735928559U, &x);
	return (0);
} */
