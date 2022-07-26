/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:49:08 by yoav              #+#    #+#             */
/*   Updated: 2022/07/26 13:10:43 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "doubly_linked_list.h"

t_dll	**stack_get_list(t_stack *s)
{
	return (&(s->lst));
}

int	stack_get_size(t_stack *s)
{
	return (s->size);
}
