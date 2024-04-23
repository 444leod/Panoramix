##
## EPITECH PROJECT, 2024
## myTeams
## File description:
## Makefile
##

NAME_LIB = libmy.a

SRC_LIB = 	my/debug_print.c \
	my/escaped_string.c \
	my/garbage_collector.c \
	my/garbage_llist.c \
	my/my_error.c \
	my/my_snprintf.c \
	my/my_strdup.c \
	my/replace_char.c \
	my/str_to_word_array.c \
	my/supercat.c \
	my/tablen.c \
	my/quote_splitter.c \
	my/linked_list.c \
	my/my_exit.c \
	my/is_positive_number.c \

CC = gcc

CFLAGS = -I../include -Wall -Wextra -Werror -Wpedantic

OBJ_LIB = $(SRC_LIB:.c=.o)

%.o: %.c
	@$(CC) -c $< -o $@ $(CFLAGS)

all: $(NAME_LIB)

$(NAME_LIB): $(OBJ_LIB)
	@ar rc $(NAME_LIB) $(OBJ_LIB)

clean:
	@rm -f $(OBJ_LIB) $(OBJ_DEV)

fclean: clean
	@rm -f $(NAME_LIB)

re: fclean all

debug: all

.PHONY: all clean fclean re
