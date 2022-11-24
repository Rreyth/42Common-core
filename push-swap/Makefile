# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 20:21:23 by tdhaussy          #+#    #+#              #
#    Updated: 2022/11/24 16:34:29 by tdhaussy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME =	push_swap

SRC =	

OBJ =	$(SRC:.c=.o)

CFlAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) -o $@ $^

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:		fclean	all
.PHONY:	all clean fclean re
