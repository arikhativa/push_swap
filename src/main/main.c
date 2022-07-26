/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:33:53 by yoav              #+#    #+#             */
/*   Updated: 2022/07/26 14:23:06 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "dll.h"
#include "double_stack.h"

int	main(int ac, char **av)
{
	t_double_stack	*dstack;

	dstack = double_stack_create();

	double_stack_push_a(dstack, 1);
	double_stack_push_a(dstack, 5);
	double_stack_print(dstack);
	double_stack_rotate_a(dstack);
	double_stack_print(dstack);

	double_stack_free(dstack);
	return (SUCCESS);
}
