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

<<<<<<< HEAD
=======

static int set_content(t_dancing_list *res, size_t *c_size, size_t c_count, void const **content)
{
    int i;

    i = 0;
    while (i < c_count)
    {
        if (content[i]) {
            res->c_size[i] = c_size[i];
            CHECK((res->content[i] = malloc(c_size[i])));
            ft_memcpy(res->content[i], content[i], c_size[i]);
        } else {
            res->content[i] = 0;
            res->c_size[i] = 0;
        }
        i++;
    }
    return (1);
}

>>>>>>> b338730f5ddbb4841d73f6b722177f498f437f64
t_dancing_list				*ft_dlstnew(void const *content, size_t c_size, long x, long y)
{
    t_dancing_list *res;

    CHECK((res = (t_dancing_list*)malloc(sizeof(t_dancing_list))));
<<<<<<< HEAD
    res->c_size = (content) ? c_size : 0;
    if (content)
    {
        CHECK((res->content = malloc(sizeof(void) * c_size)));
        ft_memcpy(res->content, content, c_size);
=======
    res->c_count = (content) ? c_count : 0;
    if (content)
    {
        CHECK((res->content = (void **) malloc(sizeof(void *) * c_count)));
        CHECK((res->c_size = (size_t*) malloc(sizeof(size_t) * c_count)));
        CHECK(set_content(res, c_size, c_count, content));
>>>>>>> b338730f5ddbb4841d73f6b722177f498f437f64
    }
    else
    {
        res->content = 0;
        res->c_size = 0;
    }
<<<<<<< HEAD
    res->cords[0] = x;
    res->cords[1] = y;
=======
    if (cords)
        ft_memcpy(res->cords, cords, sizeof(long) * 2);
    else
        res->cords[0] = res->cords[1] = 0;
>>>>>>> b338730f5ddbb4841d73f6b722177f498f437f64
    res->up = 0;
    res->down = 0;
    res->left = 0;
    res->right = 0;
    return (res);
}