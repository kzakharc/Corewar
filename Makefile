#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/16 12:41:59 by vpoltave          #+#    #+#              #
#    Updated: 2017/10/12 19:08:02 by yzakharc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	corewar
CC		=	gcc

LIBFT	=	./libft/libft.a
OBJ		:=	$(patsubst %.c,%.o,$(wildcard *.c))							\
			$(patsubst %.c,%.o,$(wildcard ./cor/instructions/*.c))		\
			$(patsubst %.c,%.o,$(wildcard ./cor/virtual_machine/*.c))	\
			$(patsubst %.c,%.o,$(wildcard ./cor/visualisation/*.c))		\

.PHONY: libft

all: $(NAME)

$(NAME): $(OBJ) libft
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT) -lncurses
	@echo "\033[32mcorewar compiled\033[0m"

libft:
	@make -C ./libft
	@echo "\033[32mlibft.a compiled\033[0m"

%.o : %.c
	@$(CC) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@make clean -C ./libft
	@echo "\033[32mclean completed\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C ./libft
	@echo "\033[32mfclean completed\033[0m"

re: fclean all