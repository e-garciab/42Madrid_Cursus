# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 13:12:02 by egarcia2          #+#    #+#              #
#    Updated: 2025/02/24 11:09:54 by egarcia2         ###   ########.fr        #
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
	ft_print_hex.c \
	ft_print_ptr.c

#Object files
OBJS = $(SRCS:.c=.o)

#Principal rule
all: $(NAME)

#Library's construction
$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

#Source files compilation
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#Rule that cleans the temporary files (.o)
clean:
	rm -f $(OBJS)
	
#Rule that cleans .a
fclean: clean
	rm -f $(NAME)

#Rule that cleans and compiles all again
re: fclean all

#Phony targets (specifies that all, clean, fclean and re are not files, just rule names)
.PHONY: all clean fclean re