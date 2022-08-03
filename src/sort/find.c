/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:56:07 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/03 17:37:12 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int	small_handler(t_dll *elem, void *param)
{
	int	*num;

	num = param;
	if (elem->value < *num)
		*num = elem->value;
	return (SUCCESS);
}

static int	big_handler(t_dll *elem, void *param)
{
	int	*num;

	num = param;
	if (elem->value > *num)
		*num = elem->value;
	return (SUCCESS);
}

static int	find_index(t_stack *stack, t_dll_iter find_num)
{
	int		num;
	int		i;
	t_dll	*runner;

	runner = stack->lst;
	if (runner && !runner->next)
		return (0);
	num = runner->value;
	dll_iterate(runner->next, find_num, &num);
	i = 0;
	while (runner)
	{
		if (runner->value == num)
			return (i);
		runner = runner->next;
		++i;
	}
	return (ERROR);
}

int	find_smallest(t_stack *stack)
{
	return (find_index(stack, small_handler));
}

int	find_biggest(t_stack *stack)
{
	return (find_index(stack, big_handler));
}
