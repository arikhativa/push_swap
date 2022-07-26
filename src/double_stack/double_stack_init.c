/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:20:01 by yoav              #+#    #+#             */
/*   Updated: 2022/07/26 17:25:49 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "double_stack.h"
#include "define.h"

int	double_stack_init(t_double_stack *dstack, int size, char **tab)
{
	int	i;
	int	num;
	int stt;

	i = size - 1;
	while (i)
	{
		atoi_overflow(tab[i], &num);
		if (ERROR == double_stack_push_a(dstack, num))
			return (ERROR);
		--i;
	}
	return (SUCCESS);
}
