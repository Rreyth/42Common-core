# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 20:21:23 by tdhaussy          #+#    #+#              #
#    Updated: 2022/10/09 22:59:50 by tdhaussy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME =	libftprintf.a

SRC =	ft_printf.c \
		ft_putargs.c

OBJ =	$(SRC:.c=.o)

CFlAGS = -Wall -Wextra -Werror

all:	$(NAME)

%.o:	%.c
		$(CC) $(CFLAGS) -c $^ -o $@

$(NAME):	$(OBJ)
		ar crs $@ $^

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:		fclean	all
.PHONY:	all clean fclean re
