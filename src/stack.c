/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:32:44 by yochered          #+#    #+#             */
/*   Updated: 2018/11/19 12:32:46 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	push(t_dlist *elem, int stack_type)
{
	if (!stack_type)
	{
		g_del_top++;
		g_del_stack[g_del_top] = elem;
	}
	else
	{
		g_res_top++;
		g_res_stack[g_res_top] = elem;
	}
}

t_dlist	*pop(int stack_type)
{
	if (!stack_type)
	{
		g_del_top--;
		return (g_del_stack[g_del_top + 1]);
	}
	else
	{
		g_res_top--;
		return (g_res_stack[g_res_top + 1]);
	}
}

void	create_stack(t_dlist *list, int stack_type)
{
	long cols;
    long rows;

	cols = (ft_dlstgetend(list, X))->cords[X];
	rows = (ft_dlstgetend(list, Y))->cords[Y];
	if (!stack_type)
	{
		g_del_top = -1;
		if (!(g_del_stack = (t_dlist **) ft_memalloc(sizeof(t_dlist *)
				* (cols + rows))))
			return ;
	}
	else
	{
		g_res_top = -1;
		if (!(g_res_stack = (t_dlist **)ft_memalloc(sizeof(t_dlist *) * rows)))
			return ;
	}
}
