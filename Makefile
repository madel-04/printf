# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 12:33:15 by marvin            #+#    #+#              #
#    Updated: 2024/09/26 12:33:15 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB			= ar rcs
RM			= rm -f
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME		= libftprintf.a

SRC			= printf_utils.c \

OBJ			= $(SRC:%.c=%.o)


INCLUDE		= libftprintf.h

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
		$(LIB) $(NAME) $(OBJ)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
