/* #include <stdio.h> */
#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/* int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc >= 2)
	{
		while (i < argc)
		{
			printf("--> %d\n", ft_isprint(ft_atoi(argv[i])));
			i++;
		}
		return (0);
	}
	printf("Too few, non-acceptable or incorrect arguments.\n");
	return (0);
} */