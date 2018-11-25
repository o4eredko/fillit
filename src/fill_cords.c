/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:36:16 by yochered          #+#    #+#             */
/*   Updated: 2018/11/14 15:36:18 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_cords	*lstmap(t_shape *lst, t_cords *(*f)(t_shape *elem))
{
	t_cords	*new_list;

	if (lst)
	{
		new_list = f(lst);
		new_list->next = lstmap(lst->next, f);
		return (new_list);
	}
	return (NULL);
}

void	move_cords(int **cords, int xy, int length)
{
	int i;
	int tmp;

	i = -1;
	tmp = length;
	while (++i < 4)
	{
		if (cords[i][xy] < tmp)
			tmp = cords[i][xy];
	}
	i = -1;
	while (++i < 4)
		cords[i][xy] -= tmp;
	if (!xy)
		move_cords(cords, Y, length);
}

t_cords	*fill_cords(t_shape *elem)
{
	t_cords	*res;
	int		x;
	int		y;

	CHECK_ERR((res = (t_cords *)malloc(sizeof(t_cords))));
	CHECK_ERR((res->cords = (int **)ft_memalloc(sizeof(int *) * 4)));
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (elem->matrix[y][x] == '#')
			{
				CHECK_ERR((*res->cords = (int *)ft_memalloc(sizeof(int) * 2)));
				(*res->cords)[0] = x;
				(*res->cords)[1] = y;
				res->cords++;
			}
		}
	}
	res->cords -= 4;
	move_cords(res->cords, 0, 4);
	return (res);
}
