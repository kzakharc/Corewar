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
//	new_process->alive = 1;
	new_process->live_color = 0;
	new_process->live_pc = -1;
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
//	new_process->alive = 1;
	new_process->carry = (*process)->carry;
	new_process->live_proc = (*process)->live_proc;
	new_process->waiting_cycles = 0;
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
	if (*process == NULL)
		winner(skrr->chmp, skrr, skrr->chmp->last_live, skrr->chmp->id);
	return (1);
}

//int check_is_live(t_proc **procs, t_skrr *skrr)
//{
//	t_proc *tmp;
//	t_proc *prev;
//	t_proc *address;
//
//	tmp = *procs;
//	prev = tmp;
//	while (tmp) {
//		if (tmp->live_proc) {
//			tmp->live_proc = 0;
//			prev = tmp;
//			address = tmp->next;
//		} else
//		{
//			if (*procs == tmp)
//				*procs = tmp->next;
//			prev->next = tmp->next;
//			address = tmp->next;
//			free(tmp);
//			skrr->process_count--;
//		}
//		tmp = address;
//	}
//	if (*procs == NULL)
//		return (0);
//	return (1);
//}

//int 	alive(t_proc *process, t_skrr *skrr)
//{
//	t_proc 	*proc_tmp;
//	int 	alive;
//
//	proc_tmp = process;
//	alive = 0;
//	while (proc_tmp)
//	{
//		if (proc_tmp->live_proc == 0 && (proc_tmp->alive == 1))
//		{
//			proc_tmp->alive = 0;
//			skrr->process_count -= 1;
//		}
//		else if (proc_tmp->live_proc == 1)
//		{
//			proc_tmp->live_proc = 0;
//			alive = 1;
//		}
//		proc_tmp = proc_tmp->next;
//	}
//	if (alive == 1)
//		return (1);
//	winner(skrr->chmp, skrr, skrr->chmp->last_live, skrr->chmp->id);
//	return (0);
//}
