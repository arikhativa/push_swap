/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:35:45 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/03 11:41:08 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

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

void	apply_round(t_double_stack *dstack, int round)
{
	t_sort_meta	meta;
	int c = 0;

	sort_meta_init(&meta, dstack, round);
	while (meta.a_size || meta.b_size)
	{
		sort_meta_set_size(&meta);
		if ((c % 2) == 0)
			generic_push(dstack, round, h_push_a, &meta.a_clean_nodes, &meta.b_clean_nodes);
		else
			generic_push(dstack, round, h_push_b, &meta.a_clean_nodes, &meta.b_clean_nodes);
		++c;
		sort_meta_set_clean_nodes(&meta, round);
	}
}

void	merge_sort(t_double_stack *dstack)
{
	int size;
	int round;
	int i;

	size = double_stack_get_size_a(dstack);
	sort_first_round(dstack, size);
	round = 4;
	while (round < size)
	{
		apply_round(dstack, round);
		round *= 2;
	}
	apply_round(dstack, round);
}
