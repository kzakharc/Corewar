/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:39:09 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/02 18:39:10 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int 	lldi_instr(t_skrr *skrr,t_proc *process)
{
	unsigned char	*q;
	int 			address;

	process->sop = 13;
	if (process->waiting_cycles == g_tab[skrr->op].cycles)
	{
		process->sop = -1;
		process->waiting_cycles = 0;
		if (!(q = malloc(sizeof(unsigned char) * g_tab[skrr->op].numb_of_arg)))
			exit(0);
		if (!(same_start(q, skrr, process, g_tab[skrr->op].numb_of_arg)))
			return (0);
		if (!(address = get_address(q, skrr, 1, 0)) && (g_err) && !(g_err = 0))
			return (0);
		if (!(load_into(address, process, skrr, 2)) && (g_err) && !(g_err = 0))
				return (0);
		process->pc = ((process->pc + skrr->chmp->offset + 2 + MEM_SIZE) % MEM_SIZE);
		process->tmp_pc = process->pc;
		free(q);
	}
	return (1);
}