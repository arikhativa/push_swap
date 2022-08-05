/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:46:21 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/05 13:21:06 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "double_stack.h"

typedef struct s_first_round_meta
{
	int	a_size;
	int	a_flip;
	int	b_size;
	int	b_flip;
}				t_first_round_meta;

typedef struct s_sort_meta
{
	int	a_size;
	int	a_run_size;
	int	b_size;
	int	b_run_size;
}				t_sort_meta;

// generic
typedef void	(*t_handle_push)(t_double_stack *dstack, t_sort_meta *m);

void	generic_push(t_double_stack *dstack, int round,	t_handle_push f, \
	t_sort_meta *m);
int		get_min(int a, int b);

// sort_meta
void	sort_meta_init(t_sort_meta *meta, t_double_stack *dstack, int round);
void	sort_meta_set_run_size(t_sort_meta *meta, int round);
void	sort_meta_set_size(t_sort_meta *meta);

void	sort(t_double_stack *dstack);
void	sort_two(t_double_stack *dstack);
void	sort_three(t_double_stack *dstack);
void	sort_four(t_double_stack *dstack);
void	sort_five(t_double_stack *dstack);
void	sort_six(t_double_stack *dstack);
void	sort_first_round(t_double_stack *dstack);
void	merge_sort(t_double_stack *dstack);
void	h_push_b(t_double_stack *dstack, t_sort_meta *m);
void	h_push_a(t_double_stack *dstack, t_sort_meta *m);
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
