/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:50:43 by yoav              #+#    #+#             */
/*   Updated: 2022/07/26 13:52:37 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLL_H
# define DLL_H

# include <stddef.h>
# include <stdlib.h>

typedef	struct	s_dll	t_dll;

typedef struct	s_dll
{
	int		value;
	t_dll	*next;
	t_dll	*prev;
}				t_dll;

// is
int	dll_is_last_elem(t_dll *elem);

// print
void	dll_print(t_dll *lst);
void	dll_print_elem(t_dll *elem);

t_dll	*dll_create_elem(int value);
void	dll_free_elem(t_dll *elem);
void	dll_clear_list(t_dll *lst);
void	dll_swap_value(t_dll *a, t_dll *b);

// add
void	dll_add_after(t_dll *lst, t_dll *new_elem);
void	dll_add_before(t_dll *lst, t_dll *new_elem);
void	dll_add_last(t_dll **lst, t_dll *new_elem);

// remove
t_dll	*dll_remove_first_elem(t_dll *lst);
t_dll	*dll_remove_elem(t_dll *elem);
t_dll	*dll_remove_last_elem(t_dll *lst);

#endif