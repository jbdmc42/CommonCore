/* #include <stdio.h> */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

/* int	main(void)
{
	char	string[20] = "Hello World!";

	printf("%s", ft_strrchr(string, '!'));
	return (0);
} */