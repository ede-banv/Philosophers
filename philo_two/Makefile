CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = philo_two
SRCS =
OBJS = ${SRCS:.c=.o}

$(NAME):	${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:	${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all