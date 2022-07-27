/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:59:15 by yoav              #+#    #+#             */
/*   Updated: 2022/07/27 14:00:10 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_STACK_H
# define DOUBLE_STACK_H

# include "stack.h"

typedef	struct	s_double_stack
{
	t_stack	*a;
	t_stack	*b;
}				t_double_stack;

t_double_stack	*double_stack_create(void);
void			double_stack_free(t_double_stack *dstack);

// get
int	double_stack_get_size_a(t_double_stack *dstack);
int	double_stack_get_size_b(t_double_stack *dstack);
int	double_stack_get_top_value_a(t_double_stack *dstack);
int	double_stack_get_top_value_b(t_double_stack *dstack);

// set
void	double_stack_rotate_a(t_double_stack *dstack);
void	double_stack_rotate_b(t_double_stack *dstack);
int		double_stack_init(t_double_stack *dstack, int size, char **tab);

// push
int		double_stack_push_a(t_double_stack *dstack, int i);
void	double_stack_push_a_to_b(t_double_stack *dstack);
void	double_stack_push_b_to_a(t_double_stack *dstack);

// pop
t_dll	*double_stack_pop_a(t_double_stack *dstack);
t_dll	*double_stack_pop_b(t_double_stack *dstack);

// print
void	double_stack_print(t_double_stack *dstack);

#endif
