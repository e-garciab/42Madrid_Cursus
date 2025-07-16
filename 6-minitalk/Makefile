# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 12:29:38 by egarcia2          #+#    #+#              #
#    Updated: 2025/07/16 11:58:12 by egarcia2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name of the programs
NAME_CLIENT = client
NAME_SERVER = server

#Libft configuration
LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

#Compilation flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

#Source files
SRCS_CLIENT = client.c
SRCS_SERVER = server.c

#Object files
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

#Main rule
all: $(LIBFT) $(PRINTF) $(NAME_CLIENT) $(NAME_SERVER) 

#Rule for libft compilation
$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF) :
	$(MAKE) -C $(PRINTF_DIR)

#Rule for client program compilation
$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) $(PRINTF) -o $(NAME_CLIENT)

#Rule for server program compilation
$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) $(PRINTF) -o $(NAME_SERVER)

#Individual object compilation
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#Rule for cleaning temporary files (.o)
clean:
	rm -f *.o
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	
#Rule for cleaning all objects(included program and libft.a)
fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

#Rule for re-compiling
re: fclean all

#Phony targets
.PHONY: all clean fclean re