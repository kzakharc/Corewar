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

#include "../virtual_machine/virtualm.h"

int		supp_to_and(unsigned char *q, t_skrr *skrr, short i, int l)
{
	int adr;

	adr = 0;
	if (q[i] == T_REG && (skrr->process->tmp_pc += 1))
		adr = reg_param(skrr, &skrr->map[skrr->process->tmp_pc], 1);
	else if (q[i] == T_DIR && (skrr->process->tmp_pc += 1))
		adr = dir_param(skrr, &skrr->map[skrr->process->tmp_pc], g_tab[6].dir_size);
	else if (q[i] == T_IND && (skrr->process->tmp_pc += 1))
		adr = ind_param(skrr, &skrr->map[skrr->process->tmp_pc], l, 4);
	i++;
	if (q[i] == T_REG && (skrr->process->tmp_pc += 1))
		adr &= reg_param(skrr, &skrr->map[skrr->process->tmp_pc], 1);
	else if (q[i] == T_DIR && (skrr->process->tmp_pc += 1))
		adr &= dir_param(skrr, &skrr->map[skrr->process->tmp_pc], g_tab[6].dir_size);
	else if (q[i] == T_IND && (skrr->process->tmp_pc += 1))
		adr &= ind_param(skrr, &skrr->map[skrr->process->tmp_pc], l, 4);
	return (adr);
}

int 	determination_of_action(unsigned char *q, t_skrr *skrr, int l, int key)
{
	int		result;
	short	i;

	result = 0;
	i = 0;
	if (key == 1 && (skrr->process->tmp_pc += 1))
	{
		result = reg_param(skrr, &skrr->map[skrr->process->tmp_pc], 1);
		skrr->process->tmp_pc += 1;
		result += reg_param(skrr, &skrr->map[skrr->process->tmp_pc], 1);
	}
	else if (key == 2 && (skrr->process->tmp_pc += 1))
	{
		result = reg_param(skrr, &skrr->map[skrr->process->tmp_pc], 1);
		skrr->process->tmp_pc += 1;
		result -= reg_param(skrr, &skrr->map[skrr->process->tmp_pc], 1);
	}
	else if (key == 3 && (skrr->process->tmp_pc += 1))
		result = supp_to_and(q, skrr, i, l);
	(l == 0) ? result = (skrr->process->pc + (result % IDX_MOD)) : 0;
	return (result);
}