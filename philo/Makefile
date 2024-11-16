CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = philo

SRCS = 	 check.c dining.c initialize.c main.c parcing.c parcing1.c utils.c


OBJS = ${SRCS:.c=.o}

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
NC=\033[0m

%.o: %.c philo.h
	@${CC} ${CFLAGS} -c $< -o $@

all : ${NAME}

${NAME} : ${OBJS}
	@${CC}  ${CFLAGS} ${OBJS} -o ${NAME}
	@echo  "${GREEN} [files compiled]${NC}" 
 

clean:
	@rm -rf ${OBJS}
	@echo  "${YELLOW} [files cleaned]${NC}" 

fclean: clean
	@rm -rf ${NAME}

re: fclean all

.PHONY : all clean fclean re