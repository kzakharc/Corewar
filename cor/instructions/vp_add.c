/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 16:49:35 by yzakharc          #+#    #+#             */
/*   Updated: 2017/10/24 13:03:37 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int		add_instr(t_skrr *skrr, t_proc *process)
{
	unsigned char	*q;
	int				address;
	int				reg;

	process->sop = 3;
	if (process->waiting_cycles != g_tab[skrr->op].cycles)
		return (0);
	process->sop = -1;
	process->waiting_cycles = 0;
	if (!(q = malloc(sizeof(unsigned char) * g_tab[skrr->op].numb_of_arg)))
		exit(0);
	if (!(same_start(q, skrr, process, g_tab[skrr->op].numb_of_arg)))
		return (0);
	if (!(address = determination_of_action(q, skrr, 1, process)) && (g_err))
		return (g_err = 0);
	process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
	if (!(reg = reg_param(skrr, process, 2)) && (g_err))
		return (g_err = 0);
	process->registry[reg] = (unsigned int)address;
	process->carry = (address == 0) ? 1 : 0;
	process->pc = (process->pc + skrr->chmp->offset + 2 + MEM_SIZE) % MEM_SIZE;
	process->tmp_pc = process->pc;
	return (1);
}
