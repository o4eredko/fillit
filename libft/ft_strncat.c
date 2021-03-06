/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:25:12 by dmatseku          #+#    #+#             */
/*   Updated: 2018/10/26 16:54:32 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (j < n && s2[(int)j] != '\0')
	{
		s1[i] = s2[(int)j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
