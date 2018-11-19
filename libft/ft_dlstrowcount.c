/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstrowcount.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:43:35 by dmatseku          #+#    #+#             */
/*   Updated: 2018/11/19 18:43:37 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_dlstrowcount(t_dlist *list)
{
	long i;

	i = 0;
	while ((list = list->down))
		i++;
	return (i);
}
