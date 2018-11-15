/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:22:22 by dmatseku          #+#    #+#             */
/*   Updated: 2018/10/26 17:17:13 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (*haystack != '\0')
	{
		if (*haystack == *needle)
		{
			i++;
			needle++;
			if (*needle == '\0')
				return ((char*)haystack - i + 1);
		}
		else if (i != 0)
		{
			needle -= i;
			haystack -= i - 1;
			i = 0;
		}
		haystack++;
	}
	return (0);
}
