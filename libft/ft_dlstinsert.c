/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstinsert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:38:11 by dmatseku          #+#    #+#             */
/*   Updated: 2018/11/16 10:38:12 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*create_column(t_dlist **list, long x)
{
	t_dlist *tmp;
	long i;

	tmp = ft_dlstgetend(*list, 0);
	if (!tmp)
	{
		tmp = ft_dlstnew(0, 0, 0, 0);
		*list = tmp;
	}
	while (tmp->cords[0] < x)
	{
		i = tmp->cords[0] + 1;
		tmp->right = ft_dlstnew(&i, sizeof(long), i, 0);
		tmp->right->left = tmp;
		tmp = tmp->right;
	}
	return (tmp);
}

t_dlist	*create_row(t_dlist **list, long y)
{
	t_dlist *tmp;
	long i;

	tmp = ft_dlstgetend(*list, 1);
	if (!tmp)
	{
		tmp = ft_dlstnew(0, 0, 0, 0);
		*list = tmp;
	}
	while (tmp->cords[1] < y)
	{
		i = tmp->cords[1] + 1;
		tmp->down = ft_dlstnew(&i, sizeof(long), 0, i);
		tmp->down->up = tmp;
		tmp = tmp->down;
	}
	return (tmp);
}

int ft_insert2(t_dlist **list, t_dlist *elem)
{
	t_dlist *tmp_elem;

	if (!(tmp_elem = ft_dlstfind(*list, 0, elem->cords[1])))
		tmp_elem = create_row(list, elem->cords[1]);
	if (!tmp_elem->right)
		tmp_elem->right = elem;
	else
	{
		while (tmp_elem->right && tmp_elem->right->cords[0] > tmp_elem->cords[0]
			&& tmp_elem->right->cords[0] <= elem->cords[0])
		{
			if (tmp_elem->right->cords[0] == elem->cords[0])
				return (0);
			tmp_elem = tmp_elem->right;
		}
		if (!(elem->right = tmp_elem->right))
		{
			elem->right = tmp_elem;
			elem->left = tmp_elem;
			tmp_elem->right = elem;
			tmp_elem->left = elem;
		}
		else
		{
			elem->left = (tmp_elem->right->left) ? tmp_elem->right->left : tmp_elem->right;
			elem->right->left = elem;
			elem->left->right = elem;
			if (!tmp_elem->cords[0])
				tmp_elem->right = elem;
		}
	}
	return (1);
}
int	ft_dlstinsert(t_dlist **list, t_dlist *elem)
{
	t_dlist *tmp_elem;

	if (!(tmp_elem = ft_dlstfind(*list, elem->cords[0], 0)))
		tmp_elem = create_column(list, elem->cords[0]);
	if (!tmp_elem->down)
		tmp_elem->down = elem;
	else
	{
		while (tmp_elem->down && tmp_elem->down->cords[0] > tmp_elem->cords[0]
			&& tmp_elem->down->cords[1] <= elem->cords[1])
		{
			if (tmp_elem->down->cords[1] == elem->cords[1])
				return (0);
			tmp_elem = tmp_elem->down;
		}
		if (!(elem->down = tmp_elem->down))
		{
			elem->down = tmp_elem;
			elem->up = tmp_elem;
			tmp_elem->down = elem;
			tmp_elem->up = elem;
		}
		else
		{
			elem->up = (tmp_elem->down->up) ? tmp_elem->down->up : tmp_elem->down;
			elem->down->up = elem;
			elem->up->down = elem;
			if (!tmp_elem->cords[1])
				tmp_elem->down = elem;
		}
	}
	return (ft_insert2(list, elem));
}
