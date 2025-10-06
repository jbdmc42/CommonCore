/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:03:01 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/06 08:42:49 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_min_to_b(t_stack *a, t_stack *b, t_node *cur)
{
	int	min;
	int	pos;
	int	i;

	cur = a->top;
	min = cur->value;
	pos = 0;
	i = 0;
	while (cur)
	{
		if (cur->value < min)
		{
			min = cur->value;
			pos = i;
		}
		cur = cur->next;
		i++;
	}
	if (pos <= a->size / 2)
		while (a->top->value != min)
			ra(a);
	else
		while (a->top->value != min)
			rra(a);
	pb(a, b);
}

void	sort_three(t_stack *a)
{
	int	aa;
	int	bb;
	int	cc;

	aa = a->top->value;
	bb = a->top->next->value;
	cc = a->bot->value;
	if (aa > bb && bb < cc && aa < cc)
		sa(a);
	else if (aa > bb && bb > cc)
	{
		sa(a);
		rra(a);
	}
	else if (aa > bb && bb < cc && aa > cc)
		ra(a);
	else if (aa < bb && bb > cc && aa < cc)
	{
		sa(a);
		ra(a);
	}
	else if (aa < bb && bb > cc && aa > cc)
		rra(a);
}

void	sort_five(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = NULL;
	push_min_to_b(a, b, node);
	push_min_to_b(a, b, node);
	sort_three(a);
	pa(a, b);
	pa(a, b);
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	check_special_cases(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
	}
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 5)
		sort_five(a, b);
}
