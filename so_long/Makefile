# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 15:21:23 by tdhaussy          #+#    #+#              #
#    Updated: 2022/12/04 17:27:43 by tdhaussy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME = so_long

#BONUS =

SRC =	srcs/so_long.c

#SRC_BONUS =

RM = rm -rf

OBJ =	$(SRC:srcs/%.c=objs/%.o)

#OBJ_BONUS =	$(SRC_BONUS:%.c=objs_bonus/%.o)

OBJ_DIR = objs

#OBJ_BONUS_DIR = objs_bonus

CFLAGS = -Wall -Wextra -Werror -g3

all:	$(NAME)

#bonus:	$(BONUS)

objs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $^ -o $(<:srcs/%.c=objs/%.o)

#objs_bonus/%.o: %.c
#	$(CC) $(CFLAGS) -c $^ -o $(<:%.c=objs_bonus/%.o)

$(OBJ_DIR):
		mkdir $@

#$(OBJ_BONUS_DIR):
#		mkdir $@

$(NAME):	$(OBJ_DIR) $(OBJ)
		@echo "**********************"
		@echo "*     \033[1;33mCOMPILING\033[1;0m      *"
		@echo "**********************\n"
		$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@
		@echo "**********************"
		@echo "*        \033[1;32mDONE\033[1;0m        *"
		@echo "**********************"

#$(BONUS):	$(OBJ_BONUS_DIR) $(OBJ_BONUS)
#		@echo "**********************"
#		@echo "*  \033[1;33mCOMPILING BONUS\033[1;0m   *"
#		@echo "**********************\n"
#		$(CC) $(CFLAGS) -o $@ $(OBJ_BONUS)
#		@echo "**********************"
#		@echo "*        \033[1;32mDONE\033[1;0m        *"
#		@echo "**********************"

clean:
		$(RM) $(OBJ_DIR) #$(OBJ_BONUS_DIR)
		@echo "**********************"
		@echo "*    \033[1;32mCLEANED OBJS\033[1;0m    *"
		@echo "**********************"


fclean:	clean
		$(RM) $(NAME) #$(BONUS)
		@echo "\n**********************"
		@echo "*   \033[1;32mCLEANED BINARY\033[1;0m   *"
		@echo "**********************"


re:		fclean	all
.PHONY:	all clean fclean re
#.SILENT: all clean fclean $(OBJ) $(NAME) $(OBJ_DIR) $(BONUS) $(OBJ_BONUS) $(OBJ_BONUS_DIR)
