# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 20:21:23 by tdhaussy          #+#    #+#              #
#    Updated: 2022/11/30 17:39:05 by tdhaussy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME =	push_swap

BONUS = checker

SRC =	push_swap.c \
		push_swap_utils.c \
		push_swap_errors.c \
		args_to_stack.c \
		ft_split.c \
		ft_split_utils.c \
		sort_utils.c \
		sort_utils2.c \
		small_sort.c \
		global_sort.c \
		g_sort_utils.c \
		ft_free.c

SRC_BONUS = checker_bonus.c \
			checker_sort_bonus.c \
			checker_sort2_bonus.c \
			push_swap_errors.c \
			push_swap_utils.c \
			args_to_stack.c \
			ft_free.c \
			ft_split.c \
			ft_split_utils.c \
			get_next_line.c \
			get_next_line_utils.c

MAKEFLAGS =	--no-print-directory

RM = rm -rf

OBJ =	$(SRC:%.c=objs/%.o)

OBJ_BONUS =	$(SRC_BONUS:%.c=objs_bonus/%.o)

OBJ_DIR = objs

OBJ_BONUS_DIR = objs_bonus

CFLAGS = -Wall -Wextra -Werror -g3

all:	$(NAME)

bonus:	$(BONUS)

objs/%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $(<:%.c=objs/%.o)

objs_bonus/%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $(<:%.c=objs_bonus/%.o)

$(OBJ_DIR):
		mkdir $@

$(OBJ_BONUS_DIR):
		mkdir $@

$(NAME):	$(OBJ_DIR) $(OBJ)
		@echo "**********************"
		@echo "*     \033[1;33mCOMPILING\033[1;0m      *"
		@echo "**********************\n"
		$(CC) $(CFLAGS) -o $@ $(OBJ)
		@echo "**********************"
		@echo "*        \033[1;32mDONE\033[1;0m        *"
		@echo "**********************"

$(BONUS):	$(OBJ_BONUS_DIR) $(OBJ_BONUS)
		@echo "**********************"
		@echo "*  \033[1;33mCOMPILING BONUS\033[1;0m   *"
		@echo "**********************\n"
		$(CC) $(CFLAGS) -o $@ $(OBJ_BONUS)
		@echo "**********************"
		@echo "*        \033[1;32mDONE\033[1;0m        *"
		@echo "**********************"

clean:
		$(RM) $(OBJ_DIR) $(OBJ_BONUS_DIR)
		@echo "**********************"
		@echo "*    \033[1;32mCLEANED OBJS\033[1;0m    *"
		@echo "**********************"


fclean:	clean
		$(RM) $(NAME) $(BONUS)
		@echo "\n**********************"
		@echo "*   \033[1;32mCLEANED BINARY\033[1;0m   *"
		@echo "**********************"


re:		fclean	all
.PHONY:	all clean fclean re
.SILENT: all clean fclean $(OBJ) $(NAME) $(OBJ_DIR) $(BONUS) $(OBJ_BONUS) $(OBJ_BONUS_DIR)
