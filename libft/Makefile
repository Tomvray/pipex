SRCS		= ft_is.c \
			ft_itoa.c \
			ft_put.c \
			ft_str1.c \
			ft_str2.c \
			ft_strjoin.c \
			ft_substr.c \
			ft_to.c \
			ft_mem.c \
			ft_memcmp.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strmapi.c \
			ft_strtrim.c \
			ft_striteri.c \
			ft_split.c \

SRCS_BONUS	= ft_lst1_bonus.c \
			ft_lst2_bonus.c

NAME		= libft.a

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

bonus: ${OBJS} ${OBJS_BONUS}
	ar rcs ${NAME} ${OBJS} ${OBJS_BONUS}

clean:
	${RM} ${OBJS}
	${RM} ${OBJS_BONUS}

fclean:	clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
