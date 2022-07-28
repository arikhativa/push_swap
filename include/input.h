/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:26:30 by yoav              #+#    #+#             */
/*   Updated: 2022/07/28 15:24:24 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

int	push_swap_is_space(char c);
char	*push_swap_skip_space(char *s);
int	input_is_valid(int size, char **tab);
int	atoi_overflow(const char *nptr, int *ret);

#endif
