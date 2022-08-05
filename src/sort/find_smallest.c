/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:56:07 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/05 14:10:36 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	find_smallest(t_double_stack *dstack)
{
	t_dll			*list;
	register t_dll	*runner;
	int				value;
	int				i;

	list = *stack_get_list(dstack->a);
	runner = list;
	value = runner->value;
	while (runner)
	{
		if (runner->value < value)
			value = runner->value;
		runner = runner->next;
	}
	i = 0;
	runner = list;
	while (runner)
	{
		if (runner->value == value)
			return (i);
		runner = runner->next;
		++i;
	}
	return (i);
}
