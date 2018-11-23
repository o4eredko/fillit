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

size_t		print_size(t_dlist *elem)
{
	size_t i;
	long j;
	long res;

	i = 1;
	j = 1;
	res = *(long*)elem->content;
	if (elem->c_size == sizeof(long))
	{
		while (res / j > 9) {
			i++;
			j *= 10;
		}
		return (i);
	}
	else if (elem->c_size == sizeof(char))
		return (1);
	return (elem->c_size);
}

void	print_header(t_dlist *tmp)
{
	while (tmp)
	{
		if (tmp->c_size == sizeof(char))
			ft_putchar(*(char*)tmp->content);
		else if (tmp->c_size == sizeof(long))
			ft_putlong(*(long*)tmp->content);
		else
			ft_putstr((char*)tmp->content);
		if (tmp->cords[0] != 0 || tmp->cords[1] != 0)
			ft_putchar(' ');
		tmp = tmp->right;
	}
}

void	print_elem(size_t size, t_dlist *elem)
{
	size_t count;

	count = elem ? size : size + 1;
	if (elem)
		ft_putchar('1');
	print_spaces(count);
}

void	ft_dlstprint(t_dlist *list)
{
	t_dlist *tmp;
	t_dlist *tmp1;
	long i;
	long j;

	if (!list)
	{
		ft_putchar('0');
		return ;
	}
	print_header(list);
	i = 0;
	j = ft_dlstgetend(list, Y)->cords[Y];
	while (++i <= j)
	{
		ft_putchar('\n');
		tmp = list;
		while ((tmp = tmp->right))
		{
			if ((tmp1 = tmp->down))
			{
				while (tmp1 && tmp1->down && tmp1->down->cords[Y] > tmp1->cords[Y] && tmp1->cords[Y] < i)
					tmp1 = tmp1->down;
				if (tmp1 && tmp1->cords[Y] == i)
					print_elem(print_size(tmp), tmp1);
			}
			if (!tmp->down || (tmp1 && i != tmp1->cords[Y]))
				print_elem(print_size(tmp), 0);
		}
	}
}