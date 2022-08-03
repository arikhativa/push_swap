/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:26:07 by yoav              #+#    #+#             */
/*   Updated: 2022/08/03 16:14:30 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"
#include "dll.h"

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

int	stack_is_empty(t_stack *s)
{
	return (0 == s->size);
}
