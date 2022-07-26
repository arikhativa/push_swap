/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:48:20 by yoav              #+#    #+#             */
/*   Updated: 2022/07/26 13:11:09 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stack.h"
#include "doubly_linked_list.h"

void	stack_print(t_stack *s)
{
	ft_printf("stack->size: %d\n", stack_get_size(s));
	dll_print(*stack_get_list(s));
}
