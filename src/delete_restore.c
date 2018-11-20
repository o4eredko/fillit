/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_restore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:03:28 by yochered          #+#    #+#             */
/*   Updated: 2018/11/20 14:03:29 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			delete_from_col(t_dlist *elem)
{
	if (elem->left)
		elem->left->right = elem->right;
	if (elem->right)
		elem->right->left = elem->left;
}

void			delete_from_row(t_dlist *elem)
{
	if (elem->down)
		elem->down->up = elem->up;
	if (elem->up)
		elem->up->down = elem->down;
}

void			restore_in_col(t_dlist *elem)
{
	if (elem->left)
		elem->left->right = elem;
	if (elem->right)
		elem->right->left = elem;
}

void			restore_in_row(t_dlist *elem)
{
	if (elem->down)
		elem->down->up = elem;
	if (elem->up)
		elem->up->down = elem;
}
