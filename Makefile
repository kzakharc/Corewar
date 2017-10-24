#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/16 12:41:59 by vpoltave          #+#    #+#              #
#    Updated: 2017/10/23 15:12:21 by vpoltave         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	corewar
CC		=	gcc

LIBFT	=	./libft/libft.a
OBJ		:=	$(patsubst %.c,%.o,$(wildcard *.c))							\
			$(patsubst %.c,%.o,$(wildcard ./cor/virtual_machine/*.c))	\
			$(patsubst %.c,%.o,$(wildcard ./cor/visualisation/*.c))		\
			$(patsubst %.c,%.o,$(wildcard ./cor/instructions/*.c))		\

.PHONY: libft

all: $(NAME)

$(NAME): $(OBJ) libft
		$(CC) -o $(NAME) $(OBJ) $(LIBFT) -lncurses

libft:
	make -C ./libft

%.o : %.c
	$(CC) -o $@ -c $<

clean:
	rm -rf $(OBJ)
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft

re: fclean all