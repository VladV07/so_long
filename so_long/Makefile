NAME			=	so_long

HEADER 			=	so_long.h

HEADER_GNL		=	gnl/get_next_line.h 

SRCS			=	unit.c \
					get_map.c \
					so_long.c \
					gnl/get_next_line.c \
					gnl/get_next_line_utils.c 

OBJ				=	${addprefix ,${SRCS:.c=.o}}

MLX				=	-L mlx -lmlx -framework OpenGL -framework AppKit

CC 				=	gcc

FLAGS			=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	make -s -C ./mlx
	$(CC) $(FLAGS) $(OBJ) -I $(HEADER) -I $(HEADER_GNL) $(MLX) -o $(NAME)

clean:
	make clean -C ./mlx
	@rm -rf ${OBJ}

fclean:	clean
	@rm -rf ${NAME}

re:		fclean all
	make re -C ./mlx

.PHONY:	all clean fclean re