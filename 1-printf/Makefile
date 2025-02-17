# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 13:12:02 by egarcia2          #+#    #+#              #
#    Updated: 2025/02/17 14:56:33 by egarcia2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name of my static library
NAME = libftprintf.a

#Compiler
CC = cc

#Compilation flags
CFLAGS = -Wall -Wextra -Werror

#Source code
SRCS = ft_printf.c \
	ft_print_char.c \
	ft_print_str.c \
	ft_print_nbr.c \
	ft_print_unsigned_nbr.c \
	main.c

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I $(LIBFT_DIR)

#Object files
OBJS = $(SRCS:.c=.o)

#Principal rule
all: $(LIBFT) $(NAME)

#Library's construction
$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

#Source files compilation
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) all clean

#Rule that cleans the temporary files (.o)
clean:
	rm -f $(OBJS)
	
#Rule that cleans .a
fclean: clean
	rm -f $(NAME) $(LIBFT)

#Rule that cleans and compiles all again
re: fclean all

#Phony targets (specifies that all, clean, fclean and re are not files, just rule names)
.PHONY: all clean fclean re