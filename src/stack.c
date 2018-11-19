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

void	push(t_dlist ***stack, t_dlist *elem, int stack_type)
{
	if (!stack_type)
	{
		g_del_stack++;
		(*stack)[g_del_stack] = elem;
	}
	else
	{
		g_res_stack++;
		(*stack)[g_res_stack] = elem;
	}
}

t_dlist	*pop(t_dlist **stack, int stack_type)
{

	if (!stack_type)
	{
		g_del_stack--;
		return (stack[g_del_stack + 1]);
	}
	else
		{
		g_res_stack--;
		return (stack[g_res_stack + 1]);
	}
}

void	create_del_stack(t_dlist *list, t_dlist ***stack)
{
	int cols;
	int rows;

	cols = (ft_dlstgetend(list, X))->cords[X];
	rows = (ft_dlstgetend(list, Y))->cords[Y];
	g_del_stack = -1;
	(*stack) = (t_dlist **)ft_memalloc(sizeof(t_dlist *) * (cols + rows));
	if (!(*stack))
		return ;
}

void	create_res_stack(t_dlist *list, t_dlist ***stack)
{
	int rows;

	rows = (ft_dlstgetend(list, Y))->cords[Y];
	g_res_stack = -1;
	(*stack) = (t_dlist **)ft_memalloc(sizeof(t_dlist *) * rows);
	if (!(*stack))
		return ;
}
