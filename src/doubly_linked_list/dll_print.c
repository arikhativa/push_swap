/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:09:36 by yoav              #+#    #+#             */
/*   Updated: 2022/07/26 12:12:43 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "doubly_linked_list.h"

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
