/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:03:46 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/18 09:03:46 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	del_content(void  *content)
{
	free(content);
} */

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/* int main(void)
{
	t_list	*head = NULL;
	t_list *node1 = ft_lstnew(ft_strdup("Hello"));
	t_list *node2 = ft_lstnew(ft_strdup("42"));
	t_list *node3 = ft_lstnew(ft_strdup("Students"));

	ft_lstadd_back(&head, node1);
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);

	t_list *tmp = head;
	while (tmp)
	{
		printf("Content --> %s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	ft_lstdelone(node2, del_content);
	printf("\n---------------\n\n");
	tmp = head;
	while (tmp)
	{
		printf("Content --> %s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	return (0);
} */