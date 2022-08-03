/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:25:57 by yoav              #+#    #+#             */
/*   Updated: 2022/08/03 11:53:53 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "define.h"
#include "input.h"

static int	is_line_valid(char *s)
{
	s = push_swap_skip_space(s);
	if (!*s)
		return (FALSE);
	while (*s)
	{
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
	int	num;
	int stt;

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
