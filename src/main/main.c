/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:33:53 by yoav              #+#    #+#             */
/*   Updated: 2022/07/26 13:56:41 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "dll.h"
#include "stack.h"

int	main(int ac, char **av)
{
	t_stack	*s;
	t_dll	*e;

	s = stack_create();
	
	stack_push(s, dll_create_elem(1));
	stack_push(s, dll_create_elem(2));
	stack_push(s, dll_create_elem(3));
	stack_print(s);
	e = stack_pop(s);
	dll_free_elem(e);
	e = stack_pop(s);
	dll_free_elem(e);
	e = stack_pop(s);
	dll_free_elem(e);

	stack_print(s);

	stack_push(s, dll_create_elem(3));
	stack_print(s);
	stack_free(s);

	return (SUCCESS);
}
