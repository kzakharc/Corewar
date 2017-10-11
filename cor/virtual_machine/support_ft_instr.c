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
	if (q[i] == T_REG && (process->tmp_pc += 1))
		adr = reg_param(skrr, process, 1);
	else if (q[i] == T_DIR && (process->tmp_pc += 1))
		adr = dir_param(skrr, process, g_tab[6].dir_size);
	else if (q[i] == T_IND && (process->tmp_pc += 1))
		adr = ind_param(skrr, process, l, 4);
	i++;
	if (q[i] == T_REG && (process->tmp_pc += 1))
		adr &= reg_param(skrr, process, 1);
	else if (q[i] == T_DIR && (process->tmp_pc += 1))
		adr &= dir_param(skrr, process, g_tab[6].dir_size);
	else if (q[i] == T_IND && (process->tmp_pc += 1))
		adr &= ind_param(skrr, process, l, 4);
	return (adr);
}

int 	supp_to_or(unsigned char *q, t_skrr *skrr, short i, int l, t_proc *process)
{
	int adr;

	adr = 0;
	if (q[i] == T_REG && (process->tmp_pc += 1))
		adr = reg_param(skrr, process, 1);
	else if (q[i] == T_DIR && (process->tmp_pc += 1))
		adr = dir_param(skrr, process, g_tab[6].dir_size);
	else if (q[i] == T_IND && (process->tmp_pc += 1))
		adr = ind_param(skrr, process, l, 4);
	i++;
	if (q[i] == T_REG && (process->tmp_pc += 1))
		adr |= reg_param(skrr, process, 1);
	else if (q[i] == T_DIR && (process->tmp_pc += 1))
		adr |= dir_param(skrr, process, g_tab[6].dir_size);
	else if (q[i] == T_IND && (process->tmp_pc += 1))
		adr |= ind_param(skrr, process, l, 4);
	return (adr);
}

int 	supp_to_xor(unsigned char *q, t_skrr *skrr, short i, int l, t_proc *process)
{
	int adr;

	adr = 0;
	if (q[i] == T_REG && (process->tmp_pc += 1))
		adr = reg_param(skrr, process, 1);
	else if (q[i] == T_DIR && (process->tmp_pc += 1))
		adr = dir_param(skrr, process, g_tab[6].dir_size);
	else if (q[i] == T_IND && (process->tmp_pc += 1))
		adr = ind_param(skrr, process, l, 4);
	i++;
	if (q[i] == T_REG && (process->tmp_pc += 1))
		adr ^= reg_param(skrr, process, 1);
	else if (q[i] == T_DIR && (process->tmp_pc += 1))
		adr ^= dir_param(skrr, process, g_tab[6].dir_size);
	else if (q[i] == T_IND && (process->tmp_pc += 1))
		adr ^= ind_param(skrr, process, l, 4);
	return (adr);
}

int 	determination_of_action(unsigned char *q, t_skrr *skrr, int l, int key, t_proc *process)
{
	int		result;
	short	i;

	result = 0;
	i = 0;
	if (key == 1 && (process->tmp_pc += 1))
	{
		result = reg_param(skrr, process, 1);
		process->tmp_pc += 1;
		result += reg_param(skrr, process, 1);
	}
	else if (key == 2 && (process->tmp_pc += 1))
	{
		result = reg_param(skrr, process, 1);
		process->tmp_pc += 1;
		result -= reg_param(skrr, process, 1);
	}
	else if (key == 3)
		result = supp_to_and(q, skrr, i, l, process);
	else if (key == 4)
		result = supp_to_or(q, skrr, i, l, process);
	else if (key == 5)
		result = supp_to_xor(q, skrr, i, l, process);
	return (result);
}