#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*psrc;
	unsigned char	*pdst;

	psrc = (unsigned char *)src;
	pdst = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		pdst[i] = psrc[i];
		i++;
	}
	return (dst);
}

/* int	main(void)
{
	char	src[20] = "Hello World!";
	char	dst[20];
	int		i;

	i = 0;
	ft_memcpy(dst, src, 5);
	while (i < 20)
	{
		write(1, &dst[i], 1);
		i++;
	}
	write(1, "\n", 1);
} */