/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pricing_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:47:03 by jbdmc             #+#    #+#             */
/*   Updated: 2025/09/03 16:39:48 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cost	calculate_cost(t_stack *a, t_stack *b, t_node *node)
{
	t_cost	cost;
	int		pos_a;
	int		pos_b;

	pos_a = find_pos_in_a(a, node->value);
	pos_b = index_of_node(b, node);
	if (pos_a <= a->size / 2)
		cost.cost_a = pos_a;
	else
		cost.cost_a = -(a->size - pos_a);
	if (pos_b <= b->size / 2)
		cost.cost_b = pos_b;
	else
		cost.cost_b = -(b->size - pos_b);
	if (cost.cost_a < 0)
		cost.total = -cost.cost_a;
	else
		cost.total = cost.cost_a;
	if (cost.cost_b < 0)
		cost.total += -cost.cost_b;
	else
		cost.total += cost.cost_b;
	cost.node = node;
	return (cost);
}

static void	find_min_max(t_stack *a, t_node **min_node, t_node **max_node)
{
	t_node *cur;
	
	cur = a->top;
	*min_node = cur;
	*max_node = cur;
	while (cur)
	{
		if (cur->value < (*min_node)->value)
			*min_node = cur;
		if (cur->value > (*max_node)->value)
			*max_node = cur;
		cur = cur->next;
	}
}

int	find_pos_in_a(t_stack *a, int value)
{
	t_node	*cur;
	t_node	*min_node;
	t_node	*max_node;
	int		i;

	find_min_max(a, &min_node, &max_node);
	if (value < min_node->value || value > max_node->value)
		return index_of_min(a);
	cur = a->top;
	i = 0;
	while (cur && cur->next)
	{
		if (cur->value < value && value < cur->next->value)
			return i + 1;
		cur = cur->next;
		i++;
	}
	return 0;
}
