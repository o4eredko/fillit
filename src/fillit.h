/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:37:01 by yochered          #+#    #+#             */
/*   Updated: 2018/11/09 13:37:03 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include "../libft/get_next_line.h"
# include "../libft/libft.h"
# define CHECK_ERR(x) if (!x)return (0)
# define X 0
# define Y 1

typedef struct		s_shape
{
	char			**matrix;
	struct s_shape	*next;
}					t_shape;

typedef struct		s_cords
{
	int				**cords;
	struct s_cords	*next;
}					t_cords;

int					g_del_stack;
int 				g_res_stack;

t_shape				*validate(int fd);
void				print_usage();
void				algorithm(t_dlist **head, t_dlist **del_stack,
		t_dlist **res_stack);
void				create_del_stack(t_dlist *list, t_dlist ***stack);
void				create_res_stack(t_dlist *list, t_dlist ***stack);
void				push(t_dlist ***stack, t_dlist *elem, int stack_type);
t_dlist				*pop(t_dlist **stack, int stack_type);
/*Additional funcs*/
void				print_list(t_shape *head);
void				print_cords(t_cords *head);
void				print_stack(t_dlist **stack);

#endif
