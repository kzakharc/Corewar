/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_skrr_&_global.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:48:46 by yzakharc          #+#    #+#             */
/*   Updated: 2017/10/12 14:48:47 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void	init(t_skrr *skrr)
{
	skrr->fd = 0;
	skrr->i = 0;
	skrr->j = 0;
	skrr->n = 0;
	skrr->op = 0;
	skrr->shift = 0;
	skrr->init_id = 1;
	skrr->flag_n = NULL;
	skrr->cnt_n = 0;
	skrr->flag_v = 0;
	skrr->flag_dump = 0;
	skrr->flag_a = 0;
	skrr->max_player = 0;
	skrr->max_checks = MAX_CHECKS;
	skrr->cycle_to_die = CYCLE_TO_DIE;
	skrr->process_count = 0;
	skrr->nbr_live = 0;
	g_cycles = 0;
	g_ctd = 0;
	g_err = 0;
	skrr->chmp = NULL;
	skrr->process = NULL;
}
