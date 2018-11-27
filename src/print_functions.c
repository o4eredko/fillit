/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:35:27 by yochered          #+#    #+#             */
/*   Updated: 2018/11/27 11:52:57 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_usage(void)
{
	ft_putendl("usage: fillit source_file\n");
}

void	print_map(t_dlist *head, char **map, int size, int k)
{
	long	x;
	long	y;
	t_dlist *row;

	while (g_res_top != -1)
	{
		row = (ft_dlstfind(head, 0, (pop(1))->cords[Y]))->right->right;
		while (row && row->left->cords[X] < row->cords[X])
		{
			x = ft_atoi(ft_dlstgetn(head, row->cords[X], X)->content);
			y = ft_atoi(ft_strchr((
				ft_dlstgetn(head, row->cords[X], X)->content), ':') + 1);
			map[y - 1][x - 1] = (char)('A' + (g_res_top + 1));
			row = row->right;
		}
	}
	y = -1;
	while (++y < size)
	{
		ft_putstr(map[y]);
		ft_putchar('\n');
	}
}
