#include <stdio.h>
#include "src/fillit.h"
#include "libft/libft.h"

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
	t_dlist	*row_end;
	t_dlist	*col_end;

	row_end = ft_dlstgetend(*head, X);
	while (*head)
	{
		tmp1 = (*head)->right;
		*head = (*head)->down;
		col_end = ft_dlstgetend(*head, Y);
		while (*head)
		{
			tmp = (*head)->down;
			if (*head == col_end)
			{
				del_elem(head);
				break ;
			}
			del_elem(head);
			*head = tmp;
		}
		if (*head == row_end)
		{
			del_elem(head);
			break ;
		}
		del_elem(head);
		*head = tmp1;
	}
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
		return (1);
	}
	close(fd);

	cords = lstmap(elem, &fill_cords);
	num_of_tetriminos = ft_clstcount(cords);
	map_size = ft_sqrt(4 * num_of_tetriminos);
    while (!set_dlist(cords, &list, map_size))
        map_size++;
	print_cords(cords);
	if (!g_res_stack)
		create_stack(list, 1);
	if (!g_del_stack)
		create_stack(list, 0);
    ft_dlstprint(list);
    ft_putstr("\n\n");
	while (!(algorithm(&list, num_of_tetriminos)))
	{
        ft_putstr("\n\n");
		del_matrix(&list);
		set_dlist(cords, &list, ++map_size - 1);
        //ft_dlstprint(list);
        g_res_top = -1;
	}
    ft_putstr("\n\n");
    ft_putstr("\n\n");
	print_map(list, create_matrix(map_size), map_size);
	return (0);
}
