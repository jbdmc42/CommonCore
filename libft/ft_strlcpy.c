/* #include <stdio.h> */
#include "libft.h"

static size_t	cal_len(const char *str)
{
	size_t	str_len;

	str_len = 0;
	while (str[str_len] != '\0')
		str_len++;
	return (str_len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	src_len;

	src_len = cal_len(src);
	if (dstsize == 0)
		return (src_len);
	j = 0;
	while (src[j] != '\0' && j < (dstsize - 1))
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (src_len);
}

/* int	main(void)
{
	char dst[20];

	size_t len = ft_strlcpy(dst, "Hello, world!", sizeof(dst));
	printf("Copied string: %s\n", dst);
	printf("Original size: %zu\n", len);
	return (0);
} */