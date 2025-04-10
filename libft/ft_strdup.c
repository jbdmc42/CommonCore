/* #include <stdio.h> */
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_strdup(const char *s)
{
	size_t		i;
	size_t		len;
	char		*dup;

	i = 0;
	len = ft_strlen(s);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/* int	main(int argc, char *argv[])
{
	if (argc == 2)
		printf("Result --> %s", ft_strdup(argv[1]));
	return (0);
} */