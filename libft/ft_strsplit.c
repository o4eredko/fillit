/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:05:20 by dmatseku          #+#    #+#             */
/*   Updated: 2018/10/29 20:05:49 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	str_count(char *s, char c)
{
	size_t res;

	res = 0;
	if (*s != c && *s)
		res++;
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1))
			res++;
		s++;
	}
	return (res);
}

static size_t	word_count(char **s, char c)
{
	size_t	res;
	char	*s1;

	s1 = *s;
	while (*s1 == c && *s1)
	{
		s1++;
		*s += 1;
	}
	res = 0;
	while (s1[res] && s1[res] != c)
		res++;
	return (res);
}

static char		**split(char **res, size_t count, char *s, char c)
{
	size_t i;
	size_t j;
	size_t wcount;

	i = 0;
	while (i < count)
	{
		j = 0;
		wcount = word_count(&s, c);
		if (!(res[i] = (char*)malloc(wcount + 1)))
			return (0);
		while (s[j] != c && s[j])
		{
			res[i][j] = s[j];
			j++;
		}
		res[i][j] = '\0';
		s += j;
		i++;
	}
	res[i] = 0;
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	count;
	char	**res;

	if (!s || !c)
		return (0);
	count = str_count((char*)s, c);
	if (!(res = (char**)malloc(sizeof(char*) * (1 + count))))
		return (0);
	return (split(res, count, (char*)s, c));
}
