/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:13:00 by dmatseku          #+#    #+#             */
/*   Updated: 2018/10/26 16:39:40 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*move1(char *dst, const char *src, size_t len)
{
	size_t i;

	i = len;
	while (i > 0)
	{
		dst[i - 1] = src[i - 1];
		i--;
	}
	return (dst);
}

static void	*move2(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src < dst)
		return (move1((char *)dst, (const char *)src, len));
	return (move2((char *)dst, (const char *)src, len));
}
