/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get_by_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:25:26 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/03 18:27:48 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_get_value_by_index(t_stack *stack, int index)
{
	int		i;
	t_dll	*runner;

	runner = stack->lst;
	if (runner && !runner->next)
		return (runner->value);
	i = 0;
	while (runner)
	{
		if (i == index)
			return (runner->value);
		runner = runner->next;
		++i;
	}
	return (ERROR);
}
