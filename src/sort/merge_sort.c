/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:35:45 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/27 15:43:28 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generic.h"
#include "define.h"
#include "double_stack.h"

void	sort_round1(t_double_stack *dstack)
{
	int		i;
	int		size;

	i = 0;
	size = double_stack_get_size_a(dstack);
	while (i < size)
	{
		double_stack_push_a_to_b(dstack);
		double_stack_rotate_b(dstack);
		double_stack_rotate_a(dstack);
		i += 2;
	}
}

int	stack_with_bigger_elem(t_double_stack *dstack)
{
	int	a;
	int	b;

	a = double_stack_get_top_value_a(dstack);
	b = double_stack_get_top_value_b(dstack);
	if (a > b)
		return (A_BIG);
	return (B_BIG);
}


void	h_push_b(t_double_stack *dstack, int *size_a, int *size_b)
{
	if (!(*size_b) && *(size_a))
	{
		double_stack_push_a_to_b(dstack);
		--*(size_a);
	}
	else if (!(*size_a) && (*size_b))
		--(*size_b);
	else if (A_BIG == stack_with_bigger_elem(dstack))
	{
		double_stack_push_a_to_b(dstack);
		--(*size_a);
	}
	else if (B_BIG == stack_with_bigger_elem(dstack))
		--(*size_b);
	double_stack_rotate_b(dstack);

}

void	h_push_a(t_double_stack *dstack, int *size_a, int *size_b)
{
	if (!(*size_b) && (*size_a))
		--(*size_a);
	else if (!(*size_a) && (*size_b))
	{
		double_stack_push_b_to_a(dstack);
		--(*size_b);
	}
	else if (B_BIG == stack_with_bigger_elem(dstack))
	{
		double_stack_push_b_to_a(dstack);
		--(*size_b);
	}
	else if (A_BIG == stack_with_bigger_elem(dstack))
		--(*size_a);
	double_stack_rotate_a(dstack);
}


void	ttt(t_double_stack *dstack, int size, int round)
{
	int i = 0;
	int c = 0;
	int node_to_move = size;

	printf("Round: %d\n\n", round);
	while (i < size)
	{
		if ((0 == (node_to_move / round)) && (0 != (node_to_move % round)))
			round = node_to_move % round;
		// double_stack_print(dstack);
		if ((c % 2) == 0)
			generic_push(dstack, round, h_push_b);
		else
			generic_push(dstack, round, h_push_a);
		++c;
		i += round;
		node_to_move -= round;
	}
	printf("-- DONE ---\n");
}

void	merge_sort(t_double_stack *dstack)
{
	int size;
	int round;
	int i;

	size = double_stack_get_size_b(dstack) + double_stack_get_size_a(dstack);
	round = 2;
	sort_round1(dstack);
	double_stack_print(dstack);
	while (round < size)
	{
		ttt(dstack, size, round);
		double_stack_print(dstack);
		round *= 2;
	}
	ttt(dstack, size, round);
}
