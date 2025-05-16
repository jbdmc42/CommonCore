/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:53:14 by joaobarb          #+#    #+#             */
/*   Updated: 2025/05/14 02:28:56 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	dealloc(t_list **head, t_list *clean_node, char *buf)
{
	t_list	*tmp;

	if (!*head)
		return ;
	while (*head)
	{
		tmp = (*head)->next;
		free((*head)->stash);
		free(*head);
		*head = tmp;
	}
	*head = NULL;
	if (clean_node->stash[0])
		*head = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}

t_list	*find_lst_node(t_list *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	ft_strcpy(t_list *head, char *str)
{
	int	i;
	int	j;

	if (!head)
		return ;
	j = 0;
	while (head)
	{
		i = 0;
		while (head->stash[i])
		{
			if (head->stash[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
 			}
			str[j++] = head->stash[i++];
		}
		head = head->next;
	}
	str[j] = '\0';
}

int	ft_strlen(t_list *head)
{
	int	i;
	int	len;

	if (!head)
		return (0);
	len = 0;
	while (head)
	{
		i = 0;
		while (head->stash[i])
		{
			if (head->stash[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		head = head->next;
	}
	return (len);
}

void	append(t_list **head, char *buf)
{
	t_list	*new_node;
	t_list	*lst_node;

	lst_node = find_lst_node(*head);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	if (!lst_node)
		*head = new_node;
	else
		lst_node->next = new_node;
	new_node->stash = buf;
	new_node->next = NULL;
}
