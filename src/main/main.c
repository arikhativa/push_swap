/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:33:53 by yoav              #+#    #+#             */
/*   Updated: 2022/08/03 16:45:40 by yrabby           ###   ########.fr       */
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
		ft_printf("Error\n");
		return (ERROR);
	}
	dstack = double_stack_create();
	if (ERROR == double_stack_init(dstack, ac, av))
	{
		double_stack_free(dstack);
		ft_printf("Error\n");
		return (ERROR);
	}
	if (!double_stack_is_done(dstack))
		sort(dstack);
	// double_stack_print(dstack);
	double_stack_free(dstack);
	return (SUCCESS);
}


