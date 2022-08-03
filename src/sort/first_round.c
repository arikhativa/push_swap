/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_round.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 09:19:48 by yoav              #+#    #+#             */
/*   Updated: 2022/08/03 16:13:42 by yrabby           ###   ########.fr       */
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

void	sort_first_round(t_double_stack *dstack)
{
	int	size_a;
	int	size_b;
	int	flip_a;
	int	flip_b;

	push_half(dstack);
	size_a = double_stack_get_size_a(dstack);
	size_b = double_stack_get_size_b(dstack);
	while (size_a || size_b)
	{
		
		flip_a = should_flip_a(dstack);
		flip_b = should_flip_b(dstack);

		if (size_a == 1)
		{
			flip_a = FALSE;
			size_a = 0;
			double_stack_rotate_a(dstack);
		}
		if (size_b == 1)
		{
			flip_b = FALSE;
			size_b = 0;
			double_stack_rotate_b(dstack);
		}

		if (flip_a && flip_b)
			double_stack_swap_both(dstack);
		else if (flip_a)
			double_stack_swap_a(dstack);
		else if (flip_b)
			double_stack_swap_b(dstack);
		if (size_a && size_b)
		{
			double_stack_rotate_both(dstack);
			double_stack_rotate_both(dstack);
		}
		else if (size_a)
		{
			double_stack_rotate_a(dstack);
			double_stack_rotate_a(dstack);
		}
		else if (size_b)
		{
			double_stack_rotate_b(dstack);
			double_stack_rotate_b(dstack);
		}
		size_a -= get_min(2, size_a);
		size_b -= get_min(2, size_b);
	}
}
