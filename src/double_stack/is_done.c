/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_done.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:10:16 by yoav              #+#    #+#             */
/*   Updated: 2022/08/02 11:14:47 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"

static int	validate(t_dll *elem, void *param)
{
	int	*num;

	num = param;
	if (elem->value < *num)
	{
		*num = elem->value;
		return (SUCCESS);
	}
	return (ERROR);
}

int	double_stack_is_done(t_double_stack *dstack)
{
	int		num;
	int		stt;
	t_dll	*runner;

	runner = dstack->a->lst;
	if (runner && !runner->next)
		return (TRUE);
	num = runner->value;
	stt = dll_iterate(runner->next, validate, &num);
	return  (SUCCESS == stt);
}
