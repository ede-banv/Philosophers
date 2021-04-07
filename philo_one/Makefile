CC = gcc
C_FLAGS = -Wall -Werror -Wextra
NAME = Philosophers
SRCS = main.c parsing.c ph_stop.c ph_utils.c utils.c
OBJS = ${SRCS:.c=.o}

$(NAME):	${OBJS}
	${CC} ${C_FLAGS} -o ${NAME} ${OBJS}

all:	${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all