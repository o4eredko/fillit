/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:02:48 by dmatseku          #+#    #+#             */
/*   Updated: 2018/10/31 12:22:01 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *res;

	if (!(res = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (!content)
	{
		res->content = 0;
		content_size = 0;
	}
	else
	{
		if (!(res->content = malloc(content_size)))
			return (0);
		ft_memcpy(res->content, (void*)content, content_size);
	}
	res->content_size = content_size;
	res->next = 0;
	return (res);
}
