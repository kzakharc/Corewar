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
	init_data(new_champ);
	new_champ->fd = skrr->fd;
	push_process(&skrr->process, skrr, new_champ->id);
	new_champ->next = *head;
	*head = new_champ;
	return (1);
}

void 	init_data(t_chmp *champ)
{
	static int	tmp;

	champ->reg_value = 0;
	champ->offset = 0;
	champ->id = tmp * (-1);
	champ->player_pos = 0;
	champ->live = 0;
	champ->cycles = 0;
	tmp++;
}

int 	push_process(t_proc **process, t_skrr *skrr, int id)
{
	t_proc 	*new_process;
	int 	i;

	i = -1;
	if (!(new_process = malloc(sizeof(t_proc))))
		exit (0);
	while (++i < REG_NUMBER)
		new_process->registry[i] = 0;
	new_process->id = id;
	new_process->carry = 0;
	new_process->pc = 0;
	new_process->alive = 1;
	new_process->current_cycles = 0;
	new_process->next = *process;
	*process = new_process;
	return (1);
}
