/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:59:23 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/06 08:37:03 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_value(t_stack *a)
{
	t_node	*cur;
	int		min;

	if (!a || a->size == 0)
		return (0);
	cur = a->top;
	min = cur->value;
	while (cur)
	{
		if (cur->value < min)
			min = cur->value;
		cur = cur->next;
	}
	return (min);
}

void	rotate_a_helper(t_stack *a, int pos)
{
	if (pos <= a->size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		pos = a->size - pos;
		while (pos-- > 0)
			rra(a);
	}
}

void	rotate_a_to_min(t_stack *a)
{
	t_node	*cur;
	int		pos;
	int		i;

	cur = a->top;
	pos = 0;
	i = 0;
	while (cur)
	{
		if (cur->value == min_value(a))
		{
			pos = i;
			break ;
		}
		cur = cur->next;
		i++;
	}
	rotate_a_helper(a, pos);
}

t_cost	find_cheapest_node(t_stack *a, t_stack *b)
{
	t_node	*cur;
	t_cost	cheapest;
	t_cost	cost;

	cur = b->top;
	cheapest = calculate_cost(a, b, cur);
	cur = cur->next;
	while (cur)
	{
		cost = calculate_cost(a, b, cur);
		if (cost.total < cheapest.total)
			cheapest = cost;
		cur = cur->next;
	}
	return (cheapest);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	t_cost	cheapest;

	if (a->size <= 5)
	{
		check_special_cases(a, b);
		return ;
	}
	while (a->size > 3)
		pb(a, b);
	if (!is_sorted(a))
		sort_three(a);
	while (b->size > 0)
	{
		cheapest = find_cheapest_node(a, b);
		do_moves(a, b, cheapest);
	}
	rotate_a_to_min(a);
}
