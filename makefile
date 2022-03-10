# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbeaurai <cbeaurai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 10:50:05 by cbeaurai          #+#    #+#              #
#    Updated: 2022/03/10 11:40:10 by cbeaurai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.cpp

OBJS		= $(SRCS:.cpp=.o)

CC			= c++

RM			= rm -rf

FLAGS		= -Wall -Werror -Wextra -std=c++98 -g -fsanitize=address

NAME		= containers

all:		$(NAME)

$(NAME):	$(OBJS) $(OBJ2)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS)

.cpp.o:
			$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o)

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re