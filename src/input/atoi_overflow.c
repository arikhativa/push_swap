/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_overflow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:21:37 by yoav              #+#    #+#             */
/*   Updated: 2022/08/03 12:15:06 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

static char	*skip_get_sign(char *s, int *sign)
{
	*sign = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			*sign *= -1;
		++s;
	}
	return (s);
}

int	inc(const char *s, int *ret)
{
	int	num;
	int	tmp;

	num = 0;
	tmp = 0;
	while (ft_isdigit(*s))
	{
		tmp = num;
		num = (num * 10);
		if (num / 10 != tmp)
			return (ERROR);
		tmp = (*s - '0');
		num += tmp;
		if (num < tmp)
			return (ERROR);
		++s;
	}
	*ret = num;
	return (SUCCESS);
}

int	atoi_overflow(const char *nptr, int *ret)
{
	char	*s;
	int		num;
	int		sign;

	if (!nptr)
		return (ERROR);
	s = (char *)nptr;
	num = 0;
	s = push_swap_skip_space(s);
	if (0 == ft_strncmp("-2147483648", s, __INT_MAX__))
	{
		*ret = -2147483648;
		return (SUCCESS);
	}
	s = skip_get_sign(s, &sign);
	if (ERROR == inc(s, &num))
		return (ERROR);
	*ret = num * sign;
	return (SUCCESS);
}
