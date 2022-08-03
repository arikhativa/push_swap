/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:50:57 by yoav              #+#    #+#             */
/*   Updated: 2022/08/03 12:15:24 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"

static int	validate(t_dll *elem, void *param)
{
	int	*num;

	num = param;
	if (elem->value == *num)
		return (ERROR);
	return (SUCCESS);
}

int	double_stack_is_duplicates(t_double_stack *dstack)
{
	int		num;
	int		stt;
	t_dll	*runner;

	runner = dstack->a->lst;
	if (runner && !runner->next)
		return (FALSE);
	stt = SUCCESS;
	while (runner->next && SUCCESS == stt)
	{
		num = runner->value;
		stt = dll_iterate(runner->next, validate, &num);
		runner = runner->next;
	}
	if (SUCCESS == stt)
		return (FALSE);
	return (TRUE);
}
