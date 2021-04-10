CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
NAME = philo_one
SRCS = main.c parsing.c ph_stop.c ph_utils.c utils.c
OBJS = ${SRCS:.c=.o}

$(NAME):	${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:	${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all