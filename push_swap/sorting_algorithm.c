/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:24:47 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/06 08:38:40 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_of_node(t_stack *b, t_node *node)
{
	t_node	*cur;
	int		i;

	cur = b->top;
	i = 0;
	while (cur)
	{
		if (cur == node)
			return (i);
		cur = cur->next;
		i++;
	}
	return (-1);
}

int	index_of_min(t_stack *a)
{
	t_node	*cur;
	int		i;
	int		min;
	int		min_i;

	cur = a->top;
	i = 0;
	min = cur->value;
	min_i = 0;
	while (cur)
	{
		if (cur->value < min)
		{
			min = cur->value;
			min_i = i;
		}
		cur = cur->next;
		i++;
	}
	return (min_i);
}

int	index_of_max(t_stack *a)
{
	t_node	*cur;
	int		i;
	int		max;
	int		max_i;

	cur = a->top;
	i = 0;
	max = cur->value;
	max_i = 0;
	while (cur)
	{
		if (cur->value > max)
		{
			max = cur->value;
			max_i = i;
		}
		cur = cur->next;
		i++;
	}
	return (max_i);
}

t_node	*node_at(t_stack *s, int index)
{
	t_node	*cur;
	int		i;

	cur = s->top;
	i = 0;
	while (cur && i < index)
	{
		cur = cur->next;
		i++;
	}
	return (cur);
}
