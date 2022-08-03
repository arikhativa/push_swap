/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_quarter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:02:27 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/03 18:37:25 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	get_quarter(t_double_stack *dstack, t_sort_by_quarter *m)
{
	int	size;

	size = double_stack_get_size_a(dstack);
	m->quarter_size = size / 4;
	m->last_quarter_size = size - (m->quarter_size * 3);
}

void	push_quarter_to_b(t_double_stack *dstack, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		double_stack_push_a_to_b(dstack);
		++i;
	}
}

int	calc_moves(int size, int index)
{
	if (index >= (size / 2))
		return (size - 1 - index);
	return (index + 1);
}


void	move_up(t_double_stack *dstack, int index)
{
	int	size;

	size = double_stack_get_size_b(dstack);
	while (index < (size - 1))
	{
		double_stack_rotate_b(dstack);
		++index;
	}
}

void	move_down(t_double_stack *dstack, int index)
{
	int	size;

	size = double_stack_get_size_b(dstack);
	while (index + 1)
	{
		double_stack_rev_rotate_b(dstack);
		--index;
	}
}

void	move_index_to_a(t_double_stack *dstack, int index)
{
	if (index >= (double_stack_get_size_b(dstack) / 2))
		move_up(dstack, index);
	else
		move_down(dstack, index);
	double_stack_push_b_to_a(dstack);
}

void	move_one_to_a(t_double_stack *dstack, t_sort_by_quarter *m)
{
	int	big_moves;
	int	small_moves;

	big_moves = calc_moves(double_stack_get_size_b(dstack), m->biggest_in_quarter);
	small_moves = calc_moves(double_stack_get_size_b(dstack), m->smallest_in_quarter);
	if (small_moves > big_moves)
		move_index_to_a(dstack, m->biggest_in_quarter);
	else
	{
		move_index_to_a(dstack, m->smallest_in_quarter);
		double_stack_rotate_a(dstack);
	}

}

void	handle_quarter(t_double_stack *dstack, t_sort_by_quarter *m)
{
	int	i;
	int	biggest;

	push_quarter_to_b(dstack, m->quarter_size);
	biggest = stack_get_value_by_index(dstack->b, find_biggest(dstack->b));
	i = 0;
	while (i < m->quarter_size)
	{
		m->biggest_in_quarter = find_biggest(dstack->b);
		m->smallest_in_quarter = find_smallest(dstack->b);
		move_one_to_a(dstack, m);
		++i;
	}
	while (biggest != double_stack_get_top_value_a(dstack))
		double_stack_rotate_a(dstack);
	double_stack_rotate_a(dstack);
}

void	handle_last_quarter(t_double_stack *dstack, t_sort_by_quarter *m)
{
	int	i;
	int	biggest;

	push_quarter_to_b(dstack, m->last_quarter_size);
	biggest = stack_get_value_by_index(dstack->b, find_biggest(dstack->b));
	i = 0;
	while (i < m->last_quarter_size)
	{
		m->biggest_in_quarter = find_biggest(dstack->b);
		m->smallest_in_quarter = find_smallest(dstack->b);
		move_one_to_a(dstack, m);
		++i;
	}
}

void	sort_by_quarter(t_double_stack *dstack)
{
	t_sort_by_quarter m;

	get_quarter(dstack, &m);
	handle_quarter(dstack, &m);
	handle_quarter(dstack, &m);
	handle_quarter(dstack, &m);
	handle_last_quarter(dstack, &m);
	double_stack_print(dstack);
}
