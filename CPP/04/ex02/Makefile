# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/21 18:24:04 by tdhaussy          #+#    #+#              #
#    Updated: 2023/06/15 15:00:47 by tdhaussy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

NAME = ex02

SRC =	main.cpp \
		Animal.cpp \
		Dog.cpp \
		Cat.cpp \
		WrongAnimal.cpp \
		WrongDog.cpp \
		WrongCat.cpp \
		Brain.cpp

OBJ =	$(SRC:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror -g3 -std=c++98

RM = rm -rf

all:	$(NAME)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $^ -o $@

$(NAME):	$(OBJ)
		@echo "**********************"
		@echo "*     \033[1;33mCOMPILING\033[1;0m      *"
		@echo "**********************\n"
		$(CC) $(CPPFLAGS) $^ -o $@
		@echo "**********************"
		@echo "*        \033[1;32mDONE\033[1;0m        *"
		@echo "**********************"

clean:
		$(RM) $(OBJ)
		@echo "**********************"
		@echo "*    \033[1;32mCLEANED OBJS\033[1;0m    *"
		@echo "**********************"

fclean:
		$(RM) $(OBJ) $(NAME)
		@echo "**********************"
		@echo "*     \033[1;32mCLEANED ALL\033[1;0m    *"
		@echo "**********************"

re:		fclean	all

.PHONY:	all clean fclean re
