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

int				compare_cols(int x, t_cords *cords)
{
	while (cords)
	{
		if (cords->cords[0][X] == x)
			return (1);
		cords = cords->next;
	}
	return (0);
}

static t_dlist	*choose_column(t_dlist *head, t_cords *cords)
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
		if (!(compare_cols(tmp->cords[X], cords)))
		{
			while (tmp->down && tmp->down->cords[Y] > tmp->cords[Y])
			{
				i++;
				tmp = tmp->down;
			}
			if ((counter == -1 || i < counter))
			{
				counter = i;
				res = head;
			}
		}
	}
	if (!counter)
		return (NULL);
	return (res);
}

static void		reduce_matrix(t_dlist **head, t_dlist *row, t_cords *col)
{
	t_dlist	*tmp;
	t_dlist	*tmp1;

	if (tmp->right && (tmp = ft_dlstfind(*head, 0, row->cords[Y])))
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
	algorithm(head, col);
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

t_cords			*allocate_lst(t_cords *head)
{
	head = (t_cords *)malloc(sizeof(head));
	head->cords = (int **)ft_memalloc(sizeof(int *) * 1);
	head->cords[0] = (int *)ft_memalloc(sizeof(int) * 2);
	return (head);
}

void			algorithm(t_dlist **head, t_cords *col)
{
	t_dlist	*pivot;

	ft_putstr("\n\n");
	ft_dlstprint(*head);
	if ((*head)->right)
	{
		if (!(pivot = choose_column(*head, col)))
		{
			pop(1);
			return ;
		}
		if (!col)
			col = allocate_lst(col);
		while (pivot->down && pivot->down->cords[Y] > pivot->cords[Y])
		{
			pivot = pivot->down;
			push(pivot, 1);
			reduce_matrix(head, pivot, col);
			reload_matrix(head);
		}
		if (g_res_top != 1)
		{
			reload_matrix(head);
			clear_stack();
			algorithm(head, col);
		}
	}
}
