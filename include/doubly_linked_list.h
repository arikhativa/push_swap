/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:50:43 by yoav              #+#    #+#             */
/*   Updated: 2022/07/26 11:56:18 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLY_LINKED_LIST_H
# define DOUBLY_LINKED_LIST_H

# include <stddef.h>

typedef struct	s_dll
{
	int		value;
	void	*next;
	void	*prev;
}				t_dll;

#endif
