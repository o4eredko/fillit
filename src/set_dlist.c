/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:59:50 by dmatseku          #+#    #+#             */
/*   Updated: 2018/11/19 14:59:52 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			get_cords(int **cords, int xy, int bs, int length)
{
	int res;
	int i;

	i = -1;
	res = bs ? length : 0;
	while (!bs && ++i < 4)
	{
		if (res < cords[i][xy])
			res = cords[i][xy];
	}
	while (bs && ++i < 4)
	{
		if (res > cords[i][xy])
			res = cords[i][xy];
	}
	return (res);
}

static void	move_cords_l(int **cords, int length)
{
	int i;
	int j;

	i = -1;
	if (get_cords(cords, 0, 0, length) < length - 1)
		while (++i < 4)
			cords[i][0]++;
	else if (get_cords(cords, 1, 0, length) < length - 1)
	{
		j = get_cords(cords, 0, 1, length);
		while (++i < 4)
		{
			cords[i][1]++;
			cords[i][0] -= j;
		}
	}
	else if (get_cords(cords, 1, 0, length) == length - 1)
		while (++i < 4)
			cords[i][1]++;
}

void		set_cords(t_cords *cords, t_dlist **list, int count, int length)
{
	long	i;
	long	j;
	int		icount;

	icount = -1;
	while (++icount < count)
	{
		i = ft_dlstrowcount(*list) + 1;
		while (get_cords(cords->cords, 1, 0, length) <= length - 1)
		{
			ft_dlstinsert(list, ft_dlstnew(0, 0, icount + 1, i));
			j = -1;
			while (++j < 4)
				ft_dlstinsert(list, ft_dlstnew(0, 0, count +
				(cords->cords[j][0] + 1 + length * (cords->cords[j][1])), i));
			move_cords_l(cords->cords, length);
			i++;
		}
		move_cords(cords->cords, X, length);
		cords = cords->next;
	}
}

int			check_cords(t_cords *tmp_cords, int length)
{
	while (tmp_cords)
	{
		if (get_cords(tmp_cords->cords, X, 0, length) >= length
			|| get_cords(tmp_cords->cords, Y, 0, length) >= length)
			return (0);
		tmp_cords = tmp_cords->next;
	}
	return (1);
}

int			set_dlist(t_cords *cords, t_dlist **list, int length)
{
	int i;
	int j;
	int c1;

	i = ft_clstcount(cords);
	j = -1;
	CHECK(check_cords(cords, length));
	ft_dlstaddcolumn(list, 0, 0);
	while (++j < i)
	{
		c1 = 'a' + j;
		ft_dlstaddcolumn(list, &c1, sizeof(char));
	}
	j = -1;
	while (++j < length * length)
		ft_dlstaddcolumn(list, 0, 0);
	set_cords(cords, list, i, length);
	set_row(*list, length, i);
	return (1);
}
