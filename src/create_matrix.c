/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:04:53 by yochered          #+#    #+#             */
/*   Updated: 2018/11/11 15:04:54 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	while (i <= nb / i)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (ft_sqrt(nb + 1));
}

char	**create_matrix(int start_size)
{
	char	**matrix;
	int		i;

	i = -1;
	CHECK_ERR((matrix = (char **)malloc(sizeof(char *) * start_size)));
	while (++i < start_size)
	{
		CHECK_ERR((matrix[i] = ft_strnew((size_t)start_size)));
		ft_memset(matrix[i], '.', (size_t)start_size);
	}
	return (matrix);
}
