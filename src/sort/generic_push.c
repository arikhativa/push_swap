/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:56:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/27 15:15:42 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generic.h"

int	get_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	generic_push(t_double_stack *dstack, int round,	t_handle_push f)
{
	int	i;
	int	size_a;
	int	size_b;

	size_a = get_min((round / 2), double_stack_get_size_a(dstack));
	size_b = get_min((round / 2), double_stack_get_size_b(dstack));
	i = 0;
	while ((i < round) && (size_a || size_b))
	{
		f(dstack, &size_a, &size_b);
		++i;
	}
}