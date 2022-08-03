/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:20:01 by yoav              #+#    #+#             */
/*   Updated: 2022/08/03 12:39:33 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"

static char *next_input(char *s)
{
	s = skip_sign(s);
	s = skip_digit(s);
	s = push_swap_skip_space(s);
	return (s);
}

int	parse_line(t_double_stack *dstack, char *s)
{
	int		num;
	t_dll	*elem;
	t_stack	*tmp_stack;

	tmp_stack = stack_create();
	if (!tmp_stack)
		return (ERROR);
	s = push_swap_skip_space(s);
	while (*s)
	{
		if (ERROR == atoi_overflow(s, &num))
			return (ERROR);
		elem = dll_create_elem(num);
		if (!elem)
			return (ERROR);
		stack_push(tmp_stack, elem);
		s = next_input(s);
	}
	while (!stack_is_empty(tmp_stack))
		stack_push(dstack->a, stack_pop(tmp_stack));
	stack_free(tmp_stack);
	return (SUCCESS);
}

int	double_stack_init(t_double_stack *dstack, int size, char **tab)
{
	int	i;

	i = size - 1;
	while (i)
	{
		if (ERROR == parse_line(dstack, tab[i]))
			return (ERROR);
		--i;
	}
	if (TRUE == double_stack_is_duplicates(dstack))
		return (ERROR);
	return (SUCCESS);
}
