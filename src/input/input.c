/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:25:57 by yoav              #+#    #+#             */
/*   Updated: 2022/07/26 17:25:31 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "define.h"
#include "input.h"

static int	is_only_digit(char *s)
{
	if (*s && *s == '-')
		++s;
	if (!*s)
		return (FALSE);
	while (*s && ft_isdigit(*s))
		++s;
	return ('\0' == *s);
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
		stt = atoi_overflow(tab[i], &num);
		if (ERROR == stt)
			return (FALSE);
		stt = is_only_digit(tab[i]);
		if (FALSE == stt)
			return (FALSE);
		++i;
	}
	return (TRUE);
}
