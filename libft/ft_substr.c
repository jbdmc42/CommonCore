#include <stdio.h>
#include "libft.h"

static void	copy_substr(const char *s, unsigned int start, char *dup, size_t len)
{
	unsigned int	j;
	unsigned int	i;

	i = start;
	j = 0;
	while (s[i] != '\0' && j < len)
	{
		dup[j] = s[i];
		i++;
		j++;
	}
	dup[j] = '\0';
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*dup;

	if (!s)
		return (NULL);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
	{
		dup[0] = '\0';
		return (dup);
	}
	i = start;
	copy_substr(s, i, dup, len);
	return (dup);
}

/* int	main(int argc, char *argv[])
{
	if (argc == 2)
		printf("Result --> %s", ft_substr(argv[1], 2, 3));
	return (0);
} */

/* int	main(void)
{
	printf("Result --> %s", ft_substr("abcdef", 2, 3));
	return (0);
} */