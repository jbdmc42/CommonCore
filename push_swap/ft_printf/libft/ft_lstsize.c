/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:04:09 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/18 09:04:09 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

/* int	main(void)
{
	t_list *n1 = ft_lstnew("1");
	t_list *n2 = ft_lstnew("2");
	t_list *n3 = ft_lstnew("3");

	n1->next = n2;
	n2->next = n3;

	printf("List size --> %d\n", ft_lstsize(n1));
	return (0);
} */