# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yochered <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 11:16:16 by yochered          #+#    #+#              #
#    Updated: 2018/11/08 11:16:17 by yochered         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = src/validate.c src/create_matrix.c src/print_functions.c src/fill_cords.c

OBJ = validate.o create_matrix.o print_functions.o fill_cords.o

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -c $(SRC)
	gcc -Wall -W -Werror -o $(NAME) $(OBJ) -L libft/ -lft

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: re
	rm test.fillit
	make -C generator/ re
	./generator/tetrigen -v -f 5
	clear
	./$(NAME) test.fillit

run2: re
	clear
	./$(NAME) test.txt