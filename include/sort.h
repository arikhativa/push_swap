/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:46:21 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/02 12:17:12 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "double_stack.h"
# include "generic.h"

typedef struct	s_sort_meta
{
	int	a_size;
	int	a_clean_nodes;
	int	b_size;
	int	b_clean_nodes;
}				t_sort_meta;

void	sort(t_double_stack *dstack);
void	sort_two(t_double_stack *dstack);
void	sort_three(t_double_stack *dstack);
void	sort_four(t_double_stack *dstack);
void	sort_five(t_double_stack *dstack);
void	sort_six(t_double_stack *dstack);
void	sort_first_round(t_double_stack *dstack, int size);
void	merge_sort(t_double_stack *dstack);
void	h_push_b(t_double_stack *dstack, int *size_a, int *size_b);
void	h_push_a(t_double_stack *dstack, int *size_a, int *size_b);
int		should_flip_a(t_double_stack *dstack);
int		should_flip_b(t_double_stack *dstack);
int		find_smallest(t_double_stack *dstack);

typedef enum e_value_order {
	BMS,
	BSM,
	MBS,
	MSB,
	SBM,
	SMB
}			t_value_order;

#endif
