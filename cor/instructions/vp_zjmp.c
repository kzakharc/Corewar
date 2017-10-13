/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:37:20 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/02 18:37:22 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int 	zjmp_instr(t_skrr *skrr, t_proc *process)
{
	int address;

	if ((process->carry) && ((process->current_cycles != 0) &&
		(process->current_cycles) % (g_tab[skrr->op].cycles) == 0))
	{
		if (g_tab[skrr->op].arg[0] != T_DIR)
		{
			ft_printf(RED"Error: %s arg changed!"RESET, g_tab[skrr->op].name);
			exit (1);
		}
		process->tmp_pc += 1;
		address = dir_param(skrr, process, g_tab[skrr->op].dir_size);
		address = (process->pc + (address % IDX_MOD));
		process->pc = address % MEM_SIZE;
		process->tmp_pc = process->pc;
//		ft_printf("zjmp\tcurrent_cycles: %d\npc: %d\n", process->current_cycles,
//				  process->pc);
	}
	else if (!(process->carry) && ((process->current_cycles != 0) &&
			(process->current_cycles) % (g_tab[skrr->op].cycles) == 0))
	{
		ft_printf("%s failed to jump!\n", g_tab[skrr->op].name);
		process->pc += DIR_SIZE + 1;
	}
	return (1);
}