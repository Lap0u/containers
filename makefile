# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbeaurai <cbeaurai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 10:50:05 by cbeaurai          #+#    #+#              #
#    Updated: 2022/03/30 21:10:00 by cbeaurai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:		all clean fclean re

SRCS		= main.cpp

OBJS		= $(SRCS:.cpp=.o)

DEP_H		= vector.hpp headers/v_iterator.hpp headers/enable_if.hpp \
				headers/is_integral.hpp headers/equal.hpp headers/lexicographical_compare.hpp \
				headers/iterator_traits.hpp headers/reverse_iterator.hpp

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