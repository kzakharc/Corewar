/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:39:44 by yzakharc          #+#    #+#             */
/*   Updated: 2017/09/02 18:39:45 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void 	search_chmp(t_skrr *skrr, int value)
{
	t_chmp *chmp_tmp;

	chmp_tmp = skrr->chmp;
	while (chmp_tmp)
	{
		if (chmp_tmp->ac == value)
		{
			chmp_tmp->last_live = g_cycles;
			chmp_tmp->live_count += 1;
			return ;
		}
		chmp_tmp = chmp_tmp->next;
	}
}

int 	live_instr(t_skrr *skrr, t_proc *process)
{
	int	value;

	if ((process->waiting_cycles) == (g_tab[skrr->op].cycles))
	{
		process->tmp_pc = (process->tmp_pc + 1) % MEM_SIZE;
		value = dir_param(skrr, process, g_tab[1].dir_size);
		search_chmp(skrr, value);
		skrr->nbr_live += 1;
		process->live_count += 1;
		if (g_tab[skrr->op].dir_size == 0)
			skrr->chmp->offset = DIR_SIZE + 2;
		process->pc = ((process->pc + skrr->chmp->offset + 1) % MEM_SIZE);
		process->tmp_pc = process->pc;
		process->waiting_cycles = 0;
	}
	return (1);
}
