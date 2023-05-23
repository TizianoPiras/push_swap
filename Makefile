# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpiras <tpiras@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/21 14:30:26 by ertiz             #+#    #+#              #
#    Updated: 2023/05/23 18:05:05 by tpiras           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH = ./libft

GNL_PATH = ./get_next_line

NAME = push_swap

BONUS = checker

#OUTPUT = push_swap.a

#HEADER = $(NAME:.a=.h)

MAIN = main.c \

SOURCES = init.c \
errors.c \
push_swap_utils.c \
push_swap.c \
push.c \
reverse_rotate.c \
rotate.c \
short_sort.c \
stack_init.c \
swap.c \
$(LIBFT_PATH)/ft_atoi.c \
$(LIBFT_PATH)/ft_itoa.c \
$(LIBFT_PATH)/ft_split.c \
$(LIBFT_PATH)/ft_strlen.c \
$(LIBFT_PATH)/ft_substr.c \

BONUS_SRC = checker.c \
$(GNL_PATH)/get_next_line.c \
$(GNL_PATH)/get_next_line_utils.c \
$(LIBFT_PATH)/ft_strncmp.c \
			
OBJ = $(SOURCES:.c=.o)

OBJ_MAIN = $(MAIN:.c=.o)

OBJ_BONUS = $(BONUS_SRC:.c=.o)

LIBC = ar -rcs

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

#MAKEFLAGS += --silent

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN)
		$(CC) $(OBJ) $(OBJ_MAIN) -o $@ 
		@echo "\033[36mDAJE!\033[0m"

#$(OUTPUT): $(OBJ) $(MAIN)
#		$(LIBC) $(OUTPUT) $^

bonus: $(OBJ) $(OBJ_BONUS)
		$(CC) $(OBJ) $(OBJ_BONUS) -o $(BONUS)
		@echo "\033[36mDAJE col CHECKER!\033[0m"

.o:.c
		@$(CC) -Wall -Wextra -Werror -g -c $< -o $(<:.c=.o)



clean:
		@$(RM) $(OBJ) $(OUTPUT) $(OBJ_MAIN) $(OBJ_BONUS)
		@echo "\033[35mTutto pulito ^^\033[0m"

fclean: clean
		$(RM) $(NAME)
		$(RM) $(BONUS)
re: fclean all

.PHONY: all clean fclean re