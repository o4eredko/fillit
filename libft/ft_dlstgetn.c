/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstgetn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:48:56 by dmatseku          #+#    #+#             */
/*   Updated: 2018/11/26 18:13:53 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstgetn(t_dlist *list, long n, char xy)
{
	long i;

	i = 0;
	if (!xy)
	{
		while (i < n && list)
		{
			list = list->right;
			i++;
		}
		return (list);
	}
	while (i < n && list)
	{
		list = list->down;
		i++;
	}
	return (list);
}
