/* #include <stdio.h> */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char	string[20] = "Hello World!";

	printf("%s", ft_strchr(string, 'o'));
	return (0);
} */