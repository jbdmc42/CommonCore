#include "ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->dot = 0;
	flags->precision = 0;
	flags->hashtag = 0;
	flags->space = 0;
	flags->plus = 0;
}
