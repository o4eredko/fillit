/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:07:28 by dmatseku          #+#    #+#             */
/*   Updated: 2018/10/29 18:27:52 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	whitespaces(char *s)
{
	size_t res;

	res = 0;
	while ((*s == '\t' || *s == '\n' || *s == ' ') && *s)
	{
		res++;
		s++;
	}
	if (!*s)
		return (res);
	while (*s)
		s++;
	s--;
	while ((*s == '\t' || *s == '\n' || *s == ' ') && *s)
	{
		res++;
		s--;
	}
	return (res);
}

char			*ft_strtrim(char const *s)
{
	char	*s1;
	size_t	ws;
	size_t	i;

	if (!s)
		return (0);
	ws = whitespaces((char*)s);
	i = ft_strlen(s);
	while ((*s == '\t' || *s == '\n' || *s == ' ') && *s)
		s++;
	s1 = ft_strsub(s, 0, i - ws);
	return (s1);
}
