# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hbrouwer <hbrouwer@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/03 15:06:58 by hbrouwer      #+#    #+#                  #
#    Updated: 2022/10/06 16:21:47 by hbrouwer      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

AR = ar

ARFLAGS = -crs

FLAGS = -Wall -Werror -Wextra

SRC = ${wildcard *.c}

OBJS = ${SRC:.c=.o}

all: ${OBJS}

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${ARFLAGS} ${NAME} ${OBJS}

clean: 
	rm -f ${OBJS}
	
fclean:		clean
	rm -f ${NAME}

re:			fclean all
