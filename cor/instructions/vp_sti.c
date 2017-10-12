/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:37:47 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/02 18:37:48 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int 			sti_instr(t_skrr *skrr, t_proc *process)
{
	unsigned char	*q;
	int 			address;

	if ((process->current_cycles != 0) &&
			(process->current_cycles) % (g_tab[skrr->op].cycles) == 0)
	{
		if (!(q = malloc(sizeof(unsigned char) * g_tab[skrr->op].numb_of_arg)))
			exit(0);
		if (!(same_start(q, skrr, process, g_tab[skrr->op].numb_of_arg)))
			return (0);
		if ((!from_reg(q, process, skrr, 0) && (g_err) && !(g_err = 0)))
		{
			process->pc += skrr->chmp->offset + 2;
			return (1);
		}
		address = get_address(q, skrr, process, 0, 1);
		load_into(address, process, skrr, 1);
		process->pc += skrr->chmp->offset + 2;
		process->tmp_pc = process->pc;
//		ft_printf("sti\tcurrent_cycles: %d\npc: %d\ntmp_pc: %d\n", process->current_cycles,
//				  process->pc, process->tmp_pc);
	}
	return (1);
}
