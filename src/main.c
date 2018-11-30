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
	del_shape_list(&elem);
	*k = ft_clstcount(*cords);
	*map_size = ft_sqrt(*k * 4);
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
	if (ac != 2)
		print_usage();
	fd = open(av[1], 0);
	list = create_dlist(fd, &map_size, &num_of_tetriminos, &cords);
	close(fd);
	if (!g_res_stack)
		create_stack(list, 1, num_of_tetriminos);
	if (!g_del_stack)
		create_stack(list, 0, 0);
	ft_dlstprint(list);
	ft_putchar('\n');
	while (algorithm(&list, num_of_tetriminos) <= 0)
	{
		del_matrix(&list);
		set_dlist(cords, &list, ++map_size);
		g_res_top = -1;
	}
	print_map(list, create_matrix(map_size), map_size);
	free_memory(&list, &cords);
	return (0);
}
