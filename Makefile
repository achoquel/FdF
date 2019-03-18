# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achoquel <achoquel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 12:01:01 by achoquel          #+#    #+#              #
#    Updated: 2019/01/23 10:05:55 by achoquel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY	:	all clean fclean re

NAME	=	fdf

SRCS	=	srcs/utils/color_themes.c		\
			srcs/utils/graphic_utils.c		\
			srcs/utils/itoaf.c				\
			srcs/main/drawer.c				\
			srcs/main/main.c				\
			srcs/main/parser.c				\
			srcs/events/key_event_handler.c	\
			srcs/events/position.c			\
			srcs/events/misc.c				\
			srcs/windows/help_setup.c		\
			srcs/windows/status_setup.c		\
			srcs/windows/wait_setup.c

OBJS	= 	$(SRCS:.c=.o)

CC		=	@gcc

CFLAGS	+=	-Wall -Wextra -Werror

LIB		=	-L./srcs/libft/ -lft -L/usr/local/lib/ -lmlx -lm

FW		= 	-framework OpenGL -framework AppKit

RM		=	@/bin/rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			@make  -C srcs/libft/
			$(CC) -o $(NAME) $(OBJS) $(LIB) $(FW)
			@echo "\033[32m[✓] fdf compiled !\033[0m"

clean	:
			@make -C srcs/libft/ clean
			$(RM) $(OBJS)
			@echo "\033[32m[✓] objects cleaned !\033[0m"

fclean	:	clean
			$(RM) $(NAME)
			$(RM) srcs/libft/libft.a
			@echo "\033[32m[✓] objects, libraries and binaries cleaned !\033[0m"

re		:	fclean all
