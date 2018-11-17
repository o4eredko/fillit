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

int		print_size(t_dlist *elem)
{
	int i;
	long j;
	long res;

	i = 1;
	j = 1;
	res = *(long*)elem->content;
	if (elem->c_size == sizeof(long))
		while (res / j > 10)
		{
			i++;
			j *= 10;
		}
	else
		return (1);
	return (i);
}

void	print_header(t_dlist *tmp)
{
	while (tmp)
	{
		if (tmp->c_size == sizeof(char))
			ft_putchar(*(char*)tmp->content);
		else if (tmp->c_size == sizeof(int))
			ft_putnbr(*(int*)tmp->content);
		else if (tmp->c_size == sizeof(long))
			ft_putlong(*(int*)tmp->content);
		if (tmp->cords[0] != 0 || tmp->cords[1] != 0)
			ft_putchar(' ');
		tmp = tmp->right;
	}
}

void	print_elem(t_dlist *tmp1, t_dlist *list)
{
	long i;
	long j;
	long k;

	i = 0;
	while (tmp1)
	{
		j = print_size(ft_dlstfind(list, tmp1->cords[X], 0));
		i = (i) ? tmp1->cords[X] - i : tmp1->cords[X] - 1;
		k = i * 2 + j - 1 - ((tmp1->left && (tmp1->left->cords[X]) < tmp1->cords[X]) ? 1 : 0);
		if (i >= 1)
			print_spaces(k);
		else if (!tmp1->left)
			print_spaces(tmp1->cords[X] - 1 + j);
		ft_putstr("1");
		i = tmp1->cords[X];
		if (tmp1->right && tmp1->right->cords[X] < tmp1->cords[X])
			break ;
		tmp1 = tmp1->right;
	}
}

void	ft_dlstprint(t_dlist *list)
{
	t_dlist *tmp;

	if (!list)
	{
		ft_putchar('0');
		return ;
	}
	print_header(list);
	tmp = list->down;
	while (tmp)
	{
		ft_putchar('\n');
		if (tmp->right)
			print_elem(tmp->right, list);
		tmp = tmp->down;
	}
}