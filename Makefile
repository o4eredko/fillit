# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yochered <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 11:16:16 by yochered          #+#    #+#              #
#    Updated: 2018/11/27 13:14:25 by yochered         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = main.c\
	algorithm_x.c\
	create_matrix.c\
	delete_restore.c\
    fill_cords.c\
    print_functions.c\
    row_col_functions.c\
    set_dlist.c\
    set_dlist_module.c\
    stack.c\
    validate.c\
    free_memory.c
LIBFT = $(LIBDIR)libft.a
OBJ = $(addprefix $(SRCDIR), $(SRC:.c=.o))
SRCDIR = ./src/
LIBDIR = ./libft/
FLAGS = -c -Wall -W -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	gcc -o $(NAME) $(OBJ) -L $(LIBDIR) -lft -I $(LIBDIR)

$(SRCDIR)%.o: $(SRCDIR)%.c
	gcc $(FLAGS) -o $@ $< -I $(LIBDIR)

$(LIBFT):
	@make -C $(LIBDIR) --silent

clean:
	@make -C $(LIBDIR) clean --silent
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C $(LIBDIR) fclean --silent
	@/bin/rm -f $(NAME)

re: fclean all

run: re
	clear
	./$(NAME) test.fillit
