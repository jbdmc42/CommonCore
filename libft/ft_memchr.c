/* #include <stdio.h> */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((unsigned char *)&str[i]);
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char arr[] = "Hello World!";

	printf("%p", ft_memchr(arr, 'o', 10));
	return (0);
} */