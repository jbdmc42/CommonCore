/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:03:58 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/18 09:17:48 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	del_content(void  *content)
{
	free(content);
}

void *str_toupper(void *s)
{
    char *str = (char *)s;
    char *new_str = ft_strdup(str);

    if (new_str) {
        for (int i = 0; new_str[i]; i++) {
            if (new_str[i] >= 'a' && new_str[i] <= 'z') {
                new_str[i] -= 32;
            }
        }
    }
    return new_str;
} */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/* int main(void)
{
	t_list	*head = NULL;
	t_list *node1 = ft_lstnew(ft_strdup("hello"));
	t_list *node2 = ft_lstnew(ft_strdup("42"));
	t_list *node3 = ft_lstnew(ft_strdup("students"));

	ft_lstadd_back(&head, node1);
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);

	t_list *tmp = head;
	while (tmp)
	{
		printf("Content --> %s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	tmp = ft_lstmap(head, str_toupper, del_content);
	printf("\n---------------\n\n");
	while (tmp)
	{
		printf("Content --> %s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	return (0);
} */
