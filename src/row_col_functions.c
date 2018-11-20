/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_col_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:05:03 by yochered          #+#    #+#             */
/*   Updated: 2018/11/20 14:05:04 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			restore_col(t_dlist **head, t_dlist *col)
{
	t_dlist *tmp;
	t_dlist	*col_elem;

	if ((*head)->down && (tmp = ft_dlstfind(*head, 0, (*head)->down->cords[Y])))
		while (tmp)
		{
			col_elem = ft_dlstfind(col, col->cords[X], tmp->cords[Y]);
			if (!tmp->right)
				tmp->right = col_elem;
			if (tmp->right && col_elem
				&& tmp->right->cords[X] > col_elem->cords[X])
				tmp->right = col_elem;
			tmp = tmp->down;
		}
	tmp = col;
	if (!tmp->down)
		restore_in_col(tmp);
	else
		while (tmp->down && tmp->down->cords[Y] > tmp->cords[Y])
		{
			restore_in_col(tmp);
			tmp = tmp->down;
		}
}

void			restore_row(t_dlist **head, t_dlist *row)
{
	t_dlist *tmp;
	t_dlist *row_elem;

	if ((*head)->right
		&& (tmp = ft_dlstfind(*head, (*head)->right->cords[X], 0)))
		while (tmp)
		{
			row_elem = ft_dlstfind(row, tmp->cords[X], row->cords[Y]);
			if (!tmp->down)
				tmp->down = row_elem;
			if (tmp->down
				&& row_elem && tmp->down->cords[Y] > row_elem->cords[Y])
				tmp->down = row_elem;
			tmp = tmp->right;
		}
	tmp = row;
	if (!tmp->right)
		restore_in_row(tmp);
	else
		while (tmp->right && tmp->right->cords[X] > tmp->cords[X])
		{
			restore_in_row(tmp);
			tmp = tmp->right;
		}
}

void			delete_col(t_dlist **head, long x)
{
	t_dlist	*tmp;

	if ((*head)->down && (tmp = ft_dlstfind(*head, 0, (*head)->down->cords[Y])))
		while (tmp)
		{
			if (tmp->right && tmp->right->cords[X] == x
				&& tmp->right->right == tmp->right)
				tmp->right = NULL;
			else if (tmp->right && tmp->right->cords[X] == x)
				tmp->right = tmp->right->right;
			tmp = tmp->down;
		}
	if ((tmp = ft_dlstfind(*head, x, 0)))
	{
		push(tmp, 0);
		if (!tmp->down)
			delete_from_col(tmp);
		else
			while (tmp->down && tmp->down->cords[Y] > tmp->cords[Y])
			{
				delete_from_col(tmp);
				tmp = tmp->down;
			}
	}
}

void			delete_row(t_dlist **head, long y)
{
	t_dlist	*tmp;

	if ((*head)->right
		&& (tmp = ft_dlstfind(*head, (*head)->right->cords[X], 0)))
		while (tmp)
		{
			if (tmp->down && tmp->down->cords[Y] == y
				&& tmp->down->down == tmp->down)
				tmp->down = NULL;
			else if (tmp->down && tmp->down->cords[Y] == y)
				tmp->down = tmp->down->down;
			tmp = tmp->right;
		}
	if ((tmp = ft_dlstfind(*head, 0, y)))
	{
		push(tmp, 0);
		if (!tmp->right)
			delete_from_row(tmp);
		else
			while (tmp->right && tmp->right->cords[X] > tmp->cords[X])
			{
				delete_from_row(tmp);
				tmp = tmp->right;
			}
	}
}
