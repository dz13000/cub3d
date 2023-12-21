SRCS =	parsing/get_next_line.c \
		parsing/get_next_line_utils.c \
		parsing/ft_split.c \
		parsing/ft_split2.c \
		parsing/check_id.c \
		parsing/parsing.c \
		parsing/verif_map.c \
		parsing/verif_map2.c \
		parsing/check_player.c \
		parsing/check_spaces.c \
		parsing/check_zero.c \
		parsing/utils.c \
		graph/init.c \
		main.c \
		free_utils.c \


NAME = cub3D

INC = -Iinclude

FLAGS = -g3 -Wall -Werror -Wextra

MLX_FLAGS		=	-lm -lXext -lX11

OBJS = ${SRCS:.c=.o}


${NAME} : ${OBJS} 
		cc $(OBJS) ${INC} mlx/libmlx.a mlx/libmlx_Linux.a -L. -lXext -L. -lX11 -lm ${FLAGS} -o $(NAME)



all : ${NAME}

%.o:%.c
		cc ${FLAGS} ${INC}  -c $< -o $@



clean :
		rm -rf ${OBJS}

fclean : clean
		rm -rf ${NAME}
		

re : fclean all

.PHONY : all  clean fclean re libft NAME 