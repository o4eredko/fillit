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

int		count_elem(t_shape *head)
{
	int i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

/*Additional func*/

void	print_matrix(char **matrix, int start_size)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < start_size)
		ft_putendl(matrix[i]);
}


char	**create_matrix(int start_size)
{
	char	**matrix;
	int		i;

	i = -1;
	CHECK_ERR((matrix = (char **)malloc(sizeof(char *) * start_size)));
	while (++i < start_size)
	{
		CHECK_ERR((matrix[i] = ft_strnew(start_size)));
		ft_memset(matrix[i], '.', start_size);
	}
	return (matrix);
}

int 	increase_matrix_size(char ***matrix, int start_size)
{
	int i;

	i = -1;
	while (++i < start_size)
		ft_strdel(&(*matrix)[i]);
	*matrix = create_matrix(start_size + 1);
	return (start_size + 1);
}

// int		main(int ac, char **av)
// {
// 	int		fd;
// 	t_shape	*head;
// 	char	**matrix;
// 	int 	start_size;

// 	if (ac == 2)
// 	{
// 		if ((fd = open(av[1], 0)) == -1)
// 		{
// 			printf("Open error\n");
// 			return (1);
// 		}
// 		if (!(head = validate(fd)))
// 		{
// 			printf("error\n");
// 			exit(1);
// 		}
// 		start_size = ft_sqrt(4 * count_elem(head));
// 		print_list(head);
// 		// matrix = create_matrix(start_size);
// 		// print_matrix(matrix, start_size);
// 		// ft_putchar('\n');
// 		// start_size = increase_matrix_size(&matrix, start_size);
// 		// print_matrix(matrix, start_size);
// 		if ((close(fd) == -1))
// 		{
// 			printf("Close error\n");
// 			return (1);
// 		}
// 	}
// 	else if (ac == 1)
// 	{
// 		print_usage();
// 		exit(EXIT_FAILURE);
// 	}
// 	return (0);
// }
