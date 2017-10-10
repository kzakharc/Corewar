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

int 	live_instr(t_skrr *skrr, t_proc *process)
{
	int	value;

	if (g_tab[skrr->op].arg[0] != T_DIR)
	{
		ft_printf(RED"Error: %s args changed!"RESET, g_tab[skrr->op].name);
		exit (1);
	}
	process->tmp_pc +=1;
	value = dir_param(skrr, process, g_tab[1].dir_size);
	if (value == (int)process->registry[0])
	{
		skrr->chmp->cycles = process->current_cycles;
		skrr->chmp->live += 1;
	}
	skrr->nbr_live += 1;
	return (1);
}
