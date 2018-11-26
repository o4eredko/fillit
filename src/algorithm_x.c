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

void	reload_matrix(t_dlist **head)
{
	t_dlist *elem;

	while (g_del_top != -1 && g_del_stack[g_del_top])
	{
		elem = pop(0);
		if (!elem->cords[X])
			restore_row(head, elem);
		else if (!elem->cords[Y])
			restore_col(head, elem);
	}
	pop(0);
}

void	delete_branch(t_dlist **head, t_dlist *tmp, t_dlist *row_end)
{
	t_dlist *tmp1;
	t_dlist	*col_end;

	while (tmp)
	{
		if ((tmp1 = ft_dlstfind(*head, tmp->cords[X], 0)))
			tmp1 = tmp1->down;
		col_end = ft_dlstgetend(tmp1, Y);
		while (tmp1)
		{
			delete_row(head, tmp1->cords[Y]);
			if (tmp1 == col_end)
				break ;
			tmp1 = tmp1->down;
		}
		delete_col(head, tmp->cords[X]);
		if (tmp == row_end)
			break ;
		tmp = tmp->right;
	}
}

int		reduce_matrix(t_dlist **head, t_dlist *row, int k)
{
	t_dlist	*tmp;
	t_dlist	*row_end;

	if ((tmp = ft_dlstfind(*head, 0, row->cords[Y])))
	{
		tmp = tmp->right;
		row_end = ft_dlstgetend(tmp, X);
		push(NULL, 0);
		delete_branch(head, tmp, row_end);
	}
	return (algorithm(head, k));
}

int		cmp_shapes(t_dlist *sh1, t_dlist *sh2)
{
	sh1 = sh1->right->right;
	sh2 = sh2->right->right;
	if (sh1->right->cords[X] - sh1->cords[X]
		== sh2->right->cords[X] - sh2->cords[X]
	&& sh1->right->right->cords[X] - sh1->cords[X]
		== sh2->right->right->cords[X] - sh2->cords[X]
	&& sh1->right->right->right->cords[X] - sh1->cords[X]
		== sh2->right->right->right->cords[X] - sh2->cords[X])
		return (1);
	return (0);
}

int		algorithm(t_dlist **head, int num_of_tetriminos)
{
	t_dlist	*pivot;
	int		res;

	res = 0;
	if ((pivot = (*head)->right))
	{
		while (!res && pivot->down && pivot->down->cords[Y] > pivot->cords[Y])
		{
			pivot = pivot->down;
			push(ft_dlstfind(*head, 0, pivot->cords[Y]), 1);
			if (!(res = reduce_matrix(head, pivot, num_of_tetriminos)))
				pop(1);
			reload_matrix(head);
		}
	}
	return (g_res_top == num_of_tetriminos - 1);
}
