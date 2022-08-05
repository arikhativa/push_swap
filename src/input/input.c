/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:25:57 by yoav              #+#    #+#             */
/*   Updated: 2022/08/05 14:16:29 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

static int	is_line_valid(register char *s)
{
	int	num;

	s = push_swap_skip_space(s);
	if (!*s)
		return (FALSE);
	while (*s)
	{
		if (ERROR == atoi_overflow(s, &num))
			return (FALSE);
		s = skip_sign(s);
		s = skip_digit(s);
		if (*s && !push_swap_is_space(*s))
			return (FALSE);
		s = push_swap_skip_space(s);
	}
	return (TRUE);
}

int	input_is_valid(int size, char **tab)
{
	int	i;
	int	stt;

	if (2 > size)
		return (FALSE);
	i = 1;
	while (i < size)
	{
		stt = is_line_valid(tab[i]);
		if (FALSE == stt)
			return (FALSE);
		++i;
	}
	return (TRUE);
}
