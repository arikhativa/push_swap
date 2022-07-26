/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:33:53 by yoav              #+#    #+#             */
/*   Updated: 2022/07/26 14:47:15 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "dll.h"
#include "double_stack.h"
#include "input.h"

int	main(int ac, char **av)
{
	t_double_stack	*dstack;

	dstack = double_stack_create();
	double_stack_free(dstack);
	int ret;
	int stt = atoi_overflow("123", &ret);
	printf("stt: %d\nret: %d\n",stt, ret); 
	
	return (SUCCESS);
}
