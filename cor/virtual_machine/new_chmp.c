/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_chmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 17:30:50 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/10 17:30:51 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtualm.h"

int 	push_chmp(t_chmp **head, t_skrr *skrr)
{
	t_chmp *new_champ;

	if (!(new_champ = malloc(sizeof(t_chmp))))
		exit (0);
	init_data(new_champ, skrr);
	new_champ->next = *head;
	*head = new_champ;
	return (1);
}

void 	init_data(t_chmp *champ, t_skrr *skrr)
{
	int i;

	i = -1;
	while (++i < REG_NUMBER)
		champ->registry[i] = 0;
	champ->registry[0] = (unsigned int)skrr->j * (-1);
	champ->reg_value = 0;
	champ->offset = 0;
	champ->player_pos = 0;
	champ->cycle_to_die = CYCLE_TO_DIE;
	champ->nbr_live = 0;
	champ->carry = 0;
	champ->PC = 0;
}
