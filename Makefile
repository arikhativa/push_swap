# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 14:32:48 by yoav              #+#    #+#              #
#    Updated: 2022/08/05 14:32:56 by yoav             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# ft_printf
FT_PRINTF_DIR = libft

# libft
LIBFT_NAME = libft.a
LIBFT_DIR = libft
LIBFT_HEAD_DIR = libft/libft
LIBFT  = $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

# push_swap
HEAD_DIR = include 
HEAD_NAME = \
	include/dll.h \
	include/define.h \
	include/sort.h \
	include/main.h \
	include/double_stack.h \
	include/input.h \
	include/stack.h \
	include/dll.h \
	include/define.h \
	include/sort.h \
	include/main.h \
	include/double_stack.h \
	include/input.h \
	include/stack.h

SRC = \
	src/dll/iterate.c \
	src/dll/dll_add.c \
	src/dll/dll.c \
	src/dll/dll_print.c \
	src/dll/swap.c \
	src/dll/dll_is.c \
	src/dll/dll_remove.c \
	src/dll/dll_get.c \
	src/sort/sort_two.c \
	src/sort/merge_sort.c \
	src/sort/first_round.c \
	src/sort/sort_five.c \
	src/sort/generic.c \
	src/sort/sort_four.c \
	src/sort/flip.c \
	src/sort/sort.c \
	src/sort/find_smallest.c \
	src/sort/sort_six.c \
	src/sort/sort_three.c \
	src/sort/sort_meta.c \
	src/main/main.c \
	src/double_stack/double_stack_pop.c \
	src/double_stack/double_stack_get.c \
	src/double_stack/double_stack_duplicates.c \
	src/double_stack/double_stack_twice.c \
	src/double_stack/double_stack_init.c \
	src/double_stack/double_stack_push.c \
	src/double_stack/double_stack.c \
	src/double_stack/double_stack_print.c \
	src/double_stack/double_stack_is_done.c \
	src/double_stack/double_stack_get_size.c \
	src/double_stack/double_stack_swap.c \
	src/double_stack/double_stack_rotate.c \
	src/input/atoi_overflow.c \
	src/input/skip.c \
	src/input/input.c \
	src/stack/stack.c \
	src/stack/stack_print.c \
	src/stack/stack_swap.c \
	src/stack/stack_get.c \
	src/stack/stack_set.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -c -Wall -Werror -Wextra -I$(LIBFT_HEAD_DIR) -I$(HEAD_DIR) -I$(FT_PRINTF_DIR)
LDFLAGS = -L$(LIBFT_DIR)
LDLIBS = -lft

.PHONY: clean fclean re all test

%.o: %.c $(HEAD_NAME)
	@$(CC) $(CFLAGS) $< -o $@ 

all: $(NAME)

$(LIBFT):
	@$(MAKE) all -sC ./$(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $@

clean:
	@$(MAKE) clean -sC ./$(LIBFT_DIR)
	@$(RM) $(OBJ)

fclean: clean
	@$(MAKE) fclean -sC ./$(LIBFT_DIR)
	@$(RM) $(NAME)

re: fclean all
