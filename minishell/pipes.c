/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:00:00 by copilot           #+#    #+#             */
/*   Updated: 2026/06/02 17:03:44 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_commands(t_token *tokens)
{
	int	count;

	count = 1;
	while (tokens)
	{
		if (tokens->type == PIPE)
			count++;
		tokens = tokens->next;
	}
	return (count);
}

static t_token	*dup_token_node(t_token *src)
{
	t_token	*node;

	node = malloc(sizeof(t_token));
	if (!node)
		return (NULL);
	node->value = ft_strdup(src->value);
	node->type = src->type;
	node->next = NULL;
	if (src->heredoc_fd >= 0)
		node->heredoc_fd = dup(src->heredoc_fd);
	else
		node->heredoc_fd = -1;
	if (src->heredoc_fd >= 0 && node->heredoc_fd < 0)
		return (free(node->value), free(node), NULL);
	return (node);
}

t_token	*extract_command(t_token *tokens, t_token **next_token)
{
	t_token	*current;
	t_token	*new_head;
	t_token	*new_tail;
	t_token	*node;

	new_head = NULL;
	new_tail = NULL;
	*next_token = NULL;
	current = tokens;
	while (current && current->type != PIPE)
	{
		node = dup_token_node(current);
		if (!node)
			return (free_tokens(new_head), NULL);
		if (!new_head)
			new_head = node;
		else
			new_tail->next = node;
		new_tail = node;
		current = current->next;
	}
	if (current && current->type == PIPE)
		*next_token = current->next;
	return (new_head);
}

int	create_pipe(int *pipe_fd)
{
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		return (-1);
	}
	return (0);
}

void	close_fd(int *fd)
{
	if (*fd >= 0)
	{
		close(*fd);
		*fd = -1;
	}
}
