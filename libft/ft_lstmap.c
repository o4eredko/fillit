/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 14:46:12 by dmatseku          #+#    #+#             */
/*   Updated: 2018/10/31 15:03:26 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *res;

	if (!lst || !f)
		return (0);
	res = f(lst);
	tmp = res;
	lst = lst->next;
	while (lst)
	{
		res->next = f(lst);
		res = res->next;
		lst = lst->next;
	}
	return (tmp);
}
