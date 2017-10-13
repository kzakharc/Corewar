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

void	winner(t_proc *process, t_chmp *chmp, t_skrr *skrr)
{
	t_chmp	*chmp_tmp;
	long 	*best_cycles;
	int 	i;

	i = 0;
	chmp_tmp = chmp;
	if (!(best_cycles = malloc(sizeof(long) * (chmp->id * (-1)))))
		exit (0);
	print_info(skrr, skrr->chmp);
	if (chmp_tmp->id == -1)
		ft_printf("Contestant %ld, " GRN"\"%s\", "RESET "has won !\n",
				  chmp_tmp->id * (-1), chmp_tmp->header.prog_name);
	else if (chmp_tmp->id != -1)
	{
		while (chmp_tmp)
		{
			best_cycles[i] = chmp_tmp->last_live;
			chmp_tmp = chmp_tmp->next;
			i++;
		}
	multipl_winners(process, skrr, best_cycles, i);
	}
	if (skrr->flag_v == 1)
		endwin();
	exit(1);
}

int 	multipl_winners(t_proc *process, t_skrr *skrr, long *best_cycles, int i)
{
	int j;
	long best;

	j = 0;
	while (i != 0)
	{
		best = *best_cycles;
		if (best < *best_cycles)
		{
			best = *best_cycles;
		}
		i--;
		best_cycles++;
	}

//	ft_printf("Contestant %ld, " GRN"\"%s\", "RESET "has won !\n",
// chmp_tmp->ac, chmp_tmp->header.prog_name);
	return (1);
}

int 	init_lives(t_proc *process, t_skrr *skrr)
{
	t_proc *proc_tmp;

	proc_tmp = process;
	while (proc_tmp)
	{
		(proc_tmp->live_count > 0) ? proc_tmp->live_count = 0 : 0;
		proc_tmp = proc_tmp->next;
	}
	if (skrr->nbr_live >= NBR_LIVE)
	{
		skrr->cycle_to_die -= CYCLE_DELTA;
		skrr->max_checks = MAX_CHECKS;
	}
	else
	{
		skrr->max_checks--;
		if (!skrr->max_checks ? skrr->max_checks = MAX_CHECKS : 0)
			skrr->cycle_to_die -= CYCLE_DELTA;
	}
	skrr->nbr_live = 0;
	g_ctd = 0;
	return (1);
}