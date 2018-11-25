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

static void		ft_dlstrelink(t_dlist **elem, t_dlist **tmp_elem, int xy)
{
	if (!xy)
	{
		(*elem)->right = *tmp_elem;
		(*elem)->left = *tmp_elem;
		(*tmp_elem)->right = *elem;
		(*tmp_elem)->left = *elem;
	}
	else
	{
		(*elem)->down = *tmp_elem;
		(*elem)->up = *tmp_elem;
		(*tmp_elem)->down = *elem;
		(*tmp_elem)->up = *elem;
	}
}

static t_dlist	*create_column(t_dlist **list, long x)
{
	t_dlist	*tmp;
	long	i;

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

static t_dlist	*create_row(t_dlist **list, long y)
{
	t_dlist	*tmp;
	long	i;

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

static int		ft_insert2(t_dlist **list, t_dlist *elem)
{
	t_dlist *tmp_elem;

	if (!(tmp_elem = ft_dlstfind(*list, 0, elem->cords[Y])))
		tmp_elem = create_row(list, elem->cords[Y]);
	if (!tmp_elem->right)
		tmp_elem->right = elem;
	else
	{
		while (tmp_elem->right && tmp_elem->right->cords[X] > tmp_elem->cords[X]
			&& tmp_elem->right->cords[X] <= elem->cords[X])
		{
			CHECK((tmp_elem->right->cords[X] != elem->cords[X]));
			tmp_elem = tmp_elem->right;
		}
		if (!(elem->right = tmp_elem->right))
			ft_dlstrelink(&elem, &tmp_elem, X);
		else
		{
			elem->left = (tmp_elem->right->left)
					? tmp_elem->right->left : tmp_elem->right;
			elem->right->left = elem;
			elem->left->right = elem;
			if (!tmp_elem->cords[X])
				tmp_elem->right = elem;
		}
	}
	return (1);
}

int				ft_dlstinsert(t_dlist **list, t_dlist *elem)
{
	t_dlist *tmp_elem;

	if (!(tmp_elem = ft_dlstfind(*list, elem->cords[X], 0)))
		tmp_elem = create_column(list, elem->cords[X]);
	if (!tmp_elem->down)
		tmp_elem->down = elem;
	else
	{
		while (tmp_elem->down && tmp_elem->down->cords[Y] > tmp_elem->cords[Y]
			&& tmp_elem->down->cords[Y] <= elem->cords[Y])
		{
			CHECK((tmp_elem->down->cords[Y] != elem->cords[Y]));
			tmp_elem = tmp_elem->down;
		}
		if (!(elem->down = tmp_elem->down))
			ft_dlstrelink(&elem, &tmp_elem, Y);
		else
		{
			elem->up = (tmp_elem->down->up)
					? tmp_elem->down->up : tmp_elem->down;
			elem->down->up = elem;
			elem->up->down = elem;
			if (!tmp_elem->cords[Y])
				tmp_elem->down = elem;
		}
	}
	return (ft_insert2(list, elem));
}
