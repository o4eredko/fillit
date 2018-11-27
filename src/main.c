/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:08:31 by yochered          #+#    #+#             */
/*   Updated: 2018/11/27 12:08:33 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	del_elem(t_dlist **elem)
{
	if (*elem)
	{
		if ((*elem)->content)
			free((*elem)->content);
		free(*elem);
		*elem = NULL;
	}
}

void	del_matrix(t_dlist **head)
{
	t_dlist	*tmp;
	t_dlist	*tmp1;

	while (*head)
	{
		tmp1 = (*head)->right;
		while (*head)
		{
			tmp = (*head)->down;
			if (*head == ft_dlstgetend(*head, Y))
			{
				del_elem(head);
				break ;
			}
			del_elem(head);
			*head = tmp;
		}
		if (*head == ft_dlstgetend(*head, X))
		{
			del_elem(head);
			break ;
		}
		del_elem(head);
		*head = tmp1;
	}
}

t_dlist	*create_dlist(int fd, int *map_size, int *k, t_cords **cords)
{
	t_shape	*elem;
	t_dlist *list;

	list = NULL;
	if (!(elem = validate(fd)))
	{
		ft_putstr("error\n");
		exit(1);
	}
	*cords = lstmap(elem, &fill_cords);
	*k = ft_clstcount(*cords);
	while (!set_dlist(*cords, &list, *map_size))
	{
		del_matrix(&list);
		(*map_size)++;
	}
	return (list);
}

int		main(int ac, char **av)
{
	t_dlist *list;
	t_cords	*cords;
	int		fd;
	int		map_size;
	int		num_of_tetriminos;

	list = NULL;
	fd = open(av[1], 0);
	list = create_dlist(fd, &map_size, &num_of_tetriminos, &cords);
	close(fd);
	if (!g_res_stack)
		create_stack(list, 1, num_of_tetriminos);
	if (!g_del_stack)
		create_stack(list, 0, 0);
	while (algorithm(&list, num_of_tetriminos) <= 0)
	{
		del_matrix(&list);
		set_dlist(cords, &list, ++map_size);
		g_res_top = -1;
	}
	print_map(list, create_matrix(map_size), map_size, num_of_tetriminos);
	return (0);
}
