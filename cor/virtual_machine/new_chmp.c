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

#include "../../corewar.h"

int 	push_chmp(t_chmp **head, t_skrr *skrr)
{
	t_chmp *new_champ;

	if (!(new_champ = malloc(sizeof(t_chmp))))
		exit (0);
	init_data(new_champ, skrr);
	new_champ->fd = skrr->fd;
	push_process(&skrr->process, skrr, new_champ->id);
	new_champ->next = *head;
	*head = new_champ;
	return (1);
}

void 	init_data(t_chmp *champ, t_skrr *skrr)
{
	champ->reg_value = 0;
	champ->offset = 0;
	champ->id = skrr->init_id * (-1);
	champ->player_pos = 0;
	champ->live_count = 0;
	champ->last_live = 0;
	skrr->init_id++;
}

int 	push_process(t_proc **process, t_skrr *skrr, int id)
{
	t_proc 	*new_process;
	int 	i;

	if (!(new_process = malloc(sizeof(t_proc))))
		exit (0);
	i = -1;
	while (++i < REG_NUMBER)
		new_process->registry[i] = 0;
	new_process->id = id;
	new_process->carry = 0;
	new_process->pc = 0;
	new_process->alive = 1;
	new_process->current_cycles = 0;
	new_process->live_count = 0;
	skrr->process_count++;
	new_process->next = *process;
	*process = new_process;
	return (1);
}

int 	inheritance_proc(t_proc **process, int pc)
{
	t_proc 	*new_process;
	int 	i;

	if (!(new_process = malloc(sizeof(t_proc))))
		exit (0);
	i = -1;
	while (++i < REG_NUMBER)
		new_process->registry[i] = (*process)->registry[i];
	new_process->id = (*process)->id;
	new_process->pc = pc;
	new_process->tmp_pc = pc;
	new_process->alive = (*process)->alive;
	new_process->current_cycles = (*process)->current_cycles;
	new_process->next = *process;
	*process = new_process;
	return (1);
}