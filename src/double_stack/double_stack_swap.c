/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 09:27:35 by yoav              #+#    #+#             */
/*   Updated: 2022/07/28 13:22:11 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"

void	double_stack_swap_a(t_double_stack *dstack)
{
	ft_printf("sa\n");
	stack_swap_top(dstack->a);
}

void	double_stack_swap_b(t_double_stack *dstack)
{
	ft_printf("sb\n");
	stack_swap_top(dstack->b);
}

void	double_stack_swap_both(t_double_stack *dstack)
{
	ft_printf("ss\n");
	stack_swap_top(dstack->a);
	stack_swap_top(dstack->b);
}
