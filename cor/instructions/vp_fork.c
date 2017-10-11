/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:37:59 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/02 18:38:00 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int 	fork_instr(t_skrr *skrr, t_proc *process)
{
	int address;

	if ((process->current_cycles != 0) &&
		(process->current_cycles) % (g_tab[skrr->op].cycles) == 0)
	{
		if (g_tab[skrr->op].arg[0] != T_DIR)
		{
			ft_printf(RED"Error: %s args changed!"RESET, g_tab[skrr->op].name);
			exit (1);
		}
		process->tmp_pc += 2;
		address = dir_param(skrr, process, g_tab[skrr->op].dir_size);
		address = (process->pc + (address % IDX_MOD));
		process->pc = address % MEM_SIZE;
		inheritance_proc(&process, process->pc);
//		ft_printf("fork\tcurrent_cycles: %d\npc: %d\n", process->current_cycles,
//				  process->pc);
	}
	return (1);
}