# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbeaurai <cbeaurai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 10:50:05 by cbeaurai          #+#    #+#              #
#    Updated: 2022/03/26 18:43:32 by cbeaurai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:		all clean fclean re

SRCS		= main.cpp

OBJS		= $(SRCS:.cpp=.o)

DEP_H		= vector.hpp v_iterator.hpp enable_if.hpp is_integral.hpp 

CC			= c++

RM			= rm -rf

FLAGS		= -Wall -Werror -Wextra -std=c++98 -g3 -fsanitize=address

NAME		= containers

all:		$(NAME)

$(NAME):	$(OBJS) $(OBJ2) $(DEP_H)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS)

.cpp.o:
			$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o)

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

# .SILENT: