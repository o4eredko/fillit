/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:17:37 by dmatseku          #+#    #+#             */
/*   Updated: 2018/11/15 12:17:39 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dancing_list				*ft_dlstnew(void const *content, size_t c_size, long x, long y)
{
    t_dancing_list *res;

    CHECK((res = (t_dancing_list*)malloc(sizeof(t_dancing_list))));
    res->c_size = (content) ? c_size : 0;
    if (content)
    {
        CHECK((res->content = malloc(sizeof(void) * c_size)));
        ft_memcpy(res->content, content, c_size);
    }
    else
    {
        res->content = 0;
        res->c_size = 0;
    }
    res->cords[0] = x;
    res->cords[1] = y;
    res->up = 0;
    res->down = 0;
    res->left = 0;
    res->right = 0;
    return (res);
}