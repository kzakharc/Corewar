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

void	winner(t_chmp *chmp, t_skrr *skrr)
{
	t_chmp	*chmp_tmp;
	long 	best_cycle;
	int 	best_player;

	chmp_tmp = chmp;
	best_cycle = chmp_tmp->last_live;
	best_player = chmp_tmp->ac;
	print_info(skrr, skrr->chmp);
	if (skrr->max_player == 1)
		ft_printf("Contestant %ld, " GRN"\"%s\", "RESET "has won !\n",
				  chmp_tmp->id * (-1), chmp_tmp->header.prog_name);
	else if (skrr->max_player > 1)
	{
		chmp_tmp = chmp_tmp->next;
		while (chmp_tmp)
		{
			if ((best_cycle <= chmp_tmp->last_live) && (best_player > chmp_tmp->ac))
			{
				best_cycle = chmp_tmp->last_live;
				best_player = chmp_tmp->ac;
			}
			chmp_tmp = chmp_tmp->next;
		}
		multipl_winners(skrr, best_cycle, best_player);
	}
	(skrr->flag_v == 1) ? endwin() : 0;
	exit(1);
}

void 	multipl_winners(t_skrr *skrr, long best_cycles, int best_player)
{
	t_chmp *chmp_tmp;

	chmp_tmp = skrr->chmp;
	while (chmp_tmp)
	{
		if ((best_cycles == chmp_tmp->last_live) && (best_player == chmp_tmp->ac))
			ft_printf("Contestant %ld, " GRN"\"%s\", "RESET "has won !\n",
					  chmp_tmp->id * (-1), chmp_tmp->header.prog_name);
		chmp_tmp = chmp_tmp->next;
	}
}

int 	init_lives(t_proc *process, t_skrr *skrr)
{
	t_chmp	*champ_tmp;

	champ_tmp = skrr->chmp;
	while (champ_tmp)
	{
		champ_tmp->live_count = 0;
		champ_tmp = champ_tmp->next;
	}

	if (skrr->nbr_live >= NBR_LIVE && (skrr->max_checks = MAX_CHECKS))
		skrr->cycle_to_die -= CYCLE_DELTA;
	else
	{
		skrr->max_checks--;
		if (skrr->max_checks == 0 && (skrr->max_checks = MAX_CHECKS))
			skrr->cycle_to_die -= CYCLE_DELTA;
	}
	g_ctd = 0;
	skrr->nbr_live = 0;
	return (1);
}

