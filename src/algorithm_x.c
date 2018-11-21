/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:28:56 by yochered          #+#    #+#             */
/*   Updated: 2018/11/19 12:28:59 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				compare_cols(long x, t_list *col)
{
	while (col)
	{
		if (*(long *)col->content == x)
			return (1);
		col = col->next;
	}
	return (0);
}

static void		reload_matrix(t_dlist **head)
{
	t_dlist *elem;

	while (g_del_top != -1)
	{
		elem = pop(0);
		if (!elem->cords[X])
			restore_row(head, elem);
		else if (!elem->cords[Y])
			restore_col(head, elem);
	}
}

void			clear_stack(void)
{
	while (g_res_top != -1)
		pop(1);
}

static void		reduce_matrix(t_dlist **head, t_dlist *row, int k)
{
	t_dlist	*tmp;
	t_dlist	*tmp1;

	if ((tmp = ft_dlstfind(*head, 0, row->cords[Y])))
		tmp = tmp->right;
	while (tmp && tmp->right)
	{
		tmp1 = (ft_dlstfind(*head, tmp->cords[X], 0))->down;
		while (tmp1 && tmp1->down)
		{
			delete_row(head, tmp1->cords[Y]);
			if (tmp1->down->cords[Y] <= tmp1->cords[Y])
				break ;
			tmp1 = tmp1->down;
		}
		delete_col(head, tmp->cords[X]);
		if (tmp->right->cords[X] <= tmp->cords[X])
			break ;
		tmp = tmp->right;
	}
	algorithm(head, k);
}

int				algorithm(t_dlist **head, int num_of_tetriminos)
{
	t_dlist	*pivot;

	if ((*head)->right->c_size == sizeof(char))
	{
		pivot = (*head)->right;
		while (pivot->down && pivot->down->cords[Y] > pivot->cords[Y])
		{
			pivot = pivot->down;
			push(pivot, 1);
			reduce_matrix(head, pivot, num_of_tetriminos);
			reload_matrix(head);
			if (g_res_top == num_of_tetriminos - 1)
				return (1);
			else if (g_res_top > num_of_tetriminos - 1)
				return (0);
		}
	}
	return (0);
}
