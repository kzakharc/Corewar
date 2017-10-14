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
	while (skrr->cycle_to_die > 0)
	{
		change_process(skrr, chmp, &skrr->process);
//		(g_ctd == skrr->cycle_to_die) ? kill_processes(skrr->process, skrr) : 0;
		skrr->flag_v ? visualize(skrr, chmp) : 0;
		if ((g_ctd == skrr->cycle_to_die) && (skrr->nbr_live > 0))
			init_lives(skrr->process, skrr);
//		else if ((g_ctd == skrr->cycle_to_die) && (skrr->nbr_live == 0))
//			(!skrr->flag_v) ? winner(skrr->process, chmp, skrr) : 0;
		g_cycles++;
		g_ctd++;
//		ft_printf("Cycle: %ld\n", g_cycles);
	}
	(!skrr->flag_v) ? winner(skrr->process, chmp, skrr) : 0;
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
		(proc_tmp->alive) ? which_instr(skrr, chmp_tmp, &proc_tmp) : 0;
		(proc_tmp->alive) ? proc_tmp->waiting_cycles++ : 0;
		proc_tmp = proc_tmp->next;
	}
	return (1);
}

int 	process_first_positions(t_chmp *chmp_tmp, t_proc *proc_tmp)
{
	if (!chmp_tmp || !proc_tmp)
		return (0);
	while (chmp_tmp || proc_tmp)
	{

		proc_tmp->pc = chmp_tmp->player_pos;
		proc_tmp = proc_tmp->next;
		chmp_tmp = chmp_tmp->next;
	}
	return (1);
}

int 	kill_processes(t_proc *process, t_skrr *skrr)
{
	t_proc 	*proc_tmp;
	int 	alive;

	proc_tmp = process;
	alive = 0;
	while (proc_tmp)
	{
		if (proc_tmp->live_count == 0)
		{
			proc_tmp->alive = 0;
			skrr->process_count -= 1;
		}
		(proc_tmp->live_count > 0) ? alive = 1 : 0;
		proc_tmp = proc_tmp->next;
	}
	if (alive == 1)
		return (1);
	winner(skrr->process, skrr->chmp, skrr);
	return (0);
}

int		which_instr(t_skrr *skrr, t_chmp *chmp, t_proc **process)
{
	skrr->op = -1;
	while (++skrr->op < 16)
	{
		if (skrr->map[(*process)->pc] == g_tab[skrr->op].opcode)
		{
			chmp->offset = 0;
			((skrr->op) == 0) ? live_instr(skrr, *process) : 0;
			((skrr->op) == 1) ? ld_instr(skrr, *process) : 0;
			((skrr->op) == 2) ? st_instr(skrr, *process) : 0;
			((skrr->op) == 3) ? add_instr(skrr, *process) : 0;
			((skrr->op) == 4) ? sub_instr(skrr, *process) : 0;
			((skrr->op) == 5) ? and_instr(skrr, *process) : 0;
			((skrr->op) == 6) ? or_instr(skrr, *process) : 0;
			((skrr->op) == 7) ? xor_instr(skrr, *process) : 0;
			((skrr->op) == 8) ? zjmp_instr(skrr, *process) : 0;
			((skrr->op) == 9) ? ldi_instr(skrr, *process) : 0;
			((skrr->op) == 10) ? sti_instr(skrr, *process) : 0;
			((skrr->op) == 11) ? fork_instr(skrr, process) : 0;
			((skrr->op) == 12) ? lld_instr(skrr, *process) : 0;
			((skrr->op) == 13) ? lldi_instr(skrr, *process) : 0;
			((skrr->op) == 14) ? lfork_instr(skrr, process) : 0;
			((skrr->op) == 15) ? aff_instr(skrr, *process) : 0;
			return (1);
		}
	}
	if (skrr->map[(*process)->pc] == 0)
		(*process)->pc = ((*process)->pc + 1) % MEM_SIZE;
	return (0);
}
