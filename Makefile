# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stopp <stopp@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/24 16:23:21 by stopp             #+#    #+#              #
#    Updated: 2024/04/26 16:26:34 by stopp            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFTPRINTF = lib/libftprintf.a

SRC_DIR = src
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/data_chk.c $(SRC_DIR)/setup_exec.c
OBJS = $(SRCS:.c=.o)
BONUS_DIR = bonus
BONUS_SRCS = $(BONUS_DIR)/main_bonus.c $(BONUS_DIR)/data_chk_bonus.c $(BONUS_DIR)/setup_exec_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

all: without_bonus

without_bonus: $(OBJS)
	make -C lib
	$(CC) $(CFLAGS) $(LIBFTPRINTF) $(OBJS) -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJS)
	make -C lib
	$(CC) $(CFLAGS) $(LIBFTPRINTF) $(BONUS_OBJS) -o $(NAME)
$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	make -C lib clean

fclean: clean
	rm -f $(NAME)
	make -C lib fclean

re: fclean all

.PHONY: all clean fclean re bonus
