/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:03:49 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/18 09:03:50 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	ft_strtolower(void *s)
{
	char	*str = (char *)s;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}
} */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* int main(void)
{
	t_list	*head = NULL;
	t_list *node1 = ft_lstnew(ft_strdup("HELLO"));
	t_list *node2 = ft_lstnew(ft_strdup("42"));
	t_list *node3 = ft_lstnew(ft_strdup("STUDENTS"));

	ft_lstadd_back(&head, node1);
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);

	t_list *tmp = head;
	while (tmp)
	{
		printf("Content --> %s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	ft_lstiter(head, ft_strtolower);
	printf("\n---------------\n\n");
	tmp = head;
	while (tmp)
	{
		printf("Content --> %s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	return (0);
} */