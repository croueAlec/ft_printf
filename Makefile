# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acroue <acroue@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 11:51:52 by acroue            #+#    #+#              #
#    Updated: 2023/11/15 11:42:23 by acroue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_printf.c \
		ft_put.c \
		ft_strlen_printf.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
RM = rm -f

all: ${NAME}

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

${NAME} : ${OBJS}
	@ar rcs ${NAME} ${OBJS}

re : fclean all
