/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:26:43 by yoav              #+#    #+#             */
/*   Updated: 2022/07/26 13:35:19 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include "doubly_linked_list.h"

typedef struct s_stack
{
	t_dll	*lst;
	int		size;
}				t_stack;

t_stack	*stack_create(void);
void	stack_free(t_stack *s);

// set
void	stack_rotate(t_stack *s);
void	stack_push(t_stack *s, t_dll *elem);
t_dll	*stack_pop(t_stack *s);


// get
t_dll	**stack_get_list(t_stack *s);
int		stack_get_size(t_stack *s);

// print
void	stack_print(t_stack *s);



#endif
