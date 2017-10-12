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
	while ((skrr->cycle_to_die > 0) || !(skrr->max_checks))
	{
		change_process(skrr, chmp, skrr->process);
		(g_ctd == skrr->cycle_to_die) ? kill_processes(skrr->process) : 0;
//		skrr->flag_v ? visualize(skrr, chmp) : 0;
		if ( (g_ctd == skrr->cycle_to_die) && (skrr->nbr_live >= NBR_LIVE))
		{
			skrr->cycle_to_die -= CYCLE_DELTA;
			skrr->nbr_live = 0;
			g_ctd = 0;
		}
		else if ((g_ctd == skrr->cycle_to_die) && (skrr->nbr_live))
		{
			skrr->nbr_live = 0;
			skrr->max_checks--;
			if (!skrr->max_checks ? skrr->max_checks = 10 : 0)
				skrr->cycle_to_die -= CYCLE_DELTA;
			g_ctd = 0;
		}
		else if ((g_ctd == skrr->cycle_to_die) && !(skrr->nbr_live))
			(!skrr->flag_v) ? winner(skrr->process, chmp, skrr) : 0;
		g_cycles++;
		g_ctd++;
	}
	return (1);
}

int 	change_process(t_skrr *skrr, t_chmp *chmp, t_proc *process)
{
	t_proc *proc_tmp;
	t_chmp *chmp_tmp;

	proc_tmp = process;
	chmp_tmp = chmp;
	!proc_tmp->current_cycles ? process_first_positions(chmp_tmp, proc_tmp) : 0;
	while (proc_tmp)
	{
		proc_tmp->current_cycles = (long)g_cycles;
		(proc_tmp->alive) ? which_instr(skrr, chmp_tmp, proc_tmp) : 0;
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

void	winner(t_proc *process, t_chmp *chmp, t_skrr *skrr)
{
	t_chmp	*chmp_tmp;
	long 	best_cycles[chmp->ac];
	int 	champ[chmp->ac];
	int 	i;

	i = 0;
	chmp_tmp = chmp;
	print_info(skrr, skrr->chmp);
	if (chmp_tmp->ac == 1)
		ft_printf("Contestant %ld, " GRN"\"%s\", "RESET "has won !\n", chmp_tmp->ac, chmp_tmp->header.prog_name);
	else if (chmp_tmp->ac != 1)
	{
		while (chmp_tmp)
		{
			best_cycles[i] = chmp_tmp->last_live;
			champ[i] = chmp_tmp->ac;
			i++;
			chmp_tmp = chmp_tmp->next;

		}
	}
	exit(1);
}

int 	kill_processes(t_proc *process)
{
	t_proc *proc_tmp;

	proc_tmp = process;
	while (proc_tmp)
	{
		(!proc_tmp->live_count) ? proc_tmp->alive = 0 : 0;
		proc_tmp = proc_tmp->next;
	}
	return (1);
}

int		which_instr(t_skrr *skrr, t_chmp *chmp, t_proc *process)
{
	//dump_print(skrr);
	skrr->op = -1;
	while (++skrr->op < 16)
		if (skrr->map[process->pc] == g_tab[skrr->op].opcode)
		{
			chmp->offset = 0;
			((skrr->op) == 0) ? live_instr(skrr, process) : 0;
			((skrr->op) == 1) ? ld_instr(skrr, process) : 0;
			((skrr->op) == 2) ? st_instr(skrr, process) : 0;
			((skrr->op) == 3) ? add_instr(skrr, process) : 0;
			((skrr->op) == 4) ? sub_instr(skrr, process) : 0;
			((skrr->op) == 5) ? and_instr(skrr, process) : 0;
			((skrr->op) == 6) ? or_instr(skrr, process) : 0;
			((skrr->op) == 7) ? xor_instr(skrr, process) : 0;
			((skrr->op) == 8) ? zjmp_instr(skrr, process) : 0;
			((skrr->op) == 9) ? ldi_instr(skrr, process) : 0;
			((skrr->op) == 10) ? sti_instr(skrr, process) : 0;
			((skrr->op) == 11) ? fork_instr(skrr, process) : 0;
			((skrr->op) == 12) ? lld_instr(skrr, process) : 0;
			((skrr->op) == 13) ? lldi_instr(skrr, process) : 0;
			((skrr->op) == 14) ? lfork_instr(skrr, process) : 0;
			((skrr->op) == 15) ? aff_instr(skrr, process) : 0;
			return (1);
		}
	return (0);
}
