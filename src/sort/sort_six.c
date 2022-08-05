/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_six.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:42:15 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/05 14:18:48 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static inline void	index_two(t_double_stack *dstack)
{
	double_stack_rotate_a(dstack);
	double_stack_rotate_a(dstack);
	double_stack_rotate_a(dstack);
}

void	sort_six(t_double_stack *dstack)
{
	int	i;

	i = find_smallest(dstack);
	if (4 == i)
		double_stack_swap_a(dstack);
	else if (3 == i)
		double_stack_rotate_a_twice(dstack);
	else if (2 == i)
		index_two(dstack);
	else if (1 == i)
	{
		double_stack_rev_rotate_a(dstack);
		double_stack_rev_rotate_a(dstack);
	}
	else if (0 == i)
		double_stack_rev_rotate_a(dstack);
	double_stack_push_a_to_b(dstack);
	sort_five(dstack);
	double_stack_push_b_to_a(dstack);
}
