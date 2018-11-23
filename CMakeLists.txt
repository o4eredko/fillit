cmake_minimum_required(VERSION 3.12)
project(fillit C)

set(CMAKE_C_STANDARD 99)

add_executable(fillit main.c libft/ft_putlong libft/ft_dlstfind.c libft/ft_dlstgetend.c libft/ft_dlstnew.c libft/ft_dlstinsert.c
        libft/ft_dlstprint.c libft/ft_putchar libft/ft_memcpy libft/ft_putnbr.c libft/ft_putstr.c libft/ft_putlong.c src/algorithm_x.c
        src/stack.c src/print_functions.c libft/ft_putendl.c libft/ft_memalloc.c libft/ft_dlstgetn.c src/delete_restore.c
        src/row_col_functions.c src/fill_cords.c src/set_dlist.c src/validate.c libft/ft_dlstaddcolumn.c libft/ft_dlstrowcount.c
        libft/ft_strlen.c libft/ft_strnew.c libft/get_next_line.c libft/ft_lstnew.c src/create_matrix.c
        libft/ft_memset.c libft/ft_strdel.c libft/ft_memdel.c libft/ft_atoi.c libft/ft_lstadd.c src/create_matrix.c src/set_dlist.c
        libft/ft_itoa.c libft/ft_strjoin.c libft/ft_strcat.c libft/ft_strchr.c)