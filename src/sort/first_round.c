/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_round.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 09:19:48 by yoav              #+#    #+#             */
/*   Updated: 2022/08/03 16:43:58 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	push_half(t_double_stack *dstack)
{
	int	size;
	int	i;

	i = 0;
	size = double_stack_get_size_a(dstack);
	while (i < (size / 2))
	{
		double_stack_push_a_to_b(dstack);
		double_stack_push_a_to_b(dstack);
		i += 2;
	}
}

static inline void	handle_last_elem(t_double_stack *dstack, t_first_round_meta *m)
{
	if (m->a_size == 1)
	{
		m->a_flip = FALSE;
		m->a_size = 0;
		double_stack_rotate_a(dstack);
	}
	if (m->b_size == 1)
	{
		m->b_flip = FALSE;
		m->b_size = 0;
		double_stack_rotate_b(dstack);
	}
}

static inline void	rotate_if_needed(t_double_stack *dstack, t_first_round_meta *m)
{
	handle_last_elem(dstack, m);
	if (m->a_flip && m->b_flip)
		double_stack_swap_both(dstack);
	else if (m->a_flip)
		double_stack_swap_a(dstack);
	else if (m->b_flip)
		double_stack_swap_b(dstack);
	if (m->a_size && m->b_size)
		double_stack_rotate_both_twice(dstack);
	else if (m->a_size)
		double_stack_rotate_a_twice(dstack);
	else if (m->b_size)
		double_stack_rotate_b_twice(dstack);
}

void	sort_first_round(t_double_stack *dstack)
{
	t_first_round_meta	m;

	push_half(dstack);
	m.a_size = double_stack_get_size_a(dstack);
	m.b_size = double_stack_get_size_b(dstack);
	while (m.a_size || m.b_size)
	{
		m.a_flip = should_flip_a(dstack);
		m.b_flip = should_flip_b(dstack);
		rotate_if_needed(dstack, &m);
		m.a_size -= get_min(2, m.a_size);
		m.b_size -= get_min(2, m.b_size);
	}
}
