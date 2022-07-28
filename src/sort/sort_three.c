/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:48:16 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/28 14:20:12 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

t_value_order get_order(int a, int b, int c)
{
	if ((a > b) && (a > c)) // B??
	{
		if (b > c)
			return (BMS);
		else
			return (BSM);
	}
	if (b > c) // ?B?
	{
		if (a > c)
			return (MBS);
		else
			return (SBM);
	}
	// ??B
	if (a > b)
		return (MSB);
	else
		return (SMB);
}

void	sort_three(t_double_stack *dstack)
{
	t_value_order	order;
	t_dll			*list;

	list = *stack_get_list(dstack->a);
	order = get_order(list->value, list->next->value, list->next->next->value);
	if (BMS == order)
		return ;
	else if (BSM == order)
		double_stack_swap_a(dstack);
	else if (MBS == order)
	{
		double_stack_rev_rotate_a(dstack);
		double_stack_swap_a(dstack);
	}
	else if (MSB == order)
		double_stack_rotate_a(dstack);
	else if (SBM == order)
		double_stack_rev_rotate_a(dstack);
	else if (SMB == order)
	{
		double_stack_rotate_a(dstack);
		double_stack_swap_a(dstack);
	}
}
