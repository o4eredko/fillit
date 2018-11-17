/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstgetend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:46:39 by dmatseku          #+#    #+#             */
/*   Updated: 2018/11/16 10:46:40 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstgetend(t_dlist	*list, char xy)
{
	t_dlist	*head;

	head = list;
	if (!list)
		return (0);
	if (!xy)
	{
		while (list->right)
		{
			if (list->right == head)
				break;
			list = list->right;
		}
		return (list);
	}
	while (list->down)
	{
		if (list->down == head)
			break ;
		list = list->down;
	}
	return (list);
}