# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izperez <izperez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 08:55:05 by izperez           #+#    #+#              #
#    Updated: 2023/10/19 11:07:18 by izperez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR		= ar rcs
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f

NAME	= libftprintf.a

SRC	= ft_printf.c ft_cases.c
OBJ	= $(SRC:.c=.o)

%.o: %.c
		$(CC) $(CFLAGS) -c $(SRC)

all:	$(NAME)

$(NAME): $(OBJ)
		 $(AR) $(NAME) $(OBJ)

clean:	
	$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

