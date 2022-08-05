/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:56:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/05 14:11:14 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	get_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	generic_push(t_double_stack *dstack, int round,	t_handle_push f, \
	t_sort_meta *m)
{
	register int	i;

	i = 0;
	while ((i < round) && (m->a_run_size || m->b_run_size))
	{
		f(dstack, m);
		++i;
	}
}
