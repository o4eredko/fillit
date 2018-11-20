/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstfind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:33:30 by dmatseku          #+#    #+#             */
/*   Updated: 2018/11/16 10:33:31 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist *ft_dlstfind(t_dlist *head, long x, long y)
{
	CHECK((head));
	while (head && head->cords[X] != x && head->right
		   && head->right->cords[X] > head->cords[X])
		head = head->right;
	while (head && head->cords[Y] != y && head->down
		   && head->down->cords[Y] > head->cords[Y])
		head = head->down;
	if (head->cords[X] == x && head->cords[Y] == y)
		return (head);
	return (NULL);
}