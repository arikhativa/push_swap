/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_round.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 09:19:48 by yoav              #+#    #+#             */
/*   Updated: 2022/07/28 09:56:53 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"

static int	should_flip_a(t_double_stack *dstack)
{
	int	top;
	int	second_to_top;

	top = double_stack_get_top_value_a(dstack);
	second_to_top = double_stack_get_second_to_top_value_a(dstack);
	return (top < second_to_top);
}

static int	should_flip_b(t_double_stack *dstack)
{
	int	top;
	int	second_to_top;

	top = double_stack_get_top_value_b(dstack);
	second_to_top = double_stack_get_second_to_top_value_b(dstack);
	return (top > second_to_top);
}

void	push_half(t_double_stack *dstack)
{
	int	size;
	int	i;

	i = 0;
	while (i < (size / 2))
	{
		double_stack_push_a_to_b(dstack);
		double_stack_push_a_to_b(dstack);
		i += 2;
	}
}

// void	sort_first_round(t_double_stack *dstack)
// {
// 	int		i;
// 	int		flip_a;
// 	int		flip_b;
// 	int		size;

// 	size = double_stack_get_size_a(dstack);
// 	i = 4;
// 	while (i < (size / 2))
// 	{
// 		double_stack_push_a_to_b(dstack);
// 		double_stack_push_a_to_b(dstack);
// 		flip_a = should_flip_a(dstack);
// 		flip_b = should_flip_b(dstack);
// 		if (flip_a && flip_b)
// 			double_stack_swap_both(dstack);
// 		else if (flip_a)
// 			double_stack_swap_a(dstack);
// 		else if (flip_b)
// 			double_stack_swap_b(dstack);
// 		double_stack_push_a_to_b(dstack);
// 		double_stack_push_a_to_b(dstack);
// 		i += 4;
// 	}
// }

void	sort_first_round(t_double_stack *dstack, int size, int round)
{
	int i = 0;
	int c = 0;
	int	size_a = 0;
	int	size_b = 0;
	int	nodes_a = 0;
	int	nodes_b = 0;

	push_half(dstack);
	size_a = double_stack_get_size_a(dstack);
	size_b = double_stack_get_size_b(dstack);
	nodes_a = get_min(size_a, round / 2);
	nodes_b = get_min(size_b, round / 2);
	while (i < size)
	{
		size_a -= nodes_a;
		size_b -= nodes_b;
		if ((c % 2) == 0)
			generic_push(dstack, round, h_push_a, &nodes_a, &nodes_b);
		else
			generic_push(dstack, round, h_push_b, &nodes_a, &nodes_b);
		++c;
		i += round;
		nodes_a = get_min(size_a, round / 2);
		nodes_b = get_min(size_b, round / 2);
	}
}
