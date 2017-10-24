/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:39:57 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/02 18:39:57 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int 	ld_instr(t_skrr *skrr, t_proc *process)
{
	unsigned char 	*q;
	int 			address;
	int 			reg;

	process->sop = 1;
	if (process->waiting_cycles == g_tab[skrr->op].cycles)
	{
		process->sop = -1;
		address = 0;
		process->waiting_cycles = 0;
		if (!(q = malloc(sizeof(unsigned char) * g_tab[skrr->op].numb_of_arg)))
			exit(0);
		if (!(same_start(q, skrr, process, g_tab[skrr->op].numb_of_arg)))
			return (0);
		process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
		if (q[0] == T_IND)
			address = ind_param(skrr, process, 4);
		else if (q[0] == T_DIR)
			address = dir_param(skrr, process, g_tab[skrr->op].dir_size);
		process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
		if (q[1] == T_REG)
		{
			if (!(reg = reg_param(skrr, process, 2)) && (g_err) && !(g_err = 0))
				return (0);
			process->registry[reg] = (unsigned int)address;
		}
		process->carry = (address == 0) ? 1 : 0;
		process->pc = ((process->pc + skrr->chmp->offset + 2 + MEM_SIZE) % MEM_SIZE);
		process->tmp_pc = process->pc;
		free(q);
	}
	return (1);
}
