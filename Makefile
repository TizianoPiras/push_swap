# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/21 14:30:26 by ertiz             #+#    #+#              #
#    Updated: 2023/05/21 18:32:18 by ertiz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH = ./libft

NAME = push_swap

OUTPUT = push_swap.a

HEADER = $(NAME:.a=.h)

SOURCES = init.c \
main.c \
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
			
OBJ = $(SOURCES:.c=.o)

LIBC = ar -rcs

CC = gcc

RM = rm -f

MAKEFLAGS += --silent

all: $(NAME)

$(NAME): $(OUTPUT)
		$(CC) $< -o $@

$(OUTPUT): $(OBJ)
		$(LIBC) $(OUTPUT) $^

%.o:%.c
		@$(CC) -Wall -Wextra -g -O2 -c $< -o $@
		@echo "\033[36mDAJE!\033[0m"
		
clean:
		@$(RM) $(OBJ) $(OUTPUT)
		@echo "\033[35mTutto pulito ^^\033[0m"

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re