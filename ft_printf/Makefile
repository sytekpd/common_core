NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ_DIR = objs

SRC_FILES_PART1 = ft_printf.c \
				ft_putchar.c \
				ft_putnbr.c \
				ft_putunbr.c \
				ft_numlen.c \
				ft_putstr.c \
				ft_putptr.c \
				ft_strlen.c 
SRC_FILES_HANDLERS = handle_char.c \
				handle_hex.c \
				handle_int.c \
				handle_percent.c \
				handle_pointer.c \
				handle_string.c \
				handle_unsigned_int.c 
SRC_FILES_BONUS =

OBJ_FILES_PART1 = $(addprefix $(OBJ_DIR)/,$(SRC_FILES_PART1:.c=.o))
OBJ_FILES_HANDLERS = $(addprefix $(OBJ_DIR)/,$(SRC_FILES_HANDLERS:.c=.o))
OBJ_FILES_BONUS = $(addprefix $(OBJ_DIR)/,$(SRC_FILES_BONUS:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_FILES_PART1) $(OBJ_FILES_HANDLERS) $(OBJ_FILES_BONUS)
	ar rcs $(NAME) $(OBJ_FILES_PART1) $(OBJ_FILES_HANDLERS) $(OBJ_FILES_BONUS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	$(CC) $(CFLAGS) main.c -L. -lftprintf -o ft_printf
	./ft_printf

lint:
	c_formatter_42 $(SRC_FILES_PART1) $(SRC_FILES_HANDLERS) $(SRC_FILES_BONUS) libftprintf.h

.PHONY: all clean fclean re
