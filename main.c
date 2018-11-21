#include <stdio.h>
#include "src/fillit.h"
#include "libft/libft.h"

void	del_matrix(t_dlist **head)
{
	t_dlist	*tmp;
	t_dlist	*tmp1;
	t_dlist	*row_end;
	t_dlist	*col_end;

	row_end = ft_dlstgetend(*head, X);
	while (*head)
	{
		if (*head == row_end)
			break ;
		tmp1 = (*head)->down;
		col_end = ft_dlstgetend(tmp1, Y);
		while (tmp1)
		{
			if (tmp1 == col_end)
				break ;
			tmp = tmp1->down;
			ft_memdel(&(tmp1->content));
			ft_memdel((void **)&tmp1);
			tmp1 = tmp;
		}
		tmp = (*head)->right;
		ft_memdel(&((*head)->content));
		ft_memdel((void **)head);
		*head = tmp;
	}
	*head = NULL;
}

int 	main(int ac, char **av)
{
	t_dlist *list;
	t_shape *elem;
	t_cords	*cords;
	int		fd;
	int		res;
	int		map_size;
	int		num_of_tetriminos;

	list = NULL;
	res = 0;
	fd = open("../test.fillit", 0);
	if (!(elem = validate(fd)))
	{
		printf("Validate Error!!!\n");
		exit(1);
	}
	print_list(elem);
	close(fd);

	cords = lstmap(elem, &fill_cords);
	num_of_tetriminos = ft_clstcount(cords);
	map_size = ft_sqrt(num_of_tetriminos * 4);
	print_cords(cords);
	while (!res)
	{
		set_dlist(cords, &list, map_size);
		if (!g_res_stack)
			create_stack(list, 1);
		if (!g_del_stack)
			create_stack(list, 0);
//		ft_dlstprint(list);
		ft_putchar('\n');
		if (!(res = algorithm(&list, num_of_tetriminos)))
		{
			while (g_res_top--)
				;
			del_matrix(&list);
		}
		map_size++;
	}
	print_map(list, create_matrix(map_size - 1), map_size - 1);
	return (0);
}
