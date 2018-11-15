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

static void create_header(t_dancing_list **list)
{
    if (!*list)
        *list = ft_dlstnew(0, 0, 0, 0);
}

void    ft_insertdlst(t_dancing_list *elem, t_dancing_list *list)
{
    if (!list)
        create_header(&list);
    else
    {

    }
}