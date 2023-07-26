# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/14 15:26:26 by hrobin            #+#    #+#              #
#    Updated: 2023/07/26 18:32:17 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= minishell
SRC_DIR		:= src
BUILD_DIR:= .build
SRCS		:=  main.c \
				parsing/create_list.c \
				parsing/expend.c \
				parsing/type.c \
				builtins/echo.c \
				builtins/pwd.c \
				builtins/cd.c \

SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= cc -g3
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -MMD -MP -I include
RM			:= rm -rf
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D)
LIBRARIES	:= -L libft -lft
INCLUDES	:= -Ilibft/include

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(OBJS) $(LIBRARIES) -lreadline -o $(NAME)
	$(info CREATED $(NAME))
	clear

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c $< -o $@
	$(info CREATED $@)

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)
	make -C libft clean
	clear

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean
	clear

re: clean all

.PHONY: all re clean fclean
.SILENT:
