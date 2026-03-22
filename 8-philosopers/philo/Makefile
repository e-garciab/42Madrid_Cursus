# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/26 21:37:29 by egarcia2          #+#    #+#              #
#    Updated: 2026/03/22 20:06:25 by egarcia2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#program name
NAME = philo

#compilation flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

#program directories
INCLUDE_DIR = include
SRC_DIR = src

#source files
SRCS = \
	$(SRC_DIR)/init.c \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/parser_utils.c \
	$(SRC_DIR)/parser.c \
	$(SRC_DIR)/utils.c \
	$(SRC_DIR)/routine.c \
	$(SRC_DIR)/monitor.c \

#object files
OBJS = $(SRCS:.c=.o)

#includes
INCLUDES = -I$(INCLUDE_DIR)

#main rule
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) -pthread

#object compilation
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#clean obj files
clean:
	rm -f $(OBJS)

#clean objs files and name
fclean: clean
	rm -f $(NAME)

#recompile
re: fclean all

#phony targets
.PHONY: all clean fclean re
