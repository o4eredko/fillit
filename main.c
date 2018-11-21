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
	if (!(elem = validate(fd)))
	{
		printf("Validate Error!!!\n");
		exit(1);
	}
	print_list(elem);
	close(fd);

	cords = lstmap(elem, &fill_cords);
	print_cords(cords);
	set_dlist(cords, &list, 4);

	create_stack(list, 0);
	create_stack(list, 1);
	ft_dlstprint(list);
	ft_putchar('\n');
	algorithm(&list, NULL);
	print_stack(list, 1);
	return (0);
}
