STD_MAP		=	map.ber
SMALL_MAP	=	map1.ber
NAME 		=	so_long
CC			=	clang
FLAGS		=	-Wall -Wextra -Werror -std=c99 -g #-fsanitize=leak \
-fsanitize=address
LIB_BIN		=	external/minilibx/libmlx_Linux.a
MLX_DIR		=	external/minilibx
LIB			=	-L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz
INCLUDES	=	external/minilibx
HEADER		=	includes/so_long.h includes/so_long_bonus.h
SRC			=	src/draw_utils.c src/keyboard_processor.c \
				src/app_controller.c	\
				utils/ft_putstr_fd.c utils/ft_putchar_fd.c \
				utils/get_next_line.c utils/get_next_line_utils.c \
				utils/ft_lstadd_back.c utils/ft_lstclear.c \
				utils/ft_lst_del_str.c utils/ft_strdup.c \
				utils/ft_strlcpy.c  utils/ft_lstnew.c \
				utils/free_str_array.c  utils/ft_error_null.c \
				src/mem_utils.c\
				src/collisions.c\
				utils/ft_lstdelone.c\
				utils/ft_putnbr_fd.c\
				src/map_utils.c src/position.c \
				src/checker.c utils/ft_strchr.c \
				utils/ft_str_cons_only.c src/checker_map_content.c \
				src/init.c src/main.c src/render_utils.c
SRC_B		=	$(subst .c,_bonus.c,$(addprefix bonus/, ${SRC}))
SRC_B		+=	bonus/src/dao_img_bonus.c bonus/src/enemy_processor_bonus.c \
				bonus/src/random_bonus.c \
				bonus/src/print_status_bonus.c \
				bonus/src/common_utils_bonus.c
OBJS		= 	${SRC:.c=.o}
OBJ_M		=	${SRC_M:.c=.o}
OBJ_B		=	${SRC_B:.c=.o}

%.o:		%.c $(HEADER)
			$(CC) $(FLAGS) -g -I$(INCLUDES) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C $(MLX_DIR)
			$(CC) $(FLAGS) -o $@ $^ $(LIB)

bonus:		$(OBJ_B)
			make -C $(MLX_DIR)
			$(CC) $(FLAGS) -o $(NAME) $(OBJ_B) $(LIB)

clean:
			make -C $(MLX_DIR) clean
			rm -f ${OBJS}
			rm -f ${OBJ_M}
			rm -f ${OBJ_B}
			rm -f valgrind-out.txt

fclean:		clean
			make -C $(MLX_DIR) clean
			rm -f ${LIB_BIN}
			rm -f ${NAME}

re:			fclean all

val:		${NAME}
			valgrind \
			--leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			--verbose \
			--log-file=valgrind-out.txt \
			./${NAME} ${SMALL_MAP}

val_bonus:	bonus
			valgrind \
			--leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			--verbose \
			--log-file=valgrind-out.txt \
			./${NAME} ${SMALL_MAP}

.PHONY:		val re all clean fclean bonus val_bonus

