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
#include "../libft/libft.h"

int		ft_clstcount(t_cords *cords)
{
	int i;

	i = 0;
	while (cords)
	{
		i++;
		cords = cords->next;
	}
	return (i);
}

int		get_cords(int **cords, int xy, int bs)
{
	int res;
	int i;

	i = -1;
	res = bs ? 4 : 0;
	while (++i < 4 && !bs)
	{
		if (res < cords[i][xy])
			res = cords[i][xy];
	}
	while (++i < 4 && bs)
	{
		if (res > cords[i][xy])
			res = cords[i][xy];
	}
	return (res);
}

static void	move_cords(int **cords)
{
	int i;

	i = -1;
	if (get_cords(cords, 0, 0) < 3)
		while (++i < 4)
			cords[i][0]++;
	else
		while (++i < 4)
		{
			cords[i][1]++;
			cords[i][0] -= get_cords(cords, 0, 1);
		}
}

int	set_cords(int **cords, t_dlist **list, int count, int nb)
{
	long i;
	long j;

	i = ft_dlstrowcount(*list) + 1;
	while (get_cords(cords, 0, 0) != 3 || get_cords(cords, 1, 0) != 3)
	{
		ft_dlstinsert(list, ft_dlstnew(0, 0, nb, i));
		j = -1;
		while (++j < 4)
			ft_dlstinsert(list, ft_dlstnew(0, 0, count + (cords[j][0] + 4 * cords[j][1]), i));
		move_cords(cords);
		i++;
	}
}

void	set_dlist(t_cords *cords, t_dlist **list, int length)
{
	int i;
	int j;
	long c;

	i = ft_clstcount(cords);
	j = -1;
	c = 'a';
	ft_dlstaddcolumn(list, 0, 0);
	while (++j < i)
	{
		c = 'a' + j;
		ft_dlstaddcolumn(list, &c, sizeof(char));
	}
	i = 1;
	while (i <= length * length)
	{
		c = (i / length * 10 + i % length);
		ft_dlstaddcolumn(list, &c, sizeof(long));
		i++;
	}
	j = -1;
	i = ft_clstcount(cords);
	while (++j < i)
	{
		set_cords(cords->cords, list, i, j + 1);
		cords = cords->next;
	}
}
