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
	row = ft_dlstfind(head, 0, row->cords[Y]);
	ft_putnbr(row->cords[Y]);
	while (row)
	{
		row = row->right;
		ft_putstr("->");
		ft_putnbr(row->cords[X]);
		if (row->right->cords[X] < row->cords[X])
			break ;
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
			ft_putnbr((g_del_stack[top])->cords[X]);
			ft_putstr(", ");
			ft_putnbr((g_del_stack[top])->cords[Y]);
			ft_putstr("\n");
			top--;
		}
	}
	else
	{
		top = g_res_top;
		while (top != -1)
		{
			ft_putstr("Row: ");
			print_row(head, g_res_stack[top]);
			ft_putstr("\n");
			top--;
		}
	}
}
