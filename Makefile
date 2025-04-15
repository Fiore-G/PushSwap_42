# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: figarcia <figarcia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 21:33:18 by figarcia          #+#    #+#              #
#    Updated: 2025/02/11 20:39:44 by figarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = -I./mandatory  -I./libft

LIB = -L./libft -lft

SRCS = ../Push_Swap/mandatory/srcs/push_swap.c          \
       ../Push_Swap/mandatory/srcs/push_swap_utils.c    \
       ../Push_Swap/mandatory/srcs/sort_small.c         \
       ../Push_Swap/mandatory/srcs/sort_large.c         \
       ../Push_Swap/mandatory/srcs/sort_utils.c         \
       ../Push_Swap/mandatory/srcs/stack_operations.c   \
	   ../Push_Swap/mandatory/srcs/stack_rotate.c       \
       ../Push_Swap/mandatory/srcs/stack_utils.c        

OBJS = $(SRCS:.c=.o)

LIBPATH = libft/

all:	$(NAME)

$(NAME):	$(OBJS)
	make -C $(LIBPATH)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(LIB) -o $(NAME)

%.o:%.c Makefile
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	make clean -C $(LIBPATH)
	rm -f $(OBJS)

fclean: clean
	make clean -C $(LIBPATH)
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all