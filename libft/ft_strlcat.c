/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:37:30 by dmatseku          #+#    #+#             */
/*   Updated: 2018/10/31 13:27:32 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(char *dest, char *src, size_t n)
{
	size_t res;
	size_t srclen;
	size_t dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dest);
	if (srclen > 0)
	{
		if (dstlen <= n)
			res = srclen + dstlen;
		else
			res = n + srclen;
	}
	else if (dstlen > 0)
		res = dstlen;
	else
		res = 0;
	return (res);
}

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	size_t	j;
	size_t	res;

	res = ft_size(dst, (char*)src, dstsize);
	i = 0;
	j = 0;
	while (dst[i] != '\0')
	{
		i++;
		if (dstsize)
			dstsize--;
	}
	if (dstsize)
		dstsize--;
	while (j < dstsize && src[(int)j] != '\0')
	{
		dst[i] = src[(int)j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (res);
}
