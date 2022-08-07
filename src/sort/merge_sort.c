/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:35:45 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/07 14:56:28 by yrabby           ###   ########.fr       */
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

void	h_push_b(t_double_stack *dstack, t_sort_meta *m)
{
	if (!(m->b_run_size) && (m->a_run_size))
	{
		double_stack_push_a_to_b(dstack);
		--(m->a_run_size);
	}
	else if (!(m->a_run_size) && (m->b_run_size))
		--(m->b_run_size);
	else if (A_SMALL == stack_with_smaller_elem(dstack))
	{
		double_stack_push_a_to_b(dstack);
		--(m->a_run_size);
	}
	else if (B_SMALL == stack_with_smaller_elem(dstack))
		--(m->b_run_size);
	double_stack_rotate_b(dstack);
}

void	h_push_a(t_double_stack *dstack, t_sort_meta *m)
{
	if (!(m->b_run_size) && (m->a_run_size))
		--(m->a_run_size);
	else if (!(m->a_run_size) && (m->b_run_size))
	{
		double_stack_push_b_to_a(dstack);
		--(m->b_run_size);
	}
	else if (B_SMALL == stack_with_smaller_elem(dstack))
	{
		double_stack_push_b_to_a(dstack);
		--(m->b_run_size);
	}
	else if (A_SMALL == stack_with_smaller_elem(dstack))
		--(m->a_run_size);
	double_stack_rotate_a(dstack);
}

void	apply_round(t_double_stack *dstack, int round)
{
	t_sort_meta	meta;
	int			c;

	sort_meta_init(&meta, dstack, round);
	c = 0;
	while (meta.a_size || meta.b_size)
	{
		sort_meta_set_size(&meta);
		if ((c % 2) == 0)
			generic_push(dstack, round, h_push_a, &meta);
		else
			generic_push(dstack, round, h_push_b, &meta);
		++c;
		sort_meta_set_run_size(&meta, round);
	}
}

void	merge_sort(t_double_stack *dstack)
{
	register int	size;
	register int	round;

	size = double_stack_get_size_a(dstack);
	sort_first_round(dstack);
	round = 4;
	while (round < size)
	{
		apply_round(dstack, round);
		round *= 2;
	}
	apply_round(dstack, round);
}
