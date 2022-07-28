/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:46:21 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/28 13:00:12 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

#include "double_stack.h"
#include "generic.h"

void	sort_first_round(t_double_stack *dstack, int size);
void	merge_sort(t_double_stack *dstack);
void	h_push_b(t_double_stack *dstack, int *size_a, int *size_b);
void	h_push_a(t_double_stack *dstack, int *size_a, int *size_b);

#endif
