/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dlist_module.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:04:48 by dmatseku          #+#    #+#             */
/*   Updated: 2018/11/27 15:10:13 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void	set_row(t_dlist *list, int length, int count)
{
	int		i;
	int		j;
	char	*s1;
	char	*s2;
	char	*tmp;

	i = 0;
	while (count-- >= 0)
		list = list->right;
	while (++i <= length)
	{
		j = 0;
		while (++j <= length)
		{
			s1 = ft_itoa(j);
			s2 = ft_itoa(i);
			tmp = ft_strjoin(s1, ":");
			free(s1);
			list->content = ft_strjoin(tmp, s2);
			free(tmp);
			free(s2);
			list->c_size = ft_strlen((char*)list->content);
			list = list->right;
		}
	}
}
