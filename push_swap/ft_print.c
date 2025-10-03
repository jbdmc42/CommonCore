/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:44:19 by jbdmc             #+#    #+#             */
/*   Updated: 2025/09/01 12:14:51 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	print_stack(t_stack *stack)
{
	t_node	*cur;

	cur = stack->top;
	printf("\nStack (top -> bot, size = %d):\n", stack->size);
	while (cur)
	{
		printf("> %d\n", cur->value);
		cur = cur->next;
	}
}