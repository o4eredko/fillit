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

SRC = main.c algorithm_x.c create_matrix.c delete_restore.c\
    fill_cords.c print_functions.c row_col_functions.c\
    set_dlist.c stack.c validate.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -c src/main.c
	gcc -c src/algorithm_x.c
	gcc -c src/create_matrix.c
	gcc -c src/delete_restore.c
	gcc -c src/fill_cords.c
	gcc -c src/print_functions.c
	gcc -c src/row_col_functions.c
	gcc -c src/set_dlist.c
	gcc -c src/stack.c
	gcc -c src/validate.c
	gcc -o $(NAME) $(OBJ) -L libft/ -lft

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
	./$(NAME) test.fillit