/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:29:29 by jbdmc             #+#    #+#             */
/*   Updated: 2025/09/01 12:11:55 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_a_is_min(t_stack *a, int B, int C)
{
	if (B > C)
		ra(a);
	else
	{
		sa(a);
		ra(a);
	}
}

void	case_b_is_min(t_stack *a, int A, int C)
{
	if (A < C)
		sa(a);
	else
	{
		rra(a);
		rra(a);
	}
}

void	case_c_is_min(t_stack *a, int A, int B)
{
	if (A < B)
		ra(a);
	else
	{
		sa(a);
		rra(a);
	}
}
