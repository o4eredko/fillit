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
		tmp = tmp->right;
	row_end = ft_dlstgetend(tmp, X);
	push(NULL, 0);
	while (tmp)
	{
		tmp1 = tmp;
		col_end = ft_dlstgetend(tmp, Y);
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
	return (algorithm(head, k));
}

int				algorithm(t_dlist **head, int num_of_tetriminos)
{
	t_dlist	*pivot;
	int		res;

	res = 0;
	ft_dlstprint(*head);
	ft_putstr("\n\n");
	if ((*head)->right && (*head)->right->c_size == sizeof(char))
	{
	    if (!(*head)->right->down)
	        return (0);
		pivot = (*head)->right;
		while (!res && pivot->down)
		{
			pivot = pivot->down;
			push(pivot, 1);
			res = reduce_matrix(head, pivot, num_of_tetriminos);
			if (!res)
			{
                pop(1);
                return (0);
            }
			reload_matrix(head);
		}
		if (g_res_top != num_of_tetriminos - 1 || !res)
            return (0);
	}
    return (1);
}
