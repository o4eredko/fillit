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

static void		reduce_matrix(t_dlist **head, t_dlist **row)
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
			return ;
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
