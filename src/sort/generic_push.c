/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:56:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/27 17:13:17 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generic.h"

int	get_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	generic_push(t_double_stack *dstack, int round,	t_handle_push f, int *size_a, int *size_b)
{
	int	i;

	i = 0;
	while ((i < round) && (*size_a || *size_b))
	{
		f(dstack, size_a, size_b);
		++i;
	}
}