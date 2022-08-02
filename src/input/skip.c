/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:29:54 by yoav              #+#    #+#             */
/*   Updated: 2022/08/02 10:32:09 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

static int	is_sign(char c)
{
	return (c == '-' || c == '+');
}

char	*skip_sign(char *s)
{
	if (is_sign(*s))
		++s;
	return (s);
}

int	push_swap_is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || \
			c == '\f' || c == '\r' || c == ' ');
}

char	*push_swap_skip_space(char *s)
{
	while (push_swap_is_space(*s))
		++s;
	return (s);
}

char	*skip_digit(char *s)
{
	while (ft_isdigit(*s))
		++s;
	return (s);
}
