/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:13:25 by dmatseku          #+#    #+#             */
/*   Updated: 2018/10/29 16:34:32 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*s1;
	unsigned int	i;

	if (!s || !f)
		return (0);
	s1 = (char*)malloc(ft_strlen(s) + 1);
	if (!s1)
		return (0);
	i = 0;
	while (*s)
	{
		s1[i] = f(*s);
		s++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
