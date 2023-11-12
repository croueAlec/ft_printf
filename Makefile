# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acroue <acroue@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 11:51:52 by acroue            #+#    #+#              #
#    Updated: 2023/11/12 18:12:50 by acroue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_printf.c

SRCS_BONUS =	

CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
NAME = libftprintf.a
RM = rm -f

all: ${NAME}

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	@${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	@${RM} ${NAME}

${NAME} : ${OBJS}
	@ar rcs ${NAME} ${OBJS}

bonus : ${OBJS} ${OBJS_BONUS}
	@ar rcs ${NAME} ${OBJS} ${OBJS_BONUS}

re : fclean all
