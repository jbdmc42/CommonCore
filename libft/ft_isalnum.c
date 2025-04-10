/* #include <stdio.h> */
#include "libft.h"

int	ft_isalnum(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	else if (c >= 97 && c <= 122)
		return (1);
	else if (c >= 48 && c <= 57)
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
			printf("--> %d\n", ft_isalnum(ft_atoi(argv[i])));
			i++;
		}
		return (0);
	}
	printf("Too few, non-acceptable or incorrect arguments.\n");
	return (0);
} */