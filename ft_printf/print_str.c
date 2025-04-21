#include "ft_printf.h"

static int	print_spaces(int count, t_flags flags, int len)
{
	while (count < flags.width - len)
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	return (count);
}

int	print_str(char *s, t_flags flags)
{
	int	count;
	int	len;

	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (flags.dot && flags.precision < len)
		len = flags.precision;
	count = 0;
	if (!flags.minus)
		count += print_spaces(count, flags, len);
	write(1, s, len);
	count += len;
	if (flags.minus)
		count += print_spaces(count, flags, len);
	return (count);
}
