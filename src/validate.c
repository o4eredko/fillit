/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:55:33 by yochered          #+#    #+#             */
/*   Updated: 2018/11/08 12:55:34 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_shape	*create_node(int fd)
{
	t_shape	*shape;
	int		i;

	i = -1;
	CHECK_ERR((shape = (t_shape *)malloc(sizeof(t_shape))));
	CHECK_ERR((shape->matrix = (char **)malloc(sizeof(char *) * 4)));
	while (++i < 4)
		CHECK_ERR((shape->matrix[i] = ft_strnew(4)));
	i = -1;
	while (++i < 4)
	{
		CHECK_ERR((get_next_line(fd, &(shape->matrix[i])) == 1));
		if (ft_strlen(shape->matrix[i]) != 4)
			return (NULL);
	}
	shape->next = NULL;
	return (shape);
}

int		adjacent(char **matrix, int i, int j)
{
	int	sides;

	sides = 0;
	if (i > 0 && matrix[i - 1][j] == '#')
		sides++;
	if (j > 0 && matrix[i][j - 1] == '#')
		sides++;
	if (i < 3 && matrix[i + 1][j] == '#')
		sides++;
	if (j < 3 && matrix[i][j + 1] == '#')
		sides++;
	return (sides);
}

int		check_square(char **matrix, int i, int j)
{
	if (i == 0 || j == 0)
		return (0);
	if (matrix[i][j - 1] == '#' && matrix[i - 1][j] == '#'
		&& matrix[i - 1][j - 1] == '#')
		return (6);
	return (0);
}

int		check_shape(char **matrix)
{
	int i;
	int j;
	int sides;
	int res;

	res = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			CHECK_ERR((matrix[i][j] == '.' || matrix[i][j] == '#'));
			if (matrix[i][j] == '#')
			{
				sides = adjacent(matrix, i, j);
				CHECK_ERR((sides >= 1 && sides <= 3));
				res += sides;
				if (res == 8)
					CHECK_ERR((res = check_square(matrix, i, j)));
			}
		}
	}
	return (res == 6);
}

t_shape	*validate(int fd)
{
	t_shape	*head;
	t_shape	*node;
	char	*line;

	CHECK_ERR((head = create_node(fd)));
	CHECK_ERR(check_shape(head->matrix));
	node = head;
	while ((get_next_line(fd, &line)) == 1)
	{
		CHECK_ERR(!(ft_strlen(line)));
		while (node->next)
			node = node->next;
		CHECK_ERR((node->next = create_node(fd)));
		CHECK_ERR(check_shape(node->next->matrix));
	}
	return (head);
}
