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
	t_proc *proc_tmp;

	chmp_tmp = skrr->chmp;
	proc_tmp = skrr->process;
	while (proc_tmp)
	{
		if (value == (int) proc_tmp->registry[0])
		{
			while (chmp_tmp)
			{
				if (chmp_tmp->id == proc_tmp->id)
				{
					chmp_tmp->cycles = proc_tmp->current_cycles;
					chmp_tmp->live += 1;
					return ;
				}
				chmp_tmp = chmp_tmp->next;
			}
		}
		proc_tmp = proc_tmp->next;
	}
}

int 	live_instr(t_skrr *skrr, t_proc *process)
{
	int	value;

	if ((process->current_cycles != 0) &&
		(process->current_cycles) % (g_tab[skrr->op].cycles) == 0)
	{
		if (g_tab[skrr->op].arg[0] != T_DIR)
		{
			ft_printf(RED"Error: %s args changed!"RESET, g_tab[skrr->op].name);
			exit(1);
		}
		process->tmp_pc += 2;
		value = dir_param(skrr, process, g_tab[1].dir_size);
		search_chmp(skrr, value);
		skrr->nbr_live += 1;
		if (g_tab[skrr->op].dir_size == 0)
			skrr->chmp->offset = DIR_SIZE + 2;
		else if (g_tab[skrr->op].dir_size == 1)
			skrr->chmp->offset = DIR_SIZE;
		process->pc += skrr->chmp->offset + 1;
	}
	return (1);
}
