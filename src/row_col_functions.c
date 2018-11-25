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

void			restore(t_dlist **elem1, t_dlist **elem2, int xy)
{
	if (!xy)
	{
		(*elem1)->right = (*elem2)->right;
		(*elem1)->right->left = (*elem2)->right->left;
		(*elem2)->right->left = *elem1;
		(*elem2)->right = *elem1;
	}
	else
	{
		(*elem1)->down = (*elem2)->down;
		(*elem1)->down->up = (*elem2)->down->up;
		(*elem2)->down->up = *elem1;
		(*elem2)->down = *elem1;
	}
}

void			restore_col(t_dlist **head, t_dlist *col)
{
	t_dlist *tmp;
	t_dlist	*col_elem;
	t_dlist *col_end;

	if ((*head)->down && (tmp = ft_dlstfind(*head, 0, (*head)->down->cords[Y])))
		while (tmp)
		{
			if ((col_elem = ft_dlstfind(col, col->cords[X], tmp->cords[Y])))
			{
				if (!tmp->right)
					tmp->right = col_elem;
				else if (tmp->right->cords[X] > col_elem->cords[X])
					restore(&col_elem, &tmp, X);
			}
			tmp = tmp->down;
		}
	tmp = col;
	col_end = ft_dlstgetend(col, Y);
	while (tmp)
	{
		restore_in_col(tmp);
		if (tmp == col_end)
			break ;
		tmp = tmp->down;
	}
}

void			restore_row(t_dlist **head, t_dlist *row)
{
	t_dlist *tmp;
	t_dlist *row_elem;
	t_dlist *row_end;

	if ((tmp = ft_dlstfind(*head, (*head)->right->cords[X], 0)))
		while (tmp)
		{
			if ((row_elem = ft_dlstfind(row, tmp->cords[X], row->cords[Y])))
			{
				if (!tmp->down)
					tmp->down = row_elem;
				else if (tmp->down->cords[Y] > row_elem->cords[Y])
					restore(&row_elem, &tmp, Y);
			}
			tmp = tmp->right;
		}
	tmp = row;
	row_end = ft_dlstgetend(row, X);
	while (tmp)
	{
		restore_in_row(tmp);
		if (tmp == row_end)
			break ;
		tmp = tmp->right;
	}
}

void			delete_col(t_dlist **head, long x)
{
	t_dlist	*tmp;
	t_dlist *col_end;

	if ((*head)->down)
	{
		tmp = (*head)->down;
		while (tmp)
		{
			if (tmp->right && tmp->right->cords[X] == x)
				tmp->right = tmp->right->right;
			tmp = tmp->down;
		}
	}
	if ((tmp = ft_dlstfind(*head, x, 0)))
	{
		col_end = ft_dlstgetend(tmp, Y);
		push(tmp, 0);
		while (tmp)
		{
			delete_from_col(tmp);
			if (tmp == col_end)
				break ;
			tmp = tmp->down;
		}
	}
}

void			delete_row(t_dlist **head, long y)
{
	t_dlist	*tmp;
	t_dlist *row_end;

	if ((*head)->right)
	{
		tmp = (*head)->right;
		while (tmp)
		{
			if (tmp->down && tmp->down->cords[Y] == y)
				tmp->down = tmp->down->down;
			tmp = tmp->right;
		}
	}
	if ((tmp = ft_dlstfind(*head, 0, y)))
	{
		row_end = ft_dlstgetend(tmp, X);
		push(tmp, 0);
		while (tmp)
		{
			delete_from_row(tmp);
			if (tmp == row_end)
				break ;
			tmp = tmp->right;
		}
	}
}
