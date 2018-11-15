/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:53:59 by dmatseku          #+#    #+#             */
/*   Updated: 2018/10/26 16:32:01 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*s1;

	ch = (unsigned char)c;
	i = 0;
	s1 = (unsigned char *)s;
	while (i < n && s1[i] != ch)
		i++;
	if (i == n)
		return (0);
	return (&s1[i]);
}
