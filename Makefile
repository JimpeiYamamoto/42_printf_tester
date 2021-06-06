# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 23:50:22 by yjimpei           #+#    #+#              #
#    Updated: 2021/06/06 11:37:00 by yjimpei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printftester.a

all:	mytest.o ../libftprintf.a
		gcc -o $(NAME) mytest.o ../libftprintf.a
		./${NAME} 2 | cat -e > ft_printf.txt
		./${NAME} 1 | cat -e > printf.txt
		diff ft_printf.txt printf.txt

%.o:	%c.c
	gcc -all -Wall -Werror -Wextra -o $@ $< 

clean:
	rm -f mytest.o ft_printf.txt printf.txt

fclean: clean
	rm -f $(NAME)
