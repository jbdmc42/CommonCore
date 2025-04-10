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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	dst_len = cal_len(dst);
	src_len = cal_len(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	j = 0;
	while (src[j] != '\0' && (dst_len + j) < (dstsize - 1))
	{
		dst[dst_len + j] = src[j];
		j++;
	}
	dst[dst_len + j] = '\0';
	return (dst_len + src_len);
}

/* int	main(void)
{
	char dest[20] = "Hello, ";
	const char *src = "world!";
	size_t result;

	result = ft_strlcat(dest, src, sizeof(dest));
	printf("Result: %s\n", dest);
	printf("Total size: %zu\n", result);
	return (0);
} */