/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:07:17 by dmatseku          #+#    #+#             */
/*   Updated: 2018/10/29 16:26:57 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *res;

	if (!s1 || !s2)
		return (0);
	res = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!res)
		return (0);
	ft_strcat(res, s1);
	ft_strcat(res, s2);
	return (res);
}
