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

void	print_stack(t_dlist **stack)
{
	int top;

	top = g_del_stack;
	while (top != -1)
	{
		ft_putnbr((stack[top])->cords[X]);
		ft_putstr(", ");
		ft_putnbr((stack[top])->cords[Y]);
		ft_putstr("\n");
		top--;
	}
}
