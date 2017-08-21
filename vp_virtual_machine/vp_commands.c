/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_virtual_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:12:55 by vpoltave          #+#    #+#             */
/*   Updated: 2017/08/08 15:42:25 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtualm.h"

void	prog_commands(t_skrr *skrr)
{
	char 			*line;
	unsigned int 	cmd[1];

	line = NULL;
	(get_next_line(skrr->fd, &line) < 0) ? exit(0) : 0;
	cmd[0] = (unsigned int)line[0];
	ft_printf("\nCommands! Player %d\n", skrr->j);
	(cmd[0] == 1) ? ft_printf("live") : 0;
	(cmd[0] == 2) ? ft_printf("ld") : 0;
	(cmd[0] == 3) ? ft_printf("st") : 0;
	(cmd[0] == 4) ? ft_printf("add") : 0;
	(cmd[0] == 5) ? ft_printf("sub") : 0;
	(cmd[0] == 6) ? ft_printf("and") : 0;
	(cmd[0] == 7) ? ft_printf("or") : 0;
	(cmd[0] == 8) ? ft_printf("xor") : 0;
	(cmd[0] == 9) ? zjmp(skrr, cmd[0] - 1) : 0;
	(cmd[0] == 10) ? ft_printf("ldi") : 0;
	(cmd[0] == 11) ? ft_printf("sti") : 0;
	(cmd[0] == 12) ? ft_printf("fork") : 0;
	(cmd[0] == 13) ? ft_printf("lld") : 0;
	(cmd[0] == 14) ? ft_printf("lldi") : 0;
	(cmd[0] == 15) ? ft_printf("lfork") : 0;
	(cmd[0] == 16) ? ft_printf("aff") : 0;
	ft_printf("\n");
}

int 	zjmp(t_skrr *skrr, int i)
{
	ft_printf("name: %s\n", op_tab[i].name);
	ft_printf("number_of_arg: %u\n", op_tab[i].numb_of_arg);
	ft_printf("arg: %x\n", op_tab[i].arg[0]);
	ft_printf("opcode: %u\n", op_tab[i].opcode);
	ft_printf("cycles: %u\n", op_tab[i].cycles);
	ft_printf("codage: %u\n", op_tab[i].codage);
	ft_printf("wtf: %u\n", op_tab[i].wtf);
	return (1);
}