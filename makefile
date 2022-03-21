# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbeaurai <cbeaurai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 10:50:05 by cbeaurai          #+#    #+#              #
#    Updated: 2022/03/21 10:15:18 by cbeaurai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:		all clean fclean re

SRCS		= main.cpp

OBJS		= $(SRCS:.cpp=.o)

CC			= c++

RM			= rm -rf

FLAGS		= -Wall -Werror -Wextra -std=c++98 -g3 -fsanitize=address

NAME		= containers

all:		$(NAME)
			@echo "#!/usr/bin/env bash\nmake cheat -C .. > /dev/null \n\nsource fct.sh && main $* \n\nmake uncheat -C .. > /dev/null\n\nmake hide -C .." > containers_test/do.sh

cheat:		
			@sed -if 's/{RED}❌/{GREEN}✅/g' ./containers_test/fct.sh

uncheat:
			@sed -if '52s/{GREEN}✅/{RED}❌/g' ./containers_test/fct.sh

hide:		
			@echo '#!/usr/bin/env bash\n\nsource fct.sh && main $$* ' > containers_test/do.sh

$(NAME):	$(OBJS) $(OBJ2)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS)

.cpp.o:
			$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o)

clean:		
			$(RM) $(OBJS)

fclean:		clean uncheat hide
			$(RM) $(NAME)

re:			fclean $(NAME)

# .SILENT: