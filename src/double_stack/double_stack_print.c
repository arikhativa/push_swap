/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:12:59 by yoav              #+#    #+#             */
/*   Updated: 2022/08/05 14:15:40 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"

void	double_stack_print(t_double_stack *dstack)
{
	ft_printf("A: ");
	stack_print(dstack->a);
	ft_printf("B: ");
	stack_print(dstack->b);
	ft_printf("\n");
}
