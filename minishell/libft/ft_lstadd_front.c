/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:03:36 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/18 09:03:37 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

/* int main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;

	node1 = ft_lstnew("world!");
	node2 = ft_lstnew("Hello");

	head = node1;
	ft_lstadd_front(&head, node2);

	printf("1st node --> %s\n", (char *)head->content);
	printf("2nd node --> %s\n", (char *)head->next->content);
	return (0);
} */