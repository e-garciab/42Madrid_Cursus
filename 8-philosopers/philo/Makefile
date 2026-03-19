# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/26 21:37:29 by egarcia2          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2026/03/15 21:15:14 by egarcia2         ###   ########.fr        #
=======
#    Updated: 2026/03/17 20:40:29 by egarcia2         ###   ########.fr        #
>>>>>>> 11af22a0d168925e3a399f68c10c435fcaea5d9d
#                                                                              #
# **************************************************************************** #

#program name
NAME = philo

#compilation flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

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
