#include "fillit.h"

void	delete_from_col(t_dlist *elem)
{
	if (elem->left)
		elem->left->right = elem->right;
	if (elem->right)
		elem->right->left = elem->left;
}

void	delete_from_row(t_dlist *elem)
{
	if (elem->down)
		elem->down->up = elem->up;
	if (elem->up)
		elem->up->down = elem->down;
}

static t_dlist	*choose_column(t_dlist *head)
{
	t_dlist	*tmp;
	t_dlist	*res;
	int 	i;
	int 	counter;

	counter = 0;
	res = NULL;
	while (head->right && head->right->cords[X] > head->cords[X])
	{
		i = 0;
		head = head->right;
		tmp = head;
		while (tmp->down && tmp->down->cords[Y] > tmp->cords[Y])
		{
			i++;
			tmp = tmp->down;
		}
		if (!counter || i < counter)
		{
			counter = i;
			res = head;
		}
	}
	return (res);
}

static void		delete_col(t_dlist **head, long x)
{
	t_dlist	*tmp;

	if ((tmp = ft_dlstfind(*head, 0, (*head)->down->cords[Y])))
		while (tmp)
		{
			if (tmp->right && tmp->right->right == tmp->right)
				tmp->right = NULL;
			else if (tmp->right && tmp->right->cords[X] == x)
				tmp->right = tmp->right->right;
			tmp = tmp->down;
		}
	if ((tmp = ft_dlstfind(*head, x, 0)))
	{
		if (!tmp->down)
			delete_from_col(tmp);
		else
			while (tmp->down && tmp->down->cords[Y] > tmp->cords[Y])
			{
				delete_from_col(tmp);
				tmp = tmp->down;
			}
	}
}

static void		delete_row(t_dlist **head, long y)
{
	t_dlist	*tmp;

	if ((tmp = ft_dlstfind(*head, (*head)->right->cords[X], 0)))
		while (tmp)
		{
			if (tmp->down && tmp->down->down == tmp->down)
				tmp->down = NULL;
			else if (tmp->down && tmp->down->cords[Y] == y)
				tmp->down = tmp->down->down;
			tmp = tmp->right;
		}
	if ((tmp = ft_dlstfind(*head, 0, y)))
	{
		if (!tmp->right)
			delete_from_row(tmp);
		else
			while (tmp->right && tmp->right->cords[X] > tmp->cords[X])
			{
				delete_from_row(tmp);
				tmp = tmp->right;
			}
	}
}

static void		reduce_matrix(t_dlist **head, t_dlist **row)
{
	t_dlist	*tmp;
	t_dlist	*tmp1;

	tmp = ft_dlstfind(*head, 0, (*row)->cords[Y]);
	tmp = tmp->right;
	while (tmp->right)
	{
		tmp1 = tmp;
		while (tmp1->down)
		{
			delete_row(head, tmp1->cords[Y]);
			if (tmp1->down->cords[Y] <= tmp1->cords[Y])
				break ;
			tmp1 = tmp1->down;
		}
		delete_col(head, tmp->cords[X]);
		if (tmp->right->cords[X] <= tmp->cords[X])
			break ;
		tmp = tmp->right;
	}
//	algorithm(head);
}

void			algorithm(t_dlist **head)
{
	t_dlist	*pivot;

	if ((*head)->right)
	{
		/*Level 0*/
		pivot = choose_column(*head);
//		printf("\nColumn top cords: (%d; %d)\n", pivot->cords[X], pivot->cords[Y]);
//		while (pivot->down && pivot->down->cords[Y] > pivot->cords[Y])
//		{
			pivot = pivot->down;
			/*Level 1*/
			reduce_matrix(head, &pivot);
		}
//	}
}