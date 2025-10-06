/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:18:21 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/06 08:34:39 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// LIBRARIES
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

// STRUCTS

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bot;
	int		size;
}	t_stack;

typedef struct s_cost
{
	int		cost_a;
	int		cost_b;
	int		total;
	t_node	*node;
}	t_cost;

// FUNCTIONS

// FT_ATOL
long	ft_atol(const char *str);

// FT_FREE
void	free_stack(t_stack *stack);
void	free_tokens(char **tokens);

// FT_PRINT
void	print_error(void);

// MAIN_ALGORITHM
void	sort_stack(t_stack *a, t_stack *b);

// MOVEMENT_CALCULATOR
void	do_moves(t_stack *a, t_stack *b, t_cost cost);

// PRICING_ALGORITHM
t_cost	calculate_cost(t_stack *a, t_stack *b, t_node *node);
int		find_pos_in_a(t_stack *a, int value);

// PUSH
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

// REVERSE_ROTATE
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

// ROTATE
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// SORT_CHECK
int		is_sorted(t_stack *stack);

// SORTING_ALGORITHM
int		index_of_node(t_stack *b, t_node *node);
int		index_of_min(t_stack *a);
int		index_of_max(t_stack *a);
t_node	*node_at(t_stack *s, int index);

// SPECIAL_CASES
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);
void	check_special_cases(t_stack *a, t_stack *b);

// STACK_INIT
void	stack_init(t_stack *stack);
void	stack_add_bottom(t_stack *stack, t_node *new);
t_node	*new_node(int value);

// SWAP
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

// TINY_CASES
void	case_a_is_min(t_stack *a, int B, int C);
void	case_b_is_min(t_stack *a, int A, int C);
void	case_c_is_min(t_stack *a, int A, int B);

#endif