#include "ft_printf.h"

int	print_char(char c, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus)
	{
		ft_putchar_fd(c, 1);
		count++;
		while (count < flags.width)
		{
			ft_putchar_fd(' ', 1);
			count++;
		}
	}
	else
	{
		while (count < flags.width - 1)
		{
			ft_putchar_fd(' ', 1);
			count++;
		}
		ft_putchar_fd(c, 1);
		count++;
	}
	return (count);
}
