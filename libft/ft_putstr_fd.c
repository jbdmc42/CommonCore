#include "libft.h"

void	ft_putstr_fd(const char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		ft_putstr_fd(argv[1], 1);
	return (0);
}