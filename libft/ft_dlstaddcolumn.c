/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstaddcolumn.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:14:52 by dmatseku          #+#    #+#             */
/*   Updated: 2018/11/19 14:14:54 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstaddcolumn(t_dlist **list, void *content, size_t c_size)
{
	t_dlist	*tmp;
	long	i;

	tmp = ft_dlstgetend(*list, 0);
	if (!tmp)
	{
		tmp = ft_dlstnew(0, 0, 0, 0);
		*list = tmp;
		return ;
	}
	i = tmp->cords[0] + 1;
	tmp->right = ft_dlstnew(content, c_size, i, 0);
	tmp->right->left = tmp;
}
