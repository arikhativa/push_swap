/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:00:46 by yoav              #+#    #+#             */
/*   Updated: 2022/08/03 12:39:06 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"
#include "libft.h"

t_double_stack	*double_stack_create(void)
{
	t_double_stack	*dstack;

	dstack = ft_calloc(1, sizeof(t_double_stack));
	if (!dstack)
		return (NULL);
	dstack->a = stack_create();
	if (!dstack->a)
	{
		free(dstack);
		return (NULL);
	}
	dstack->b = stack_create();
	if (!dstack->b)
	{
		stack_free(dstack->a);
		free(dstack);
		return (NULL);
	}
	return (dstack);
}

void	double_stack_free(t_double_stack *dstack)
{
	if (dstack)
	{
		stack_free(dstack->a);
		stack_free(dstack->b);
		ft_bzero(dstack, sizeof(t_double_stack));
		free(dstack);
	}
}
