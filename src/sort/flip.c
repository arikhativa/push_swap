/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:50:42 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/28 13:51:01 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	should_flip_a(t_double_stack *dstack)
{
	int	top;
	int	second_to_top;

	top = double_stack_get_top_value_a(dstack);
	second_to_top = double_stack_get_second_to_top_value_a(dstack);
	return (top > second_to_top);
}

int	should_flip_b(t_double_stack *dstack)
{
	int	top;
	int	second_to_top;

	top = double_stack_get_top_value_b(dstack);
	second_to_top = double_stack_get_second_to_top_value_b(dstack);
	return (top > second_to_top);
}
