/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_virtual_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:12:55 by vpoltave          #+#    #+#             */
/*   Updated: 2017/08/08 15:42:25 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtualm.h"

int 	entry_point(t_skrr *skrr)
{
	skrr->PC = &skrr->map[skrr->player_pos];
	while ((skrr->cycle_to_die > 0))
	{
		if (!which_instr(skrr))
			ft_printf("NULL address in PC!");
		if (skrr->nbr_live == NBR_LIVE)
			skrr->cycle_to_die -= CYCLE_DELTA;
		if (g_iter == skrr->cycle_to_die)
			skrr->cycle_to_die -= CYCLE_DELTA;
	}
	return (1);
}

int		which_instr(t_skrr *skrr)
{
	if (skrr->PC == NULL)
		return (0);
	
}