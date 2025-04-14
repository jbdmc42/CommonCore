#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* int	main(int argc, char *argv[])
{
	if (argc == 2)
		ft_putchar_fd(argv[1][0], 1);
	return (0);
} */