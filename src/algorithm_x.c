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

void			delete_from_col(t_dlist *elem)
{
	if (elem->left)
		elem->left->right = elem->right;
	if (elem->right)
		elem->right->left = elem->left;
}

void			delete_from_row(t_dlist *elem)
{
	if (elem->down)
		elem->down->up = elem->up;
	if (elem->up)
		elem->up->down = elem->down;
}

void			restore_in_col(t_dlist *elem)
{
	if (elem->left)
		elem->left->right = elem;
	if (elem->right)
		elem->right->left = elem;
}

void			restore_in_row(t_dlist *elem)
{
	if (elem->down)
		elem->down->up = elem;
	if (elem->up)
		elem->up->down = elem;
}

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

static t_dlist	*choose_column(t_dlist *head)
{
	t_dlist	*tmp;
	t_dlist	*res;
	int		i;
	int		counter;

	counter = -1;
	while (head->right && head->right->cords[X] > head->cords[X])
	{
		i = 0;
		head = head->right;
		tmp = head;
		while (tmp->down && tmp->down->cords[Y] > tmp->cords[Y])
		{
			i++;
			tmp = tmp->down;
		}
		if (counter == -1 || i < counter)
		{
			counter = i;
			res = head;
		}
	}
	if (!counter)
		return (NULL);
	return (res);
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

void			reduce_matrix(t_dlist **head, t_dlist **row)
{
	t_dlist	*tmp;
	t_dlist	*tmp1;

	tmp = (ft_dlstfind(*head, 0, (*row)->cords[Y]))->right;
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
	algorithm(head);
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

void			algorithm(t_dlist **head)
{
	t_dlist	*pivot;

	if ((*head)->right)
	{
		if (!(pivot = choose_column(*head)))
		{
			pop(1);
			return;
		}
		while (pivot->down && pivot->down->cords[Y] > pivot->cords[Y])
		{
			pivot = pivot->down;
			push(pivot, 1);
			reduce_matrix(head, &pivot);
			reload_matrix(head);
		}
	}
}
