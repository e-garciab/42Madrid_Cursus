# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/26 21:37:29 by egarcia2          #+#    #+#              #
#    Updated: 2026/02/26 21:49:08 by egarcia2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#colors
GREEN		= \033[0;32m
RED 		= \033[0;31m
BOLD		= \033[1m
NORMAL		= \033[0m
UP 			= \033[A
CUT 		= \033[K

#program name
NAME = philo

#compilation flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

#program directories
SRC_DIR = src
INCLUDE_DIR = include

#source files
SRCS = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/init.c \


#object files
OBJS = $(SRCS:.c=.o)

#includes
INCLUDES = -I$(INCLUDE_DIR)

#main rule
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	echo "$(GREEN)[$(BOLD)OK$(NORMAL)$(GREEN)]$(NORMAL) created and compiled object files"
	echo "$(GREEN)[$(BOLD)OK$(NORMAL)$(GREEN)]$(NORMAL) $(BOLD)$(NAME)$(NORMAL) is ready"
	
#object compilation
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#clean obj files
clean:
	rm -f $(OBJS)
	echo "$(GREEN)[$(BOLD)OK$(NORMAL)$(GREEN)]$(NORMAL) object files deleted"
	
#clean objs files and name
fclean: clean
	rm -f $(NAME)
	echo "$(GREEN)[$(BOLD)OK$(NORMAL)$(GREEN)]$(NORMAL) $(BOLD)$(NAME)$(NORMAL) deleted"

#recompile
re: fclean all

#phony targets
.PHONY: all clean fclean re
