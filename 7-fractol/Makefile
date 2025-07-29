# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/19 16:36:23 by egarcia2          #+#    #+#              #
#    Updated: 2025/07/28 12:51:47 by egarcia2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#program name
NAME = fractol

#compilation flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

#program directories
SRC_DIR = src
INCLUDE_DIR = include
LIBFT_DIR = libft
PRINTF_DIR = ft_printf
MLX_DIR = minilibx-linux

#source files
SRCS = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/init.c \
	$(SRC_DIR)/render.c \
	$(SRC_DIR)/color.c \
	$(SRC_DIR)/math_utils.c \
	$(SRC_DIR)/events.c \

#object files
OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MLX = $(MLX_DIR)/libmlx.a

#minilibx compilation flags
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lm -lX11 -lXext

#includes
INCLUDES = -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MLX_DIR)

#main rule
all: $(MLX) $(LIBFT) $(PRINTF) $(NAME)

$(MLX):
	@make -C $(MLX_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf $(MLX_FLAGS)
	
#object compilation
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#clean temporary objects
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	
#clean all
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean

#recompile
re: fclean all

#phony targets
.PHONY: all clean fclean re
