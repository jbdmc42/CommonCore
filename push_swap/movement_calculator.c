/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_calculator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:56:17 by jbdmc             #+#    #+#             */
/*   Updated: 2025/09/03 15:56:46 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rr_rrr(t_stack *a, t_stack *b, t_cost *cost)
{
	while (cost->cost_a > 0 && cost->cost_b > 0)
	{
		rr(a, b);
		cost->cost_a--;
		cost->cost_b--;
	}
	while (cost->cost_a < 0 && cost->cost_b < 0)
	{
		rrr(a, b);
		cost->cost_a++;
		cost->cost_b++;
	}
}

void	do_a(t_stack *a, t_cost *cost)
{
	while (cost->cost_a > 0)
	{
		ra(a);
		cost->cost_a--;
	}
	while (cost->cost_a < 0)
	{
		rra(a);
		cost->cost_a++;
	}
}

void	do_b(t_stack *b, t_cost *cost)
{
	while (cost->cost_b > 0)
	{
		rb(b);
		cost->cost_b--;
	}
	while (cost->cost_b < 0)
	{
		rrb(b);
		cost->cost_b++;
	}
}

void	do_moves(t_stack *a, t_stack *b, t_cost cost)
{
	do_rr_rrr(a, b, &cost);
	do_a(a, &cost);
	do_b(b, &cost);
	pa(a, b);
}
