/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:04:04 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/18 09:14:02 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/* int main(void)
{
	char	*str = "Hello world!";
	t_list	*node = ft_lstnew(str);

	if (node)
	{
		printf("Content --> %s\n", (char *)node->content);
		if (node->next == NULL)
			printf("No more content on the list.\n");
	}
	return (0);
} */