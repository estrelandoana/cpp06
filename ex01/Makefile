# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/12 22:37:33 by apaula-l          #+#    #+#              #
#    Updated: 2025/10/21 21:06:37 by apaula-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Serializer

SRC = main.cpp \
	Serializer.cpp

OBJS = $(SRC:.cpp=.o)

CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
