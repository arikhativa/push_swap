/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:33:53 by yoav              #+#    #+#             */
/*   Updated: 2022/07/28 09:44:04 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "dll.h"
#include "double_stack.h"
#include "ft_printf.h"
#include "sort.h"
#include "input.h"

int	main(int ac, char **av)
{
	t_double_stack	*dstack;

	if (!input_is_valid(ac, av))
	{
		ft_printf("ERROR\n");
		return (ERROR);
	}
	dstack = double_stack_create();
	if (ERROR == double_stack_init(dstack, ac, av))
	{
		double_stack_free(dstack);
		ft_printf("ERROR\n");
		return (ERROR);
	}
	double_stack_print(dstack);
	merge_sort(dstack);
	double_stack_print(dstack);
	double_stack_free(dstack);
	int ret;
	
	return (SUCCESS);
}
