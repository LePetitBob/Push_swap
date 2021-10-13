# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 04:34:39 by vduriez           #+#    #+#              #
#    Updated: 2021/10/13 11:15:47 by vduriez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS =	ft_atol.c				\
		ft_best_push.c			\
		ft_op_push.c			\
		ft_op_rotate.c			\
		ft_op_rotate2.c			\
		ft_perfect_sort.c		\
		ft_smart_rotate.c		\
		ft_push_swap.c			\
		ft_sort_3to5.c			\
		ft_split.c				\
		ft_utils.c				\
		ft_utilscl.c			\
		ft_sortedbutwrongpos.c	\
		main.c

OBJ = $(SRCS:.c=.o)

all:
		$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY : clean fclean re