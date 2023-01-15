# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 15:21:23 by tdhaussy          #+#    #+#              #
#    Updated: 2023/01/15 09:31:33 by tdhaussy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME = pipex

SRC =	srcs/pipex.c \
		srcs/pipex_utils.c

RM = rm -rf

MAKEFLAGS =		--no-print-directory

OBJ =	$(SRC:srcs/%.c=objs/%.o)

OBJ_DIR = objs

CFLAGS = -Wall -Wextra -Werror -g3

all:	$(NAME)

objs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $^ -o $(<:srcs/%.c=objs/%.o)

$(OBJ_DIR):
		mkdir $@

$(NAME):	$(OBJ_DIR) $(OBJ)
		@echo "**********************"
		@echo "*     \033[1;33mCOMPILING\033[1;0m      *"
		@echo "**********************\n"
		@make -C libft
		$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $@
		@echo "**********************"
		@echo "*        \033[1;32mDONE\033[1;0m        *"
		@echo "**********************"

clean:
		$(RM) $(OBJ_DIR)
		@make clean -C libft
		@echo "**********************"
		@echo "*    \033[1;32mCLEANED OBJS\033[1;0m    *"
		@echo "**********************"

fclean:
		$(RM) $(OBJ_DIR) $(NAME)
		@make fclean -C libft
		@echo "**********************"
		@echo "*     \033[1;32mCLEANED ALL\033[1;0m    *"
		@echo "**********************"

re:		fclean	all
.PHONY:	all clean fclean re
