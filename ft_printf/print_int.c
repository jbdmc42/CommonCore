#include "ft_printf.h"

static int	nbr_len(int n)
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

static int	print_sign(int neg, t_flags flags)
{
	if (neg)
		ft_putchar_fd('-', 1);
	else if (flags.plus)
		ft_putchar_fd('+', 1);
	else if (flags.space)
		ft_putchar_fd(' ', 1);
	return (1);
}

static int	print_nbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "2147483648", 10);
		count += 10;
		return (count);
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, 1);
		count++;
	}
	ft_putchar_fd((n % 10) + '0', 1);
	return (count);
}

int	print_int(int n, t_flags flags)
{
	int	count;
	int	len;
	int	neg;

	count = 0;
	neg = (n < 0);
	if (neg)
		n = -n;
	len = nbr_len(n);
	if (flags.dot && flags.precision == 0 && n == 0)
		len = 0;
	if (!flags.minus && (!flags.zero || flags.dot))
		count += print_padding(' ', flags.width - (len + neg + (flags.plus || flags.space)));
	count += print_sign(neg, flags);
	if (!flags.minus && flags.zero && !flags.dot)
		count += print_padding('0', flags.width - (len + neg + (flags.plus || flags.space)));
	count += print_padding('0', flags.precision - len);
	if (!(flags.dot && flags.precision == 0 && n == 0))
		count += print_nbr(n);
	if (flags.minus)
		count += print_padding(' ', flags.width - count);
	return (count);
}
