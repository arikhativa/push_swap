/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_meta.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:37:10 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/03 11:39:55 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_meta_init(t_sort_meta *meta, t_double_stack *dstack, int round)
{
	meta->a_size = double_stack_get_size_a(dstack);
	meta->a_clean_nodes = get_min(meta->a_size, round / 2);
	meta->b_size = double_stack_get_size_b(dstack);
	meta->b_clean_nodes = get_min(meta->b_size, round / 2);
}

void	sort_meta_set_clean_nodes(t_sort_meta *meta, int round)
{
	meta->a_clean_nodes = get_min(meta->a_size, round / 2);
	meta->b_clean_nodes = get_min(meta->b_size, round / 2);
}

void	sort_meta_set_size(t_sort_meta *meta)
{
	meta->a_size -= meta->a_clean_nodes;
	meta->b_size -= meta->b_clean_nodes;
}
