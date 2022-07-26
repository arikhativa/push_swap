/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:09:36 by yoav              #+#    #+#             */
/*   Updated: 2022/07/26 13:56:41 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "dll.h"

void	dll_print(t_dll *lst)
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
	int nv = -1;
	int pv = -1;
	int	v = elem->value;

	if (elem->next)
		nv = elem->next->value;
	if (elem->prev)
		pv = elem->prev->value;
	
	ft_printf("value: %d\nnext value: %d\nprev value: %d\n", v, nv, pv);
}
