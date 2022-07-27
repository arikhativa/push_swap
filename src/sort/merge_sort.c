/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:35:45 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/27 18:03:35 by yrabby           ###   ########.fr       */
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
		if ((i % 2) == 0)
		{
			double_stack_push_a_to_b(dstack);
			double_stack_rotate_b(dstack);
		}
		else
			double_stack_rotate_a(dstack);
		++i;
	}
}

int	stack_with_smaller_elem(t_double_stack *dstack)
{
	int	a;
	int	b;

	a = double_stack_get_top_value_a(dstack);
	b = double_stack_get_top_value_b(dstack);
	if (a < b)
		return (A_SMALL);
	return (B_SMALL);
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
	else if (A_SMALL == stack_with_smaller_elem(dstack))
	{
		double_stack_push_a_to_b(dstack);
		--(*size_a);
	}
	else if (B_SMALL == stack_with_smaller_elem(dstack))
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
	else if (B_SMALL == stack_with_smaller_elem(dstack))
	{
		double_stack_push_b_to_a(dstack);
		--(*size_b);
	}
	else if (A_SMALL == stack_with_smaller_elem(dstack))
		--(*size_a);
	double_stack_rotate_a(dstack);
}

static int	get_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	apply_round(t_double_stack *dstack, int size, int round)
{
	int i = 0;
	int c = 0;
	int	size_a = double_stack_get_size_a(dstack);
	int	size_b = double_stack_get_size_b(dstack);
	int	nodes_a = get_min(size_a, round / 2);
	int	nodes_b = get_min(size_b, round / 2);

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

void	merge_sort(t_double_stack *dstack)
{
	int size;
	int round;
	int i;

	size = double_stack_get_size_b(dstack) + double_stack_get_size_a(dstack);
	round = 2;
	sort_round1(dstack);
	while (round < size)
	{
		apply_round(dstack, size, round);
		round *= 2;
	}
	apply_round(dstack, size, round);
}
