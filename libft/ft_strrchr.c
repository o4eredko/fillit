/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 18:13:29 by dmatseku          #+#    #+#             */
/*   Updated: 2018/10/26 17:16:10 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char *res;
	char *trueres;

	res = (char*)s;
	trueres = 0;
	while (*res != '\0')
	{
		if (*res == c)
			trueres = res;
		res++;
	}
	if (*res == c)
		trueres = res;
	return (trueres);
}
