/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:35:27 by yochered          #+#    #+#             */
/*   Updated: 2018/11/12 10:35:28 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_usage()
{
	ft_putendl("usage: ./fillit soruse_file");
}

void	print_map(t_dlist *head, char **map, int size)
{
	int		x;
	int		y;
	t_dlist *row;

	while (g_res_top != -1)
	{
		row = (ft_dlstfind(head, 0, (pop(1))->cords[Y]))->right->right;
		while (row && row->left->cords[X] < row->cords[X])
		{
			x = ft_atoi((ft_dlstfind(head, row->cords[X], 0))->content) / 10;
			y = ft_atoi((ft_dlstfind(head, row->cords[X], 0))->content) % 10;
			map[y - 1][x - 1] = (char)('A' + (g_res_top + 1));
			row = row->right;
		}
	}
	x = -1;
	while (++x < size)
	{
		ft_putstr(map[x]);
		ft_putchar('\n');
	}
}

/*Additional functions*/

void	print_list(t_shape *head)
{
	int i;

	while (head)
	{
		i = -1;
		while (++i < 4)
		{
			ft_putstr(head->matrix[i]);
			ft_putchar('\n');
		}
		ft_putchar('\n');
		head = head->next;
	}
}

void	print_cords(t_cords *head)
{
	int i;

	while (head)
	{
		i = -1;
		while (++i < 4)
		{
			ft_putnbr(head->cords[i][0]);
			ft_putnbr(head->cords[i][1]);
			ft_putchar('\n');
		}
		ft_putchar('\n');
		head = head->next;
	}
}

void	print_row(t_dlist *head, t_dlist *row)
{
	long x;
	long y;

	row = ft_dlstfind(head, 0, row->cords[Y]);
	row = row->right->right;
	while (row)
	{
		x = ft_atoi((ft_dlstfind(head, row->cords[X], 0))->content) / 10;
		y = ft_atoi((ft_dlstfind(head, row->cords[X], 0))->content) % 10;
		ft_putstr("(");
		ft_putlong(x);
		ft_putstr(", ");
		ft_putlong(y);
		ft_putstr(")");
		if (row->right->cords[X] < row->cords[X])
			break ;
		row = row->right;
	}
}

void	print_stack(t_dlist *head, int stack_type)
{
	int top;

	if (!stack_type)
	{
		top = g_del_top;
		while (top != -1)
		{
			ft_putlong((g_del_stack[top])->cords[X]);
			ft_putstr(", ");
			ft_putlong((g_del_stack[top])->cords[Y]);
			ft_putstr("\n");
			top--;
		}
	}
	else
	{
		top = g_res_top;
		while (top != -1)
		{
			print_row(head, g_res_stack[top]);
			ft_putstr("\n");
			top--;
		}
	}
}
