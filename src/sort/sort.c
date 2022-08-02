/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:40:24 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/02 12:01:26 by yoav             ###   ########.fr       */
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
	else if (6 == size)
		sort_six(dstack);
	else
		merge_sort(dstack);
}