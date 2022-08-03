/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:26:43 by yoav              #+#    #+#             */
/*   Updated: 2022/08/03 18:27:41 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include "dll.h"

typedef struct s_stack
{
	t_dll	*lst;
	int		size;
}				t_stack;

t_stack	*stack_create(void);
void	stack_free(t_stack *s);

// rotate
void	stack_rev_rotate(t_stack *s);
void	stack_rotate(t_stack *s);

// set
void	stack_push(t_stack *s, t_dll *elem);
t_dll	*stack_pop(t_stack *s);

// swap
void	stack_swap_top(t_stack *s);

// get
t_dll	**stack_get_list(t_stack *s);
int		stack_get_size(t_stack *s);
int	stack_get_top_value(t_stack *s);
int	stack_get_second_to_top_value(t_stack *s);
int	stack_is_empty(t_stack *s);
int	stack_get_value_by_index(t_stack *stack, int index);

// print
void	stack_print(t_stack *s);



#endif
