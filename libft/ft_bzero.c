#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

/* int	main(void)
{
	char	arr[20];
	int		i;

	i = 0;
	while (i < 20)
	{
		arr[i] = 'X';
		i++;
	}

	ft_bzero(arr, 10);

	i = 0;
	while (i < 20)
	{
		if (arr[i] == '\0')
			write(1, ".\n", 2);
		else
			write(1, &arr[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
} */