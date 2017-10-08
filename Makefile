#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/16 12:41:59 by vpoltave          #+#    #+#              #
#    Updated: 2017/09/01 10:03:06 by vpoltave         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = corewar
CC = gcc

LIBFT = ./libft/libft.a
OBJ =   ./cor/virtual_machine/vp_virtual_main.o \
        ./cor/virtual_machine/vp_err_u.o \
        ./cor/virtual_machine/vp_basic.o \
        ./cor/virtual_machine/vp_commands.o \
        ./cor/virtual_machine/vp_instructions.o \
        ./cor/virtual_machine/new_chmp.o \
        ./cor/virtual_machine/additional_func.o \
        ./cor/virtual_machine/vp_output_err.o \
        ./cor/virtual_machine/reg_dir_ind.o \
        ./cor/virtual_machine/vp_load_from_into.o \
        ./cor/virtual_machine/flag_in_arg.o \
        ./cor/instructions/vp_live.o \
        ./cor/instructions/vp_add.o \
        ./cor/instructions/vp_aff.o \
        ./cor/instructions/vp_and.o \
        ./cor/instructions/vp_fork.o \
        ./cor/instructions/vp_ld.o \
        ./cor/instructions/vp_ldi.o \
        ./cor/instructions/vp_lfork.o \
        ./cor/instructions/vp_lld.o \
        ./cor/instructions/vp_lldi.o \
        ./cor/instructions/vp_or.o \
        ./cor/instructions/vp_st.o \
        ./cor/instructions/vp_sti.o \
        ./cor/instructions/vp_sub.o \
        ./cor/instructions/vp_xor.o \
        ./cor/instructions/vp_zjmp.o \
        ./op.o                       \
        ./cor/visualisation/ds_visualize.o \

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
