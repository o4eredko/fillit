# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/24 13:52:08 by dmatseku          #+#    #+#              #
#    Updated: 2018/11/27 13:13:57 by yochered         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c\
      	ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c\
      	ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c\
      	ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
      	ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c\
      	ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c\
      	ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c\
      	ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c\
      	ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
      	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c\
      	get_next_line.c ft_dlstaddcolumn.c ft_dlstfind.c ft_dlstgetend.c ft_dlstgetn.c\
      	ft_dlstinsert.c ft_dlstnew.c ft_dlstrowcount.c ft_putlong.c ft_dlstprint.c

LIB = $(SRC:.c=.o)

$(NAME): $(LIB)
	ar rc $(NAME) $(LIB)

%.o: %.c
	gcc -Wall -W -Werror -c -o $@ $<

all: $(NAME)

clean:
	rm -f $(LIB)

fclean: clean
	rm -f $(NAME)

re: fclean all
