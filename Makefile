
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
HEAD_NAME = $(wildcard $(HEAD_DIR)/*.h)

SRC = $(wildcard src/**/*.c)
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -c -I$(LIBFT_HEAD_DIR) -I$(HEAD_DIR) -I$(FT_PRINTF_DIR)
# CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -L$(LIBFT_DIR)
LDLIBS = -lft

.PHONY: clean fclean re all test

%.o: %.c
	@$(CC) $(CFLAGS) $< -o $@ 

all: $(NAME)

test: $(NAME)
	@test/test.sh

test/5: $(NAME)
	@./test/many.sh ./test/resource/all_5

test/6: $(NAME)
	@./test/many.sh ./test/resource/all_6

test/7: $(NAME)
	@./test/many.sh ./test/resource/all_7

$(LIBFT):
	@$(MAKE) all -sC ./$(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT) $(HEAD_NAME)
	@$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $@

clean:
	@$(MAKE) clean -sC ./$(LIBFT_DIR)
	@$(RM) $(OBJ)

fclean: clean
	@$(MAKE) fclean -sC ./$(LIBFT_DIR)
	@$(RM) $(NAME)

re: fclean all
