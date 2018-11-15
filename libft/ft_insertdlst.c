/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertdlst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:44:47 by dmatseku          #+#    #+#             */
/*   Updated: 2018/11/15 15:45:02 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	create_header(t_dlist **list)
{
	if (!*list)
		*list = ft_dlstnew(0, 0, 0, 0);
}

void		ft_insertdlst(t_dlist *elem, t_dlist *list)
{
	t_dlist	*node;

	if (!list)
		create_header(&list);
	node = list;
	node = ft_find_elem(list, elem->cords[0], elem->cords[1]);
	node->up->down = elem;
	if (node->down)
		node->down->up = elem;
	if (node->left)
		node->left->right = elem;
	if (node->right)
		node->right->left = elem;
}
