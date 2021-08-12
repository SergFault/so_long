NAME 		=	so_long
CC			=	clang
FLAGS		=	-Wall -Wextra -Werror -std=c99 -g  # -fsanitize=address
MLX_DIR		=	external/minilibx
LIB			=	-L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz
INCLUDES	=	external/minilibx
HEADER		=	includes/so_long.h
SRC			=	src/so_long.c src/draw_utils.c src/keyboard_processor.c \
				src/app_controller.c	\
				utils/ft_putstr_fd.c utils/ft_putchar_fd.c \
				utils/get_next_line.c utils/get_next_line_utils.c \
				utils/ft_lstadd_back.c utils/ft_lstclear.c \
				utils/ft_lst_del_str.c utils/ft_strdup.c \
				utils/ft_strlcpy.c  utils/ft_lstnew.c \
				utils/free_str_array.c  utils/ft_error_null.c \
				src/render_utils.c src/init.c \
				utils/free_str_ptr.c src/mem_utils.c\
				src/collisions.c\
				utils/ft_lstdelone.c\
				utils/ft_putnbr_fd.c\
				src/map_utils.c src/position.c
OBJ 		= 	${SRC:.c=.o}

%.o:%.c $(HEADER)
	$(CC) $(FLAGS) -g -I$(INCLUDES) -c $< -o $@

all:	$(NAME)

clean:
	rm -f $(OBJ)

$(NAME):	$(OBJ)
				make -C external/minilibx
				$(CC) $(FLAGS) -g -o $@ $^ $(LIB)

