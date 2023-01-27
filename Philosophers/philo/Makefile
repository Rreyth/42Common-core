# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 15:12:23 by tdhaussy          #+#    #+#              #
#    Updated: 2023/01/27 17:37:51 by tdhaussy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME = philo

SRC =	srcs/philosophers.c \
		srcs/parsing.c \
		srcs/philo_routine.c

RM = rm -rf

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
		$(CC) $(CFLAGS) $(OBJ) -o $@ -lpthread
		@echo "**********************"
		@echo "*        \033[1;32mDONE\033[1;0m        *"
		@echo "**********************"

clean:
		$(RM) $(OBJ_DIR)
		@echo "**********************"
		@echo "*    \033[1;32mCLEANED OBJS\033[1;0m    *"
		@echo "**********************"

fclean:
		$(RM) $(OBJ_DIR) $(NAME)
		@echo "**********************"
		@echo "*     \033[1;32mCLEANED ALL\033[1;0m    *"
		@echo "**********************"

re:		fclean	all
.PHONY:	all clean fclean re
