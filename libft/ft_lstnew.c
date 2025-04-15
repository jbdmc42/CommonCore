#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	if (!content)
		return (NULL);
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