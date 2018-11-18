#include <stdio.h>
#include "src/fillit.h"
#include "libft/libft.h"

int main()
{
	t_dlist *list;
	char    a;

	a = 'a';
	list = NULL;
	//A
	ft_dlstinsert(&list, ft_dlstnew(&a, 1, 1, 1));
	ft_dlstinsert(&list, ft_dlstnew(&a, 1, 4, 1));
	ft_dlstinsert(&list, ft_dlstnew(&a, 1, 7, 1));
	//B
	ft_dlstinsert(&list, ft_dlstnew(&a, 1, 1, 2));
	ft_dlstinsert(&list, ft_dlstnew(&a, 1, 4, 2));
	//C
	ft_dlstinsert(&list, ft_dlstnew(&a, 1, 4, 3));
	ft_dlstinsert(&list, ft_dlstnew(&a, 1, 5, 3));
	ft_dlstinsert(&list, ft_dlstnew(&a, 1, 7, 3));
	//D
	ft_dlstinsert(&list, ft_dlstnew(&a, 1, 3, 4));
	ft_dlstinsert(&list, ft_dlstnew(&a, 1, 5, 4));
	ft_dlstinsert(&list, ft_dlstnew(&a, 1, 6, 4));
	//E
	ft_dlstinsert(&list, ft_dlstnew(&a, 1, 2, 5));
	ft_dlstinsert(&list, ft_dlstnew(&a, 1, 3, 5));
	ft_dlstinsert(&list, ft_dlstnew(&a, 1, 6, 5));
	ft_dlstinsert(&list, ft_dlstnew(&a, 1, 7, 5));
	//F
	ft_dlstinsert(&list, ft_dlstnew(&a, 1, 2, 6));
	ft_dlstinsert(&list, ft_dlstnew(&a, 1, 7, 6));
	//
	ft_dlstprint(list);
	algorithm(&list);
	ft_putstr("\n");
	ft_putstr("\n");
	ft_dlstprint(list);
	return (0);
}