/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:07:27 by yochered          #+#    #+#             */
/*   Updated: 2018/10/31 12:07:29 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 150
# include <stdlib.h>
# include <unistd.h>

int					get_next_line(const int fd, char **line);

typedef struct		s_gnl
{
	int				fd;
	char			buf[BUFF_SIZE];
	int				i;
	int				r_size;
	struct s_gnl	*next;
	struct s_gnl	*prev;
}					t_gnl;

#endif
