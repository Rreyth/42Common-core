# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 20:21:23 by tdhaussy          #+#    #+#              #
#    Updated: 2022/11/28 21:45:17 by tdhaussy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME =	push_swap

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

OBJ =	$(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g3

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) -o $@ $^

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:		fclean	all
.PHONY:	all clean fclean re
