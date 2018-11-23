# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/24 13:52:08 by dmatseku          #+#    #+#              #
#    Updated: 2018/10/31 15:48:48 by dmatseku         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.c

LIB = $(SRC:.c=.o)

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(SRC)
	@ar rc $(NAME) $(LIB)

all: $(NAME)

clean:
	@rm -f $(LIB)

fclean: clean
	@rm -f $(NAME)

re: fclean all
