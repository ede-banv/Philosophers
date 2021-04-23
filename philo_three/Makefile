CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = philo_three
SRCS = main.c start.c utils.c parsing.c ph_utils.c
OBJS = ${SRCS:.c=.o}

$(NAME):	${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:	${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all