/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:10:50 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/28 13:00:05 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERIC_H
# define GENERIC_H

#include "define.h"
#include "double_stack.h"

typedef void (*t_handle_push)(t_double_stack *dstack, int *size_a, int *size_b);

void	generic_push(t_double_stack *dstack, int round,	t_handle_push f, int *size_a, int *size_b);
int		get_min(int a, int b);

#endif
