# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedrorodrigues <pedrorodrigues@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 01:04:12 by pedrorodrig       #+#    #+#              #
#    Updated: 2023/05/12 01:04:13 by pedrorodrig      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC_DIR = .
SRC_FILES_PART1 = ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \

SRC_FILES_PART2 = ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c

SRC_FILES_BONUS = ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c

OBJ_DIR = ./objs
OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(SRC_FILES_PART1:.c=.o) $(SRC_FILES_PART2:.c=.o))
OBJ_FILES_BONUS = $(addprefix $(OBJ_DIR)/,$(SRC_FILES_BONUS:.c=.o))

$(OBJ_FILES): | $(OBJ_DIR)

.PHONY: all clean fclean re lint

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(OBJ_FILES_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f executable

re: fclean all

bonus: $(OBJ_FILES_BONUS)
	ar rcs $(NAME) $(OBJ_FILES_BONUS)

lint:
	c_formatter_42 $(SRC_FILES_PART1) $(SRC_FILES_PART2) $(SRC_FILES_BONUS) libft.h
