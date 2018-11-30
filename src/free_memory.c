/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:19:33 by yochered          #+#    #+#             */
/*   Updated: 2018/11/28 14:19:34 by yochered         ###   ########.fr       */
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
		del_elem(head);
		if (*head == ft_dlstgetend(*head, X))
		{
			del_elem(head);
			break ;
		}
		*head = tmp1;
	}
}

void	del_shape_list(t_shape **elem)
{
	int		i;
	t_shape *tmp;

	while (*elem)
	{
		i = -1;
		tmp = (*elem)->next;
		while (++i < 4)
			free((*elem)->matrix[i]);
		free((*elem)->matrix);
		free(*elem);
		*elem = tmp;
	}
	*elem = NULL;
}

void	free_memory(t_dlist **list, t_cords **cords)
{
	t_cords	*tmp;
	int		i;

	free(g_res_stack);
	free(g_del_stack);
	del_matrix(list);
	while (*cords)
	{
		i = -1;
		tmp = (*cords)->next;
		while (++i < 2)
			free((*cords)->cords[i]);
		free((*cords)->cords);
		free(*cords);
		*cords = tmp;
	}
	*cords = NULL;
}
