/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:16:39 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/06 08:31:57 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	already_in_stack(t_stack *a, int value)
{
	t_node	*cur;

	cur = a->top;
	while (cur)
	{
		if (cur->value == value)
			return (1);
		cur = cur->next;
	}
	return (0);
}

int	is_valid_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	parse_tokens(char **tokens, t_stack *a)
{
	int		j;
	long	value;
	t_node	*node;

	j = 0;
	while (tokens[j])
	{
		if (!is_valid_number(tokens[j]))
			return (0);
		value = ft_atol(tokens[j]);
		if (value < INT_MIN || value > INT_MAX)
			return (0);
		if (already_in_stack(a, (int)value))
			return (0);
		node = new_node((int)value);
		if (!node)
			return (0);
		stack_add_bottom(a, node);
		j++;
	}
	return (1);
}

int	parse_and_fill_stack(int argc, char **argv, t_stack *a)
{
	int		i;
	char	**tokens;

	i = 1;
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		if (!tokens)
			return (0);
		if (!parse_tokens(tokens, a))
			return (free_tokens(tokens), 0);
		free_tokens(tokens);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	stack_init(&a);
	stack_init(&b);
	if (!parse_and_fill_stack(argc, argv, &a))
		print_error();
	if (!is_sorted(&a))
		sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
