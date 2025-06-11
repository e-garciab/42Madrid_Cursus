# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 12:29:38 by egarcia2          #+#    #+#              #
#    Updated: 2025/06/11 21:32:34 by egarcia2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Nombre del ejecutabe
NAME = push_swap

#Datos de la libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

#compilador y flags de compilación
CC = cc
CFLAGS = -Wall -Wextra -Werror

#Archivos fuente
SRCS = push_swap.c \

#Archivos objeto
OBJS = $(SRCS:.c=.o)

#Regla principal
all: $(LIBFT) $(NAME)

#Compilación de la libft
$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

#Compilación del programa y enlace con libft
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS) -o $(NAME)

#Compilación de objetos individuales
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#Limpiar los archivos temporales generados (.o)
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	
#Limpiar todo (incluuido ejecutable y libft.a)
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

#Volver a compilar todo desde cero
re: fclean all

#Phony targets (especifica quee all y clean no son archivos sino nombres de reglas)
.PHONY: all clean fclean re