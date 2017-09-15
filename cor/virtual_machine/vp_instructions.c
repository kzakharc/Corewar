/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 17:31:42 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/10 17:31:43 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtualm.h"

int 	entry_point(t_skrr *skrr, t_chmp *chmp)
{
	while ((skrr->cycle_to_die > 0) || !(skrr->max_checks))
	{
		change_player(skrr, chmp);
		if ( (g_ctd == skrr->cycle_to_die) && (skrr->nbr_live >= NBR_LIVE))
		{
			skrr->cycle_to_die -= CYCLE_DELTA;
			skrr->nbr_live = 0;
			g_ctd = 0;
		}
		else if ((g_ctd == skrr->cycle_to_die) && (skrr->nbr_live))
		{
//			skrr->nbr_live = 0;
			skrr->max_checks--;
			g_ctd = 0;
		}
		else if ((g_ctd == skrr->cycle_to_die) && !(skrr->nbr_live))
		{
			skrr->process->alive = 0;
			//Process has won! and finish program
		}
		g_cycles++;
		g_ctd++;
	}
	return (1);
}

int 	change_player(t_skrr *skrr, t_chmp *chmp)
{


	return (1);
}

int		which_instr(t_skrr *skrr, t_chmp *chmp)
{
	int current_cycle;

	skrr->op = -1;
	current_cycle = g_ctd;
	while (++skrr->op < 16)
		if (skrr->map[skrr->process->pc] == g_tab[skrr->op].opcode)
		{
			while (g_ctd + current_cycle != g_tab[skrr->op].cycles + g_ctd)
				current_cycle++;
			((skrr->op) == 0) ? live_instr(skrr, chmp, skrr->op) : 0;
			((skrr->op) == 1) ? ld_instr(skrr, chmp, skrr->op) : 0;
			((skrr->op) == 2) ? st_instr(skrr, chmp, skrr->op) : 0;
			((skrr->op) == 3) ? add_instr(skrr) : 0;
			((skrr->op) == 4) ? sub_instr(skrr) : 0;
			((skrr->op) == 5) ? and_instr(skrr) : 0;
			((skrr->op) == 6) ? or_instr(skrr) : 0;
			((skrr->op) == 7) ? xor_instr(skrr) : 0;
			((skrr->op) == 8) ? zjmp_instr(skrr, chmp, skrr->op) : 0;
			((skrr->op) == 9) ? ldi_instr(skrr, chmp, skrr->op) : 0;
			((skrr->op) == 10) ? sti_instr(skrr, chmp, skrr->op) : 0;
			((skrr->op) == 11) ? fork_instr(skrr, chmp, skrr->op) : 0;
			((skrr->op) == 12) ? lld_instr(skrr, chmp, skrr->op) : 0;
			((skrr->op) == 13) ? lldi_instr(skrr, chmp, skrr->op) : 0;
			((skrr->op) == 14) ? lfork_instr(skrr, chmp, skrr->op) : 0;
			((skrr->op) == 15) ? aff_instr(skrr, chmp) : 0;
			return (current_cycle);
		}
	return (1);
}
