NAME = pipex
NAME_BONUS = pipex_bonus
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror

SRC =	main.c \
		pipex_utils.c \
		error.c \

SRC_BONUS =	bonus/main_bonus.c \
			bonus/pipex_utils_bonus.c \
			bonus/error_bonus.c \

LIBFT = cd ./libft && make
LIBINC = ./libft/libft.a
			

OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	${LIBFT}
	${CC} ${FLAGS} ${OBJ} ${LIBINC} -o ${NAME} 

${NAME_BONUS}: ${OBJ_BONUS}
	${LIBFT}
	${CC} ${FLAGS} ${OBJ_BONUS} ${LIBINC} -o ${NAME_BONUS}

all: ${NAME}

bonus: ${NAME_BONUS}

clean:
	${RM} ${OBJ}
	${RM} ${OBJ_BONUS}
	@make clean -C ./libft

fclean: clean
	${RM} ${NAME}
	${RM} ${NAME_BONUS}
	@make fclean -C ./libft

re: clean all

.PHONY: all clean fclean re bonus