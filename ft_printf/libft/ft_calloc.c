/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:52:22 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/14 13:52:23 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	totalsize;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	totalsize = nmemb * size;
	ptr = malloc(totalsize);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, totalsize);
	return (ptr);
}

/* int	main(void)
{
	size_t n = 5;
    size_t size = sizeof(int);
    int *arr;
    size_t i;

    arr = (int *)ft_calloc(n, size);
    if (!arr)
    {
        printf("Error: ft_calloc returned NULL\n");
        return (1);
    }

    for (i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            printf("Error: arr[%zu] = %d (expected 0)\n", i, arr[i]);
            free(arr);
            return (1);
        }
    }
    printf("Test 1 (n = 5, size = sizeof(int)): OK ✅\n");
    free(arr);

    arr = (int *)ft_calloc(0, size);
    if (arr == NULL)
    {
        printf("Error: ft_calloc(0, size) returned NULL\n");
        return (1);
    }
    else
    {
        printf("Test 2 (nmemb = 0): Valid pointer ✅\n");
        free(arr);
    }

    arr = (int *)ft_calloc(n, 0);
    if (arr == NULL)
    {
        printf("Error: ft_calloc(n, 0) returned NULL\n");
        return (1);
    }
    else
    {
        printf("Test 3 (size = 0): Valid pointer ✅\n");
        free(arr);
    }

    return 0;
} */