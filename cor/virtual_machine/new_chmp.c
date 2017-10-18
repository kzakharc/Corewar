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
	new_process->live_proc = 0;
	new_process->waiting_cycles = 0;
	new_process->sop = -1;
	skrr->process_count++;
	new_process->next = *process;
	*process = new_process;
	return (1);
}

int 	inheritance_proc(t_proc **process, int pc, t_skrr *skrr)
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
	new_process->carry = (*process)->carry;
	new_process->live_proc = (*process)->live_proc;
	new_process->waiting_cycles = 1;
	new_process->sop = -1;
	skrr->process_count++;
	new_process->next = skrr->process;
	skrr->process = new_process;
	return (1);
}

int 	kill_processes(t_proc **process, t_proc *prev, t_skrr *skrr)
{
	t_proc *current_proc;

	current_proc = *process;

	while (current_proc)
	{
		if (current_proc->live_proc == 0)
		{
			if (prev)
				prev->next = current_proc->next;
			else
				*process = current_proc->next;
			free(current_proc);
			skrr->process_count--;
		}
		else if (current_proc->live_proc == 1)
		{
			current_proc->live_proc = 0;
			prev = current_proc;
		}
		current_proc = current_proc->next;
	}
	return (1);
}
