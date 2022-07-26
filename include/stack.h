/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:26:43 by yoav              #+#    #+#             */
/*   Updated: 2022/07/26 11:43:28 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_stack
{
	t_list	*lst;
	int		size;
}				t_stack;


t_stack	*stack_create(void);
void	stack_free(t_stack *s);

#endif
