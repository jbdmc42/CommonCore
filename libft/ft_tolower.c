/* #include <stdio.h> */
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

/* int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			printf("Before --> %d     ", argv[i][0]);
			printf("After --> %d\n", ft_tolower(argv[i][0]));
			i++;
		}
	}
	return (0);
} */