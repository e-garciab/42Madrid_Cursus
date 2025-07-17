# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 12:29:38 by egarcia2          #+#    #+#              #
#    Updated: 2025/07/17 18:40:37 by egarcia2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server
NAME_CLIENT_BONUS = ./bonus/client_bonus
NAME_SERVER_BONUS = ./bonus/server_bonus

LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_CLIENT = client.c
SRCS_SERVER = server.c \
			server_utils.c
SRCS_CLIENT_BONUS = ./bonus/client_bonus.c
SRCS_SERVER_BONUS = ./bonus/server_bonus.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)

all: $(LIBFT) $(PRINTF) $(NAME_CLIENT) $(NAME_SERVER) 

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF) :
	$(MAKE) -C $(PRINTF_DIR)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) $(PRINTF) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) $(PRINTF) -o $(NAME_SERVER)

bonus: $(LIBFT) $(PRINTF) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS) 

$(NAME_CLIENT_BONUS): $(OBJS_CLIENT_BONUS)
	$(CC) $(CFLAGS) $(OBJS_CLIENT_BONUS) $(LIBFT) $(PRINTF) -o $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS)
	$(CC) $(CFLAGS) $(OBJS_SERVER_BONUS) $(LIBFT) $(PRINTF) -o $(NAME_SERVER_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o ./bonus/*.o
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	
fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re