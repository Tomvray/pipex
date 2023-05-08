NAME = pipex
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror

SRC =	main.c \
		pipex_utils.c \
		error.c \

LIBFT = cd ./libft && make
LIBINC = ./libft/libft.a
			

OBJ = ${SRC:.c=.o}

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	${LIBFT}
	${CC} ${FLAGS} ${OBJ} ${LIBINC} -o ${NAME} 

all: ${NAME}

clean:
	${RM} ${OBJ}
	@make clean -C ./libft

fclean: clean
	${RM} ${NAME}
	@make fclean -C ./libft

re: clean all

.PHONY: all clean fclean re bonus