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

int 	fork_instr(t_skrr *skrr, t_proc **process)
{
	int address;
	int pc;

	if (((*process)->waiting_cycles) == (g_tab[skrr->op].cycles))
	{
		if (g_tab[skrr->op].arg[0] != T_DIR)
		{
			ft_printf(RED"Error: %s args changed!"RESET, g_tab[skrr->op].name);
			exit (1);
		}
		(*process)->tmp_pc += 1;
		address = dir_param(skrr, *process, g_tab[skrr->op].dir_size);
		address = ((*process)->pc + (address % IDX_MOD));
		pc = address % MEM_SIZE;
		(*process)->pc += 3;
		(*process)->tmp_pc = (*process)->pc;
		(*process)->waiting_cycles = 0;
		inheritance_proc(process, pc, skrr);
	}
	return (1);
}