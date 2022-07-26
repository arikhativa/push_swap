/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:26:07 by yoav              #+#    #+#             */
/*   Updated: 2022/07/26 12:47:04 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"
#include "doubly_linked_list.h"

static void	stack_del_elem(void *elem)
{
	(void)elem;
	return ;
}

t_stack	*stack_create(void)
{
	t_stack	*s;

	s = ft_calloc(1, sizeof(t_stack));
	if (!s)
		return (NULL);
	return (s);
}

void	stack_free(t_stack *s)
{
	dll_clear_list(s->lst);
	ft_bzero(s, sizeof(s));
	free(s);
}
