/* #include <stdio.h> */
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc >= 2)
	{
		while (i < argc)
		{
			printf("--> %zu\n", ft_strlen(argv[i]));
			i++;
		}
		return (0);
	}
	printf("Too few, non-acceptable or incorrect arguments.\n");
	return (0);
} */