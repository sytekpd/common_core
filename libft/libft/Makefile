NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC_DIR = .
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_DIR = ./objs
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f executable

re: fclean all

run: $(NAME)
	@$(CC) $(CFLAGS) main.c -o executable -L. -lft
	@./executable

bonus: 