/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:33:53 by yoav              #+#    #+#             */
/*   Updated: 2022/07/26 12:45:36 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "doubly_linked_list.h"
#include "stack.h"

int	main(int ac, char **av)
{
	t_dll	*l;
	t_dll	*e;

	l = NULL;
	dll_add_last(&l, dll_create_elem(1));
	dll_add_before(l, dll_create_elem(5));
	dll_print(l);
	e = dll_remove_first_elem(l);
	dll_print(l);
	dll_print(e);
	dll_clear_list(e);
	dll_clear_list(l);

	return (SUCCESS);
}
