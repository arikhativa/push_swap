/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:42:15 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/03 17:25:39 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_five(t_double_stack *dstack)
{
	int	i;

	i = find_smallest(dstack->a);
	if (3 == i)
		double_stack_swap_a(dstack);
	if (2 == i)
	{
		double_stack_rotate_a(dstack);
		double_stack_rotate_a(dstack);
	}
	else if (1 == i)
	{
		double_stack_rev_rotate_a(dstack);
		double_stack_rev_rotate_a(dstack);
	}
	else if (0 == i)
		double_stack_rev_rotate_a(dstack);
	double_stack_push_a_to_b(dstack);
	sort_four(dstack);
	double_stack_push_b_to_a(dstack);
}
