/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:29:20 by yochered          #+#    #+#             */
/*   Updated: 2018/11/15 16:29:21 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_find_elem(t_dlist *head, int x, int y)
{
	CHECK((head));
	while (head->right && head->cords[0] != x)
		head = head->right;
	while (head->down && head->cords[1] != y)
		head = head->down;
	return (head);
}
