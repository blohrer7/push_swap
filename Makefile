# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 16:36:09 by blohrer           #+#    #+#              #
#    Updated: 2025/03/02 16:08:30 by blohrer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

SRC = 	src/errors.c \
		src/main.c \
		src/sort_utils.c \
		src/stack_init.c \
		stack_ops/push.c \
		stack_ops/reverse_rotate.c \
		stack_ops/rotate.c \
		stack_ops/swap.c \
		src/sort.c \
		src/utils.c \
		src/big_sort.c

OFILES = $(SRC:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDES = -I $(LIBFT_DIR)

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
FT_PRINTF_INCLUDES = -I $(FT_PRINTF_DIR)

INCLUDES = $(LIBFT_INCLUDES) $(FT_PRINTF_INCLUDES)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR) all

$(NAME): $(OFILES) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT) $(FT_PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OFILES)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
