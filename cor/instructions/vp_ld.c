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

	if ((process->current_cycles != 0) &&
			(process->current_cycles) % (g_tab[skrr->op].cycles) == 0)
	{
		address = 0;
		if (!(q = malloc(sizeof(unsigned char) * g_tab[skrr->op].numb_of_arg)))
			exit(0);
		if (!(same_start(q, skrr, process, g_tab[skrr->op].numb_of_arg)))
			return (0);
		if ((q[0] == T_IND) && (process->tmp_pc += 1))
			address = ind_param(skrr, process, 0, 4);
		else if ((q[0] == T_DIR) && (process->tmp_pc += 1) &&
				(skrr->chmp->offset += 2))
			address = dir_param(skrr, process, g_tab[skrr->op].dir_size);
		if ((q[1] == T_REG) && (process->tmp_pc += 1))
		{
			if (!(reg = reg_param(skrr, process, 2)) && (g_err) && !(g_err = 0))
				return (0);
			process->registry[reg] = (unsigned int)address;
		}
		(!address) ? process->carry = 1 : 0;
		process->pc += skrr->chmp->offset + 2;
//		ft_printf("ld\tcurrent_cycles: %d\npc: %d\n", process->current_cycles,
//				  process->pc);
	}
	return (1);
}
