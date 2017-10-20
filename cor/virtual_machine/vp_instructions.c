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

#include "../../corewar.h"

int 	entry_point(t_skrr *skrr, t_chmp *chmp)
{
	int	kastil;

	while (skrr->cycle_to_die > 0)
	{
		kastil = g_cycles == 1535 ? 1 : 0;
		change_process(skrr, chmp, &skrr->process);
		if (g_ctd + kastil == skrr->cycle_to_die)
		{
			kill_processes(&skrr->process, NULL, skrr);
			skrr->process == NULL ? winner(chmp, skrr, skrr->chmp->last_live, skrr->chmp->id) : 0;
		}
		if (g_cycles == skrr->flag_dump)
			dump_print(skrr);
		skrr->flag_v ? visualize(skrr, chmp) : 0;
		if ((g_ctd + kastil == skrr->cycle_to_die) && (skrr->nbr_live > 0))
			init_lives(skrr->process, skrr);
		g_cycles++;
		g_ctd++;
//		ft_printf("Cycle: %ld\n", g_cycles);

	}
	(!skrr->flag_v) ? winner(chmp, skrr, skrr->chmp->last_live, skrr->chmp->id) : 0;
	return (1);
}

int 	change_process(t_skrr *skrr, t_chmp *chmp, t_proc **process)
{
	t_proc *proc_tmp;
	t_chmp *chmp_tmp;

	proc_tmp = *process;
	chmp_tmp = chmp;
	(g_cycles == 0) ? process_first_positions(chmp_tmp, proc_tmp) : 0;
	while (proc_tmp)
	{
		which_instr(skrr, chmp_tmp, &proc_tmp);
		proc_tmp = proc_tmp->next;
	}
	return (1);
}

int 	process_first_positions(t_chmp *chmp_tmp, t_proc *proc_tmp)
{
	if (!chmp_tmp || !proc_tmp)
		exit (0);
	while (chmp_tmp || proc_tmp)
	{
		proc_tmp->pc = chmp_tmp->player_pos;
		proc_tmp = proc_tmp->next;
		chmp_tmp = chmp_tmp->next;
	}
	return (1);
}

int		which_instr(t_skrr *skrr, t_chmp *chmp, t_proc **process)
{
	skrr->op = -1;
	while (++skrr->op < 16)
	{
		if (skrr->map[(*process)->pc] == g_tab[skrr->op].opcode ||
				(*process)->sop != -1)
		{
			chmp->offset = 0;
			((*process)->sop != -1) ? skrr->op = (*process)->sop : 0;
			(skrr->op == 0) ? live_instr(skrr, *process) : 0;
			(skrr->op == 1) ? ld_instr(skrr, *process) : 0;
			(skrr->op == 2) ? st_instr(skrr, *process) : 0;
			(skrr->op == 3) ? add_instr(skrr, *process) : 0;
			(skrr->op == 4) ? sub_instr(skrr, *process) : 0;
			(skrr->op == 5) ? and_instr(skrr, *process) : 0;
			(skrr->op == 6) ? or_instr(skrr, *process) : 0;
			(skrr->op == 7) ? xor_instr(skrr, *process) : 0;
			(skrr->op == 8) ? zjmp_instr(skrr, *process) : 0;
			(skrr->op == 9) ? ldi_instr(skrr, *process) : 0;
			(skrr->op == 10) ? sti_instr(skrr, *process) : 0;
			(skrr->op == 11) ? fork_instr(skrr, process) : 0;
			(skrr->op == 12) ? lld_instr(skrr, *process) : 0;
			(skrr->op == 13) ? lldi_instr(skrr, *process) : 0;
			(skrr->op == 14) ? lfork_instr(skrr, process) : 0;
			(skrr->op == 15) ? aff_instr(skrr, *process) : 0;
			(*process)->waiting_cycles++;
			return (1);
		}
	}
	(*process)->pc = ((*process)->pc + 1 + MEM_SIZE) % MEM_SIZE;
	return (0);
}
