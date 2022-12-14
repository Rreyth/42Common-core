# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 15:21:23 by tdhaussy          #+#    #+#              #
#    Updated: 2022/12/13 21:25:33 by tdhaussy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME = so_long

SRC =	srcs/so_long.c \
		srcs/so_long_check.c \
		srcs/so_long_errors.c \
		srcs/so_long_free.c \
		srcs/so_long_map.c \
		srcs/so_long_utils.c \
		srcs/so_long_utils_map.c \
		srcs/game_utils.c \
		srcs/game_display.c \
		srcs/player_move.c

RM = rm -rf

OBJ =	$(SRC:srcs/%.c=objs/%.o)

OBJ_DIR = objs

CFLAGS = -Wall -Wextra -Werror -g3

all:	$(NAME)

objs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $^ -o $(<:srcs/%.c=objs/%.o)

$(OBJ_DIR):
		mkdir $@

$(NAME):	$(OBJ_DIR) $(OBJ)
		@echo "**********************"
		@echo "*     \033[1;33mCOMPILING\033[1;0m      *"
		@echo "**********************\n"
		@make -C libft
		@make -C minilibx-linux
		$(CC) $(CFLAGS) $(OBJ) libft/libft.a minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a -L/usr/lib -lXext -lX11 -lm -lz -o $@
		@echo "**********************"
		@echo "*        \033[1;32mDONE\033[1;0m        *"
		@echo "**********************"

clean:
		$(RM) $(OBJ_DIR)
		@make clean -C libft
		@make clean -C minilibx-linux
		@echo "**********************"
		@echo "*    \033[1;32mCLEANED OBJS\033[1;0m    *"
		@echo "**********************"


fclean:
		$(RM) $(OBJ_DIR) $(NAME)
		@make fclean -C libft
		@make clean -C minilibx-linux
		@echo "**********************"
		@echo "*     \033[1;32mCLEANED ALL\033[1;0m    *"
		@echo "**********************"


re:		fclean	all
.PHONY:	all clean fclean re
.SILENT:
