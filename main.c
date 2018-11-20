#include <stdio.h>
#include "src/fillit.h"
#include "libft/libft.h"

int main(int ac, char **av)
{
	t_dlist *list;
	t_shape *elem;
	t_cords	*cords;
	char    a;
	int		fd;

	a = 'a';
	list = NULL;
	fd = open("../test.fillit", 0);
	elem = validate(fd);
	cords = fill_cords(elem);
	set_dlist(cords, &list, 4);
	close(fd);

	create_stack(list, 0);
	create_stack(list, 1);
	ft_dlstprint(list);
	ft_putchar('\n');
	ft_putchar('\n');
	algorithm(&list);
	print_stack(list, 1);
	return (0);
}
