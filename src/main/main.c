/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:33:53 by yoav              #+#    #+#             */
/*   Updated: 2022/08/05 14:17:47 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char **av)
{
	t_double_stack	*dstack;

	if (1 == ac)
		return (SUCCESS);
	if (!input_is_valid(ac, av))
	{
		ft_putstr_fd("Error\n", 2);
		return (ERROR);
	}
	dstack = double_stack_create();
	if (ERROR == double_stack_init(dstack, ac, av))
	{
		double_stack_free(dstack);
		ft_putstr_fd("Error\n", 2);
		return (ERROR);
	}
	if (!double_stack_is_done(dstack))
		sort(dstack);
	double_stack_free(dstack);
	return (SUCCESS);
}
