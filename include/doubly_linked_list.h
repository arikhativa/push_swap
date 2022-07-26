/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:50:43 by yoav              #+#    #+#             */
/*   Updated: 2022/07/26 12:35:27 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLY_LINKED_LIST_H
# define DOUBLY_LINKED_LIST_H

# include <stddef.h>
# include <stdlib.h>

typedef	struct	s_dll	t_dll;

typedef struct	s_dll
{
	int		value;
	t_dll	*next;
	t_dll	*prev;
}				t_dll;

void	dll_print(t_dll *lst);
t_dll	*dll_create_elem(int value);
void	dll_free_elem(t_dll *elem);
void	dll_clear_list(t_dll *lst);
t_dll	*dll_remove_elem(t_dll *elem);
t_dll	*dll_remove_last_elem(t_dll *lst);
void	dll_add_after(t_dll *lst, t_dll *new_elem);
void	dll_add_before(t_dll *lst, t_dll *new_elem);
void	dll_add_last(t_dll **lst, t_dll *new_elem);
void	swap(int *a, int *b);


#endif
