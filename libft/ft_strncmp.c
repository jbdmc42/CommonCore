/* #include <stdio.h> */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 1)
	{
		return (0);
	}
	while ((i + 1) < n && (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/* int	main(void)
{
	char			str1[] = "ABCD";
	char			str2[] = "AB";
	size_t	n = 3;
	printf("%d\n", ft_strncmp(str1, str2, n));
	return (0);
} */