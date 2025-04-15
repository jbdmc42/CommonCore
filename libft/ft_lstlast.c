#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/* int main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*last;

	node1 = ft_lstnew("world!");
	node2 = ft_lstnew("Hello");

	head = node1;
	ft_lstadd_front(&head, node2);

	last = ft_lstlast(head);
	printf("Last item --> %s", (char *)last->content);
	return (0);
} */