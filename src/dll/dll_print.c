/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:09:36 by yoav              #+#    #+#             */
/*   Updated: 2022/08/05 14:14:56 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"

void	dll_print(register t_dll *lst)
{
	ft_printf("[ ");
	while (lst)
	{
		ft_printf("% 4d", lst->value);
		lst = lst->next;
	}
	ft_printf(" ]\n");
}

void	dll_print_elem(t_dll *elem)
{
	int	nv;
	int	pv;
	int	v;

	nv = -1;
	pv = -1;
	v = elem->value;
	if (elem->next)
		nv = elem->next->value;
	if (elem->prev)
		pv = elem->prev->value;
	ft_printf("value: %d\nnext value: %d\nprev value: %d\n", v, nv, pv);
}
