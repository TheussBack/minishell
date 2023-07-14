# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/14 15:26:26 by hrobin            #+#    #+#              #
#    Updated: 2023/07/14 16:51:01 by hrobin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

SRCS =	main.c \
		parce.c

OBJS = ${SRCS:.c=.o}

INC = ./includes

FLAGS = -Wall -Wextra -Werror -g3

.c.o:
	${CC} ${FLAGS} -I${INC} -c $< -o ${<:.c=.o}

${NAME}:    ${OBJS}
	    ${CC} ${FLAGS} ${OBJS} -lreadline -o ${NAME}

all:    ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
