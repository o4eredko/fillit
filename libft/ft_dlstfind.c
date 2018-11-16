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
	while (head && head->cords[0] != x)
		head = head->right;
	while (head && head->cords[1] != y)
		head = head->down;
	return (head);
}