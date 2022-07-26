/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:48:20 by yoav              #+#    #+#             */
/*   Updated: 2022/07/26 14:25:08 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stack.h"
#include "dll.h"

void	stack_print(t_stack *s)
{
	ft_printf("[%d]\t-\t", stack_get_size(s));
	dll_print(*stack_get_list(s));
}
