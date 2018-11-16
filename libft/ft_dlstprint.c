/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:11:24 by dmatseku          #+#    #+#             */
/*   Updated: 2018/11/16 13:11:25 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_spaces(long count)
{
	long i;

	i = -1;
	while (++i < count)
		ft_putchar(' ');
}

void	ft_dlstprint(t_dlist *list)
{
	t_dlist *tmp;
	t_dlist *tmp1;

	if (!list)
	{
		ft_putchar('0');
		return ;
	}
	tmp = list;
	while (tmp)
	{
		if (tmp->c_size == sizeof(char))
			ft_putchar(*(char*)tmp->content);
		else if (tmp->c_size == sizeof(int))
			ft_putnbr(*(int*)tmp->content);
		else if (tmp->c_size == sizeof(long))
			ft_putlong(*(int*)tmp->content);
		else
			ft_putstr((char*)tmp->content);
		tmp = tmp->right;
	}
	tmp = list->down;
	while (tmp)
	{
		ft_putchar('\n');
		if (tmp->right)
		{
			tmp1 = tmp->right;
			while (tmp1)
			{
				if (tmp1->left && tmp1->cords[0] - tmp1->left->cords[0] != 1)
					print_spaces(tmp1->cords[0] - tmp1->left->cords[0] > 1);
				else if (!tmp1->left)
					print_spaces(tmp1->cords[0] - 1);
				ft_putchar('1');
				tmp1 = tmp1->right;
			}
		}
		tmp = tmp->down;
	}
}