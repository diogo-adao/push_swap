# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 14:36:48 by diolivei          #+#    #+#              #
#    Updated: 2024/09/17 14:54:17 by diolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a
LIBFT_FLAGS = -Llibft -lft

SRCS = $(wildcard src/*.c)
NAME = push_swap

BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
BOLD_YELLOW	=	\033[1;33m
BOLD_GREEN = \033[1;32m
NO_COLOR	=	\033[0m

all: $(NAME)
	@sleep 0.5
	@echo "\n✅ $(BOLD_GREEN)Compilation completed!\n$(NO_COLOR)"
	@echo "  /\_/\  (\n ( ^.^ ) _)\n   \\\"/  (\n ( | | )\n(__d b__)\n"

$(NAME): $(SRCS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $(SRCS) $(LIBFT) $(LIBFT_FLAGS)

$(LIBFT):
	@make -C libft > /dev/null 2>&1
	@echo "\n $(BOLD_CYAN)Starting...\n$(NO_COLOR)"
	@sleep 1
	@echo "\n📚 $(BOLD_PURPLE)Libft compiled.$(NO_COLOR)\n"

clean:
	@make -C libft clean > /dev/null 2>&1
	@echo "\n🧹 $(BOLD_YELLOW)Project cleaned.$(NO_COLOR)\n"

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean > /dev/null 2>&1

re: fclean all

PHONY: all clean fclean re
