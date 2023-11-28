SRCS =	parsing/get_next_line.c \
		parsing/get_next_line_utils.c \
		parsing/ft_split.c \
		parsing/ft_split2.c \
		main.c \


NAME = cub3D

INC = -Iinclude

FLAGS = -g3 -Wall -Werror -Wextra


OBJS = ${SRCS:.c=.o}

LIBFT = libft.a

${NAME} : ${OBJS} 
		cc $(OBJS) ${INC}  ${FLAGS} -o $(NAME)



all : ${NAME}

%.o:%.c
		cc ${FLAGS} ${INC}  -c $< -o $@

leaks: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes   ./cub3d map.cub

clean :
		rm -rf ${OBJS}

fclean : clean
		rm -rf ${NAME}
		

re : fclean all

.PHONY : all  clean fclean re libft NAME 