# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 12:29:38 by egarcia2          #+#    #+#              #
#    Updated: 2025/07/07 16:15:48 by egarcia2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name of the programs
NAME_CLIENT = client
NAME_SERVER = server

#Libft configuration
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

#Compilation flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

#Source files
SRCS_CLIENT = client.c
SRCS_SERVER = server.c

#Object files
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

#Main rule
all: $(LIBFT) $(NAME_CLIENT) $(NAME_SERVER) 

#Rule for libft compilation
$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

#Rule for client program compilation
$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(NAME_CLIENT)

#Rule for server program compilation
$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $(NAME_SERVER)

#Individual object compilation
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#Rule for cleaning temporary files (.o)
clean:
	rm -f *.o
	$(MAKE) -C $(LIBFT_DIR) clean
	
#Rule for cleaning all objects(included program and libft.a)
fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	$(MAKE) -C $(LIBFT_DIR) fclean

#Rule for re-compiling
re: fclean all

#Phony targets
.PHONY: all clean fclean re