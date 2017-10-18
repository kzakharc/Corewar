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

static char 	*name_winner(t_chmp *chmp, int id)
{
	t_chmp *tmp;

	tmp = chmp;
	while (tmp)
	{
		if (tmp->id == id)
			return (ft_strdup(tmp->header.prog_name));
		tmp = tmp->next;
	}
	return (0);
}

void	winner(t_chmp *chmp, t_skrr *skrr, long best_cycle, int best_player)
{
	t_chmp	*chmp_tmp;
	char	*name;

	chmp_tmp = chmp;
	chmp_tmp->next != NULL ? chmp_tmp = chmp_tmp->next : 0;
	while (chmp_tmp)
	{
		if (best_cycle <= chmp_tmp->last_live)
		{
			if (best_cycle == chmp_tmp->last_live)
				best_player =
				best_player < chmp_tmp->id ? chmp_tmp->id : best_player;
			else
				best_player = chmp_tmp->id;
		}
		chmp_tmp = chmp_tmp->next;
	}
	print_info(skrr, skrr->chmp);
	name = name_winner(chmp, best_player);
	ft_printf("Contestant %ld, " GRN"\"%s\","RESET "has won !\n", best_player * (-1), name);
	(skrr->flag_v == 1) ? endwin() : 0;
	exit(1);
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

