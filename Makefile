NAME 		=	so_long
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -std=c99 -g
MLX_DIR		=	external/minilibx
LIB			=	-L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz
INCLUDES	=	external/minilibx
SRC			=	src/so_long.c src/draw_utils.c src/keyboard_processor.c \
				src/app_controller.c
OBJ 		= 	${SRC:.c=.o}

%.o:%.c
	$(CC) $(FLAGS) -g -I$(INCLUDES) -c $< -o $@

all:	$(NAME)

clean:
	rm -f $(OBJ)

$(NAME):	$(OBJ)
				$(CC) $(FLAGS) -g -o $@ $^ $(LIB)

