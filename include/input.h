/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:26:30 by yoav              #+#    #+#             */
/*   Updated: 2022/08/05 13:21:16 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "libft.h"
# include "define.h"

int		push_swap_is_space(char c);
char	*push_swap_skip_space(char *s);
char	*skip_sign(char *s);
char	*skip_digit(char *s);
int		input_is_valid(int size, char **tab);
int		atoi_overflow(const char *nptr, int *ret);

#endif
