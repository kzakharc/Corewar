/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:40:14 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/02 18:40:14 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

// TODO need to be check!

int 	st_instr(t_skrr *skrr, t_proc *process)
{
	unsigned char	*q;
	int 			address;

	process->sop = 2;
	if (process->waiting_cycles == g_tab[skrr->op].cycles)
	{
		process->sop = -1;
		process->waiting_cycles = 0;
		if (!(q = malloc(sizeof(unsigned char) * g_tab[skrr->op].numb_of_arg)))
			exit(0);
		if (!(same_start(q, skrr, process, g_tab[skrr->op].numb_of_arg)))
			return (0);
		if (!(from_reg(q, process, skrr, 0)) && (g_err) && !(g_err = 0))
			return (0);
		if (!(address = simple_address(q, skrr, process, 1)) && (g_err) &&
				!(g_err = 0))
			return (0);
		if (q[1] == T_IND)
			load_into(address, process, skrr, 1);
		else if (q[1] == T_REG)
			(process->registry[address] = skrr->chmp->reg_value);
		process->pc = ((process->pc + skrr->chmp->offset + 2 + MEM_SIZE) % MEM_SIZE);
		process->tmp_pc = process->pc;
	}
	return (1);
}
