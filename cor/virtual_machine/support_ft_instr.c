/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_ft_instr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 18:34:54 by yzakharc          #+#    #+#             */
/*   Updated: 2017/10/05 18:34:55 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int		supp_to_and(unsigned char *q, t_skrr *skrr, short i, int l, t_proc *process)
{
	int adr;

	adr = 0;
	process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
	if (q[i] == T_REG)
	{
		adr = reg_param(skrr, process, 1);
		if (g_err)
			return (0);
	}
	if (q[i] == T_DIR)
		adr = dir_param(skrr, process, g_tab[6].dir_size);
	if (q[i] == T_IND)
		adr = ind_param(skrr, process, l, 4);
	i++;
	process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
	if (q[i] == T_REG)
	{
		adr &= reg_param(skrr, process, 1);
		if (g_err)
			return (0);
	}
	if (q[i] == T_DIR)
		adr &= dir_param(skrr, process, g_tab[6].dir_size);
	if (q[i] == T_IND)
		adr &= ind_param(skrr, process, l, 4);
	return (adr);
}

int 	supp_to_or(unsigned char *q, t_skrr *skrr, short i, int l, t_proc *process)
{
	int adr;

	adr = 0;
	process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
	if (q[i] == T_REG)
	{
		adr = reg_param(skrr, process, 1);
		if (g_err)
			return (0);
	}
	if (q[i] == T_DIR)
		adr = dir_param(skrr, process, g_tab[6].dir_size);
	if (q[i] == T_IND)
		adr = ind_param(skrr, process, l, 4);
	i++;
	process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
	if (q[i] == T_REG)
	{
		adr |= reg_param(skrr, process, 1);
		if (g_err)
			return (0);
	}
	if (q[i] == T_DIR)
		adr |= dir_param(skrr, process, g_tab[6].dir_size);
	if (q[i] == T_IND)
		adr |= ind_param(skrr, process, l, 4);
	return (adr);
}

int 	supp_to_xor(unsigned char *q, t_skrr *skrr, short i, int l, t_proc *process)
{
	int adr;

	adr = 0;
	process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
	if (q[i] == T_REG)
	{
		adr = reg_param(skrr, process, 1);
		if (g_err)
			return (0);
	}
	if (q[i] == T_DIR)
		adr = dir_param(skrr, process, g_tab[6].dir_size);
	if (q[i] == T_IND)
		adr = ind_param(skrr, process, l, 4);
	i++;
	process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
	if (q[i] == T_REG)
	{
		adr ^= reg_param(skrr, process, 1);
		if (g_err)
			return (0);
	}
	if (q[i] == T_DIR)
		adr ^= dir_param(skrr, process, g_tab[6].dir_size);
	if (q[i] == T_IND)
		adr ^= ind_param(skrr, process, l, 4);
	return (adr);
}

int 	determination_of_action(unsigned char *q, t_skrr *skrr, int l, int key, t_proc *process)
{
	int		result;
	short	i;

	result = 0;
	i = 0;
	if (key == 1)
	{
		process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
		if (!(result = reg_param(skrr, process, 1)) && (g_err))
			return (0);
		process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
		result += reg_param(skrr, process, 1);
		if (g_err)
			return (0);
	}
	else if (key == 2)
	{
		process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
		if (!(result = reg_param(skrr, process, 1)) && (g_err))
			return (0);
		process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
		result -= reg_param(skrr, process, 1);
		if (g_err)
			return (0);
	}
	else if (key == 3)
		if (!(result = supp_to_and(q, skrr, i, l, process)) && (g_err))
			return (0);
	if (key == 4)
		if (!(result = supp_to_or(q, skrr, i, l, process)) && (g_err))
			return (0);
	if (key == 5)
		if (!(result = supp_to_xor(q, skrr, i, l, process)) && (g_err))
			return (0);
	return (result);
}