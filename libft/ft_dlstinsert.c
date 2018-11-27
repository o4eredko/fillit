/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstinsert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:38:11 by dmatseku          #+#    #+#             */
/*   Updated: 2018/11/26 20:50:54 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_dlstrelink(t_dlist **elem, t_dlist **tmp, int xy)
{
	if (!xy)
	{
		(*elem)->right = *tmp;
		(*elem)->left = *tmp;
		(*tmp)->right = *elem;
		(*tmp)->left = *elem;
	}
	else
	{
		(*elem)->down = *tmp;
		(*elem)->up = *tmp;
		(*tmp)->down = *elem;
		(*tmp)->up = *elem;
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

int				ft_insert2(t_dlist **list, t_dlist *elem)
{
	t_dlist *tmp;

	if (!(tmp = ft_dlstfind(*list, 0, elem->cords[Y])))
		tmp = create_row(list, elem->cords[Y]);
	if (!tmp->right)
		tmp->right = elem;
	else
	{
		while (tmp->right && tmp->right->cords[X] > tmp->cords[X]
			&& tmp->right->cords[X] <= elem->cords[X])
		{
			CHECK((tmp->right->cords[X] != elem->cords[X]));
			tmp = tmp->right;
		}
		if (!(elem->right = tmp->right))
			ft_dlstrelink(&elem, &tmp, X);
		else
		{
			elem->left = (tmp->right->left) ? tmp->right->left : tmp->right;
			elem->right->left = elem;
			elem->left->right = elem;
			tmp->right = tmp->cords[X] ? tmp->right : elem;
		}
	}
	return (1);
}

int				ft_dlstinsert(t_dlist **list, t_dlist *elem)
{
	t_dlist *tmp;

	if (!(tmp = ft_dlstfind(*list, elem->cords[X], 0)))
		tmp = create_column(list, elem->cords[X]);
	if (!tmp->down)
		tmp->down = elem;
	else
	{
		while (tmp->down && tmp->down->cords[Y] > tmp->cords[Y]
			&& tmp->down->cords[Y] <= elem->cords[Y])
		{
			CHECK((tmp->down->cords[Y] != elem->cords[Y]));
			tmp = tmp->down;
		}
		if (!(elem->down = tmp->down))
			ft_dlstrelink(&elem, &tmp, Y);
		else
		{
			elem->up = (tmp->down->up) ? tmp->down->up : tmp->down;
			elem->down->up = elem;
			elem->up->down = elem;
			tmp->down = tmp->cords[Y] ? tmp->down : elem;
		}
	}
	return (ft_insert2(list, elem));
}
