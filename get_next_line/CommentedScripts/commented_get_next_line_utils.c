/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commented_get_next_line_utils.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:53:14 by joaobarb          #+#    #+#             */
/*   Updated: 2025/05/16 15:32:45 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	dealloc(t_list **head, t_list *clean_node, char *buf) // this function will dealloc the memory to finish the clearence
{
	t_list	*tmp; // a temporary node

	if (!*head) // if the list is empty
		return ; // empty return
	while (*head) // while the current node in the list is valid
	{
		tmp = (*head)->next; // tmp node becomes the node after
		free((*head)->stash); // it frees the current node
		free(*head); // it frees the list
		*head = tmp; // the head of he list becomes the temporary pointer
	}
	*head = NULL; // after the clearing process the header of the list becomes NULL to make it still a valid list
	if (clean_node->stash[0]) // if the 1st character of the clean node is a '\0'
		*head = clean_node; // the head of the list becomes the clean_node
	else
	{
		free(buf); // it frees the current buffer
		free(clean_node); // it frees the clean node
	}
}

t_list	*find_lst_node(t_list *head) // this functions searches for the last node
{
	if (!head) // checks if the list is empty
		return (NULL); // NULL return
	while (head->next) // while the pointer to the next node is not NULL
		head = head->next; // skips the node to the next one
	return (head); // returns the last node found (lst_node)
}

void	ft_strcpy(t_list *head, char *str) // this function will 
{
	int	i; // counter for the current node
	int	j; // counter for the string that will receive the information from the current node

	if (!head) // if the list is empty
		return ; // empty return
	j = 0; // initializes the counter at 0
	while (head) // while the list is not empty
	{
		i = 0; // initializes the counter at 0
		while (head->stash[i]) // while the current character in the current node is not a '\0'
		{
			if (head->stash[i] == '\n') // if the current character in the current node is a '\n'
			{
				str[j++] = '\n'; // the next character on the string becomes the '\n'
				str[j] = '\0'; // the current character becomes the '\0'
				return ; // it ends the loop with an "empty" string
			}
			str[j++] = head->stash[i++]; // else it copies the current character on the line in the current node to the string
		}
		head = head->next; // skips to the next node
	}
	str[j] = '\0'; // gives it the '\0' character in the end
}

int	ft_strlen(t_list *head) // this function will calculate the size of the main buffer
{
	int	i; // counter for the current buffer characters
	int	len; // counter for the size

	if (!head) // if head is empty
		return (0); // size 0 return
	len = 0; // len starts in 0
	while (head) // while head has anything
	{
		i = 0; // counter for the characters in the current buffer
		while (head->stash[i]) // while the current character in the current buffer is not a '\0'
		{
			if (head->stash[i] == '\n') // if the current character in the current buffer is a '\n'
			{
				len++; // increments len by 1
				return (len); // size 1 returns
			}
			i++; // skips to the next character in the current buffer
			len++; // increments len by 1
		}
		head = head->next; // skips to the next node in head to keep counting
	}
	return (len); // total len return
}

void	append(t_list **head, char *buf) // this function creates a new node with the information stored in the temporary buffer "buf" on the head of the list if the list is not empty or in the end of the list if there is any node
{
	t_list	*new_node; // the node that will be created
	t_list	*lst_node; // last node on the list

	lst_node = find_lst_node(*head); // the function find_lst_node will search for the last node in head
	new_node = malloc(sizeof(t_list));  // allocates memory for the new_node based on the size of the t_list nodes
	if (!new_node) // safety verification
		return ; // empty return
	if (!lst_node) // verifies if the list is empty
		*head = new_node; // if it is, the new_node equals the head of the list "head"
	else
		lst_node->next = new_node; // if it isn't, the new_node will become the node after that last node found, so, the new_last_node, in a certain way
	new_node->stash = buf; // the new_node content will become the content stored in the temporary buffer "buf"
	new_node->next = NULL; // the pointer to the next node will become NULL to make the list valid
}
