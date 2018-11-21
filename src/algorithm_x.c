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

/*static t_dlist	*choose_column(t_dlist *head, t_list *col)
{
	t_dlist	*tmp;
	t_dlist	*res;
	int		i;
	int		counter;

	counter = -1;
	res = NULL;
	while (head->right && head->right->cords[X] > head->cords[X])
	{
		i = 0;
		head = head->right;
		tmp = head;
		if (!(compare_cols(tmp->cords[X], col)))
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
}*/

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

static int		reduce_matrix(t_dlist **head, t_dlist *row, t_list **col)
{
	t_dlist	*tmp;
	t_dlist	*tmp1;
	int		res;

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
	res = algorithm(head, col);
	return (res);
}

int			algorithm(t_dlist **head, t_list **col)
{
	t_dlist	*pivot;
	int 	res;

	res = 0;
	ft_putstr("\n\n");
	ft_dlstprint(*head);
	if ((*head)->right->c_size == sizeof(char))
	{
		pivot = (*head)->right;
//		if (!*col)
//			*col = ft_lstnew(&(pivot->cords[X]), sizeof(long));
//		else
//			ft_lstadd(col, ft_lstnew(&(pivot->cords[X]), sizeof(long)));
		while (pivot->down && pivot->down->cords[Y] > pivot->cords[Y])
		{
			pivot = pivot->down;
			push(pivot, 1);
			res = reduce_matrix(head, pivot, col);
			reload_matrix(head);
			if (g_res_top == 2)
				return (1);
		}
//		if (g_res_top != 1)
//			return (0);
//		if (g_res_top != 9)
//		{
//			reload_matrix(head);
//			algorithm(head, col);
//		}
	}
	return (1);
}
