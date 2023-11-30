# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izperez <izperez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 10:30:52 by izperez           #+#    #+#              #
#    Updated: 2023/11/30 13:11:03 by izperez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c \
					ft_strncmp.c ft_atoi.c ft_isalpha.c \
					ft_memcpy.c ft_strchr.c ft_strlcpy.c \
					ft_strlcat.c ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c \
					ft_memmove.c ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c \
					ft_substr.c ft_strjoin.c ft_atoi.c ft_strtrim.c ft_strchr.c\
					ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_free.c ft_gnl.c

SRC_B			=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
					ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
					ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
				
OBJS			= $(SRCS:.c=.o)
OBJ_B			= $(SRC_B:.c=.o)

NAME			= libft.a
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f
INCLUDE			= libft.h

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(OBJ_B)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(OBJ_B)
				ar rcs $(NAME) $(OBJS) $(OBJ_B)