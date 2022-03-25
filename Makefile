# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 14:37:26 by gscarama          #+#    #+#              #
#    Updated: 2022/03/25 12:49:11 by gscarama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SOURCE	= main.c \
			checks.c \
			push_swap.c \
			utils.c \

CFLAGS	= -Wall -Wextra -Werror
GCC	= gcc
RM	= rm -rf
PATH_SRC	= srcs
PATH_OBJ	= objs

SRCS	= $(addprefix $(PATH_SRC)/,$(SOURCE))
OBJS	= $(addprefix $(PATH_OBJ)/,$(SOURCE:.c=.o))

$(PATH_OBJ)/%.o : $(PATH_SRC)/%.c
			${GCC} ${CFLAGS} -c $< -o ${<:$(PATH_SRC)/%.c=$(PATH_OBJ)/%.o}

$(NAME):	${OBJS}
	make -C ./ft_printf
	cp ft_printf/libftprintf.a .
	mv libftprintf.a ${NAME}
	$(GCC) $(CFLAGS) ${OBJS} ${NAME} -o $(NAME)

all:	$(NAME)

norm:	norminette

clean:
	${RM} ${OBJ} ${OBJ_b}
	make -C ./ft_printf clean

fclean:	clean
	${RM} ${NAME}
	make -C ./ft_printf fclean

re:	fclean all

.PHONY:	.o all norm clean fclean re
