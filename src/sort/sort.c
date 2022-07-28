/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:40:24 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/28 14:45:21 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort(t_double_stack *dstack)
{
	int	size;

	size = double_stack_get_size_a(dstack);
	if (2 == size)
		sort_two(dstack);
	else if (3 == size)
		sort_three(dstack);
	else if (4 == size)
		sort_four(dstack);
	else if (5 == size)
		sort_five(dstack);
	else
		merge_sort(dstack);
}