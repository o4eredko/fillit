/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:03:21 by dmatseku          #+#    #+#             */
/*   Updated: 2018/10/26 17:14:20 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i < len)
	{
		dst[(int)i] = src[j];
		i++;
		(src[j] != '\0') ? j++ : j;
	}
	return (dst);
}
