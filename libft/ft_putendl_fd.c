#include "libft.h"

void	ft_putendl_fd(const char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

/* int	main(int argc, char *argv[])
{
	if (argc == 2)
		ft_putendl_fd(argv[1], 1);
	return (0);
} */