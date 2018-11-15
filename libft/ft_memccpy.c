/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:28:13 by dmatseku          #+#    #+#             */
/*   Updated: 2018/10/26 16:31:04 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,
		int c, size_t n)
{
	unsigned char	*sr;
	unsigned char	*ds;
	size_t			i;
	unsigned char	ch;

	sr = (unsigned char *)src;
	ds = (unsigned char *)dst;
	i = 0;
	ch = (unsigned char)c;
	while (i < n)
	{
		ds[i] = sr[i];
		if (sr[i] == ch)
			return (ds + i + 1);
		i++;
	}
	return (0);
}
