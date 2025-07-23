# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/19 16:36:23 by egarcia2          #+#    #+#              #
#    Updated: 2025/07/23 13:35:02 by egarcia2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Nombre del ejecutabe
NAME = fractol

#compilador y flags de compilación
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
INCLUDE_DIR = include
LIBFT_DIR = libft
PRINTF_DIR = ft_printf
MLX_DIR = minilibx-linux

#Archivos fuente
SRCS = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/init.c \
	$(SRC_DIR)/render.c \
	$(SRC_DIR)/math_utils.c \
	$(SRC_DIR)/events.c \

#Archivos objeto
OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MLX = $(MLX_DIR)/libmlx.a

#Flags de minilibx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lm -lX11 -lXext

INCLUDES = -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MLX_DIR)

#Regla principal
all: $(MLX) $(LIBFT) $(PRINTF) $(NAME) #para construir all, primero compila la libft y después comopila el programa

$(MLX):
	@make -C $(MLX_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)
	
#Regla para compilar el programa con lift.a (compila el ejecutable con los .o y enlaza libft.a, con -o NAME crea el binario final llamado push_swap)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf $(MLX_FLAGS)
	
#Compilación de objetos individuales
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#Limpiar los archivos temporales generados (.o)
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	
#Limpiar todo (incluuido ejecutable y libft.a)
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean

#Volver a compilar todo desde cero
re: fclean all

#Phony targets (especifica quee all y clean no son archivos sino nombres de reglas)
.PHONY: all clean fclean re


# REVISAR A PARTIR DE AQUÍ:
#Configuración de la libft y ft_printf
#LIBFT_DIR = ./libft
#PRINTF_DIR = ./ft_printf
#LIBFT = $(LIBFT_DIR)/libft.a
#PRINTF = $(PRINTF_DIR)/libftprintf.a
#MLX_DIR = ./minilibx-linux
#MLX_LIB = $(MLX_DIR)/libmlx.a


#Regla para compilar libft (le dice a make que ejecute el makefile dentro del directorio libft/)
#$(LIBFT) :
#	$(MAKE) -C $(LIBFT_DIR)

#$(PRINTF) :
#	$(MAKE) -C $(PRINTF_DIR)




