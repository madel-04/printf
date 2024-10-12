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

AR			= ar rcs
RM			= rm -f
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME		= libftprintf.a

SRC			= ft_printf_utils.c \
				ft_printf.c \
				ft_voider.c \

OBJ			= $(SRC:%.c=%.o)


INCLUDE		= ft_printf.h

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
		$(AR) $(NAME) $(OBJ)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
