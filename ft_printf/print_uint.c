#include "ft_printf.h"

static int	nbr_len(unsigned int n)
{
	int	len;

	len = (n == 0);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	print_padding(char c, int times)
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

static int	print_sign(t_flags flags)
{
	int	count;

	count = 0;
	if (flags.plus)
	{
		ft_putchar_fd('+', 1);
		count++;
	}
	else if (flags.space)
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	return (count);
}

static int	print_nbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += print_nbr(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
	count++;
	return (count);
}

int	print_uint(unsigned int n, t_flags flags)
{
	int	count;
	int	len;

	count = 0;
	len = nbr_len(n);
	if (flags.dot && flags.precision == 0 && n == 0)
		len = 0;
	if (!flags.minus && (!flags.zero || flags.dot))
		count += print_padding(' ', flags.width
				- (len + (flags.plus || flags.space)));
	count += print_sign(flags);
	if (!flags.minus && flags.zero && !flags.dot)
		count += print_padding('0', flags.width
				- (len + (flags.plus || flags.space)));
	count += print_padding('0', flags.precision - len);
	if (!(flags.dot && flags.precision == 0 && n == 0))
		count += print_nbr(n);
	if (flags.minus)
		count += print_padding(' ', flags.width - count);
	return (count);
}