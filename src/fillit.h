/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:37:01 by yochered          #+#    #+#             */
/*   Updated: 2018/11/27 11:47:20 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <get_next_line.h>
# include <libft.h>
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

t_dlist				**g_del_stack;
t_dlist				**g_res_stack;
int					g_del_top;
int					g_res_top;

t_shape				*validate(int fd);
void				print_usage(void);
int					ft_clstcount(t_cords *cords);
int					algorithm(t_dlist **head, int num_of_tetriminos);
void				delete_from_col(t_dlist *elem);
void				delete_from_row(t_dlist *elem);
void				restore_in_col(t_dlist *elem);
void				restore_in_row(t_dlist *elem);
int					ft_sqrt(int nb);
void				delete_col(t_dlist **head, long x);
void				delete_row(t_dlist **head, long y);
void				restore_col(t_dlist **head, t_dlist *col);
void				restore_row(t_dlist **head, t_dlist *row);
void				create_stack(t_dlist *list, int stack_type, int k);
void				push(t_dlist *elem, int stack_type);
t_dlist				*pop(int stack_type);
int					set_dlist(t_cords *cords, t_dlist **list, int length);
t_cords				*lstmap(t_shape *lst, t_cords *(*f)(t_shape *elem));
t_cords				*fill_cords(t_shape *elem);
void				print_map(t_dlist *head, char **map, int size);
char				**create_matrix(int start_size);
void				move_cords(int **cords, int xy, int length);
void				set_row(t_dlist *list, int length, int count);
void				del_matrix(t_dlist **head);
void				free_memory(t_dlist **list, t_cords **cords);
void				del_shape_list(t_shape **shape);

#endif
