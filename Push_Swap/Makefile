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

INCLUDE = -I.

LIB = -L./libft -lft

HEADER = mandatory/push_swap.h

SRCS = PushSwap/mandatory/srcs/push_swap.c          \
       PushSwap/mandatory/srcs/push_swap_utils.c    \
       PushSwap/mandatory/srcs/sort_small.c         \
       PushSwap/mandatory/srcs/sort_large.c         \
       PushSwap/mandatory/srcs/sort_utils.c         \
       PushSwap/mandatory/srcs/stack_operations.c   \
       PushSwap/mandatory/srcs/stack_utils.c        \
       PushSwap/mandatory/srcs/optimization.c

OBJS = $(SRCS:.c=.o)

LIBPATH = libft/

all:	$(NAME)

$(NAME):	$(OBJS)
	make -C $(LIBPATH)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(LIBFT) -o $(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	make clean -C $(LIBPATH)
	rm -f $(OBJS)

fclean: clean
	make clean -C $(LIBPATH)
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
