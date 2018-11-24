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

void		reload_matrix(t_dlist **head)
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


int		reduce_matrix(t_dlist **head, t_dlist *row, int k)
{
	t_dlist	*tmp;
	t_dlist	*tmp1;
	t_dlist	*row_end;
	t_dlist	*col_end;

	if ((tmp = ft_dlstfind(*head, 0, row->cords[Y])))
	{
		tmp = tmp->right;
		row_end = ft_dlstgetend(tmp, X);
		push(NULL, 0);
		while (tmp)
		{
			if ((tmp1 = ft_dlstfind(*head, tmp->cords[X], 0)))
				tmp1 = tmp1->down;
			col_end = ft_dlstgetend(tmp1, Y);
			while (tmp1)
			{
				delete_row(head, tmp1->cords[Y]);
				if (tmp1 == col_end)
					break;
				tmp1 = tmp1->down;
			}
			delete_col(head, tmp->cords[X]);
			if (tmp == row_end)
				break;
			tmp = tmp->right;
		}
	}
	return (algorithm(head, k));
}

int 			compare_shapes(t_dlist *sh1, t_dlist *sh2)
{
	sh1 = sh1->right->right;
	sh2 = sh2->right->right;

	if (sh1->right->cords[X] - sh1->cords[X] == sh2->right->cords[X] - sh2->cords[X]
	&& sh1->right->right->cords[X] - sh1->cords[X] == sh2->right->right->cords[X] - sh2->cords[X]
	&& sh1->right->right->right->cords[X] - sh1->cords[X] == sh2->right->right->right->cords[X] - sh2->cords[X])
		return (1);
	return (0);
}

int 			count_empty_cols(t_dlist *head)
{
	int counter;

	counter = 0;
	head = head->right;
	while (head && head->c_size == sizeof(char))
		head = head->right;
	while (head)
	{
		counter++;
		head = head->right;
	}
	return (counter);
}

int				algorithm(t_dlist **head, int num_of_tetriminos)
{
	t_dlist	*pivot;
	int		res;

//	if (g_counter++ > 2000000)
//		return (-1);
	res = 0;
	if ((pivot = (*head)->right))
	{
		while (!res && pivot->down && pivot->down->cords[Y] > pivot->cords[Y])
		{
			pivot = pivot->down;
			push(ft_dlstfind(*head, 0, pivot->cords[Y]), 1);
			if (!(res = reduce_matrix(head, pivot, num_of_tetriminos)))
			{
				if (g_res_top > 0 && compare_shapes(g_res_stack[g_res_top - 1], g_res_stack[g_res_top]))
				{
					pop(1);
					reload_matrix(head);
					return (0);
				}
				else
					pop(1);
			}
			reload_matrix(head);
			if (res == -1)
				return (-1);
		}
	}
	if (count_empty_cols(*head) <= g_empty + 4)
		return (-1);
	return (g_res_top == num_of_tetriminos - 1);
}
