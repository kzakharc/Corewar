/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 16:49:35 by yzakharc          #+#    #+#             */
/*   Updated: 2017/10/05 16:49:37 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int 	add_instr(t_skrr *skrr, t_proc *process)
{
	unsigned char	*q;
	int 			address;
	int 			reg;

	if ((process->waiting_cycles) == (g_tab[skrr->op].cycles))
	{
		if (!(q = malloc(sizeof(unsigned char) * g_tab[skrr->op].numb_of_arg)))
			exit(0);
		if (!(same_start(q, skrr, process, g_tab[skrr->op].numb_of_arg)))
			return (0);
		address = determination_of_action(q, skrr, 0, 1, process);
		process->tmp_pc += 1;
		if (!(reg = reg_param(skrr, process, 2)) && (g_err) && !(g_err = 0))
			return (0);
		process->registry[reg] = (unsigned int) address;
		address == 0 ? process->carry = 1 : 0;
		process->pc += skrr->chmp->offset + 2;
		process->tmp_pc = process->pc;
		process->waiting_cycles = 0;
	}
	return (1);
}