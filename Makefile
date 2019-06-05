# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/04 18:42:05 by mirivera          #+#    #+#              #
#    Updated: 2019/06/04 20:22:38 by mirivera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FUNCTION = ft_printf

HEADER = ./ft_printf.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = $(FUNCTION).c

OBJS = $(FUNCTION).o

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRCS) -I $(HEADER)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJS)
	#@make -C libft clean

fclean:	clean
	@rm -rf $(NAME)
	@rm -rf $(FUNCTION)
	#@make -C libft fclean

re:	fclean all

debug:
	$(CC) $(CFLAGS) $(SRCS) -o $(FUNCTION)