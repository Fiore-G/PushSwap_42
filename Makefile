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

LIBPATH = ./libft

LIBFT = $(LIBPATH)/libft.a

LIB = -L$(LIBPATH) -lft

SRCS = ./mandatory/srcs/push_swap.c          \
       ./mandatory/srcs/push_swap_utils.c    \
       ./mandatory/srcs/sort_small.c         \
       ./mandatory/srcs/sort_large.c         \
       ./mandatory/srcs/sort_utils.c         \
       ./mandatory/srcs/stack_operations.c   \
	   ./mandatory/srcs/stack_rotate.c       \
       ./mandatory/srcs/stack_utils.c		\
	   ./mandatory/srcs/errors.c

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)	libft
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(LIB) -o $(NAME)

%.o:%.c Makefile ./mandatory/push_swap.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

libft:
	$(MAKE) -C $(LIBPATH)

clean:
	$(MAKE) clean -C $(LIBPATH)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBPATH)
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all libft