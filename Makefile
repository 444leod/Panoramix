##
## EPITECH PROJECT, 2024
## Panoramix
## File description:
## Makefile
##

GREEN=\033[0;32m
NC=\033[0m

INFO = ${GREEN}[INFO]${NC}

NAME = panoramix

SRC = main.c \
	src/panoramix.c \
	src/create_villager.c \
	src/villager_loop.c \
	src/logger.c  \
	src/create_druid.c \
	src/druid_loop.c \

%.o: %.c
	@$(CC) -c $< -o $@ $(CFLAGS)

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Wpedantic -I./include -L./lib -lmy

all: $(NAME)

$(NAME): $(OBJ)
	@make -sC lib
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
	@echo -ne "${INFO} Panoramix compiled successfully.${NC}\n"

clean:
	@make -sC lib clean
	@rm -f $(OBJ)
	@echo -ne "${INFO} Repository cleaned.${NC}\n"

fclean: clean
	@make -sC lib fclean
	@rm -f $(NAME)
	@echo -ne "${INFO} Repository fully cleaned.${NC}\n"

re: fclean all

tests_run: all

run: all

init: install-hooks install-mango

dev: lib
	@$(CC) -g -o $(NAME) $(SRC) $(CFLAGS) -DDEV_MODE
	@echo -ne "${INFO} Panoramix compiled successfully in dev mode.${NC}\n"

install-hooks:
	@cp .githooks/commit-msg .git/hooks/commit-msg
	@chmod +x .git/hooks/commit-msg
	@echo "Hooks installed."

install-mango:
	@chmod +x ./init/install-mango.sh
	@./init/install-mango.sh

.PHONY: all clean fclean re
.SILENT: run
