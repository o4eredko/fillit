#include <stdio.h>
#include "src/fillit.h"
#include "libft/libft.h"

void	free_lst(t_cords **head)
{
	t_cords *tmp;

	while (*head)
	{
		tmp = (*head)->next;
		free((*head)->cords);
		free(*head);
		*head = NULL;
		*head = tmp;
	}
}

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

	free_lst(&cords);
	create_stack(list, 0);
	create_stack(list, 1);
//	ft_dlstprint(list);
	ft_putchar('\n');
	algorithm(&list, cords);
	print_stack(list, 1);
	return (0);
}
