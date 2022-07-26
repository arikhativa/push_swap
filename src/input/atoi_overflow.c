/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_overflow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:21:37 by yoav              #+#    #+#             */
/*   Updated: 2022/07/26 17:02:52 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libft.h"

static int	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || \
			c == '\f' || c == '\r' || c == ' ');
}

static char	*skip_space(char *s)
{
	while (is_space(*s))
		++s;
	return (s);
}

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
	s = skip_space(s);
	if (0 == ft_strncmp("-2147483648", s, 10))
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
