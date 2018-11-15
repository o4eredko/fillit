/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:09:18 by dmatseku          #+#    #+#             */
/*   Updated: 2018/10/31 13:14:56 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*setm(int n)
{
	size_t	i;
	int		j;

	i = 1;
	j = 1;
	while (n / j > 9 || n / j < -9)
	{
		j *= 10;
		i++;
	}
	if (n < 0)
		i++;
	return (ft_strnew(i));
}

static void	setres(char **res, int i, int j, int n)
{
	while (i > 0)
	{
		(*res)[j] = (char)(((n < 0) ? -(n / i) : n / i) + 48);
		n = n % i;
		i /= 10;
		j++;
	}
	(*res)[j] = '\0';
}

char		*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		j;

	i = 1;
	j = 0;
	res = setm(n);
	if (!res)
		return (0);
	if (n < 0)
	{
		j++;
		res[0] = '-';
	}
	while (n / i > 9 || n / i < -9)
		i *= 10;
	setres(&res, i, j, n);
	return (res);
}
