# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbeaurai <cbeaurai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 10:50:05 by cbeaurai          #+#    #+#              #
#    Updated: 2022/03/31 12:38:40 by cbeaurai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:		all clean fclean re test v s m

SRCS		= srcs/main.cpp

VSRCS		= srcs/vmain.cpp

SSRCS		= srcs/smain.cpp

MSRCS		= srcs/mmain.cpp

OBJS		= $(SRCS:.cpp=.o)

VOBJS		= $(VSRCS:.cpp=.o)

SOBJS		= $(SSRCS:.cpp=.o)

MOBJS		= $(MSRCS:.cpp=.o)

VDEP		= vector.hpp headers/v_iterator.hpp headers/enable_if.hpp \
				headers/is_integral.hpp headers/equal.hpp headers/lexicographical_compare.hpp \
				headers/iterator_traits.hpp headers/reverse_iterator.hpp

SDEP		= stack.hpp vector.hpp

MDEP		= map.hpp headers/m_iterator.hpp headers/pair.hpp headers/RBT.hpp \
				headers/RBT_node.hpp headers/make_pair.hpp headers/reverse_iterator.hpp \
				headers/iterator_traits.hpp

CC			= c++

RM			= rm -rf

FLAGS		= -Wall -Werror -Wextra -g3
FLAGS		+= -fsanitize=address

NAME		= containers

VNAME		= myvec

SNAME		= mystack

MNAME		= mymap

all:		$(NAME)
			echo "Basic main test successfully compiled"

$(NAME):	$(OBJS) $(VDEP)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS)

test:		v s m
			diff log/myv_log log/stdv_log > log/vec_diff
			diff log/mys_log log/stds_log > log/stack_diff
			diff log/mym_log log/stdm_log > log/map_diff
			cat log/*diff*
			echo "Diff files available in ./log"

v:			
			$(CC) $(FLAGS) -D NS=ft -o $(VNAME) $(VSRCS)
			./$(VNAME) > log/myv_log
			$(CC) $(FLAGS) -D NS=std -o $(VNAME) $(VSRCS)
			./$(VNAME) > log/stdv_log
			echo "Vector log files available in ./log"	
			
s:			
			$(CC) $(FLAGS) -D NS=ft -o $(SNAME) $(SSRCS)
			./$(SNAME) > log/mys_log
			$(CC) $(FLAGS) -D NS=std -o $(SNAME) $(SSRCS)
			./$(SNAME) > log/stds_log
			echo "Stack log files available in ./log"
			
m:			
			$(CC) $(FLAGS) -D NS=ft -o $(MNAME) $(MSRCS)
			./$(MNAME) > log/mym_log
			$(CC) $(FLAGS) -D NS=std -o $(MNAME) $(MSRCS)
			./$(MNAME) > log/stdm_log
			echo "Map log files available in ./log"

.cpp.o:
			$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o)

clean_log:
			rm -rf log/*

clean:		
			$(RM) $(OBJS)
			$(RM) $(VOBJS)
			$(RM) $(SOBJS)
			$(RM) $(MOBJS)
			echo "Objects cleaned successfully"

fclean:		clean clean_log
			$(RM) $(NAME)
			$(RM) $(NAME).dSYM
			$(RM) $(VNAME)
			$(RM) $(VNAME).dSYM
			$(RM) $(SNAME)
			$(RM) $(SNAME).dSYM
			$(RM) $(MNAME)
			$(RM) $(NAME).dSYM
			echo "Everything cleaned successfully"

re:			fclean $(NAME)

.SILENT: