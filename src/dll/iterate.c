/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:53:07 by yoav              #+#    #+#             */
/*   Updated: 2022/08/05 14:08:28 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"

int	dll_iterate(register t_dll *lst, t_dll_iter f, void *param)
{
	register int	stt;

	stt = SUCCESS;
	while (lst && SUCCESS == stt)
	{
		stt = f(lst, param);
		lst = lst->next;
	}
	return (stt);
}
