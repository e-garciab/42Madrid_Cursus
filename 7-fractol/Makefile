# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/19 16:36:23 by egarcia2          #+#    #+#              #
#    Updated: 2025/07/19 16:39:53 by egarcia2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Nombre del ejecutabe
NAME = fractol

#Configuración de la libft y ft_printf
LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

#compilador y flags de compilación
CC = cc
CFLAGS = -Wall -Wextra -Werror

#Archivos fuente
SRCS = main.c \


#Archivos objeto
OBJS = $(SRCS:.c=.o)

#Regla principal
all: $(LIBFT) $(PRINTF) $(NAME) #para construir all, primero compila la libft y después comopila el programa

#Regla para compilar libft (le dice a make que ejecute el makefile dentro del directorio libft/)
$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF) :
	$(MAKE) -C $(PRINTF_DIR)

#Regla para compilar el programa con lift.a (compila el ejecutable con los .o y enlaza libft.a, con -o NAME crea el binario final llamado push_swap)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

#Compilación de objetos individuales
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#Limpiar los archivos temporales generados (.o)
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	
#Limpiar todo (incluuido ejecutable y libft.a)
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

#Volver a compilar todo desde cero
re: fclean all

#Phony targets (especifica quee all y clean no son archivos sino nombres de reglas)
.PHONY: all clean fclean re