/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_load_from_into.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 17:31:50 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/10 17:31:51 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtualm.h"

void	load_into(int address, t_chmp *chmp, t_skrr *skrr, int flag)
{
	int 			i;
	int				shift;
	unsigned int 	value[4];
	int 			reg;

	i = -1;
	shift = 24;
	if (flag == 1)
	{
		while (++i < 4)
		{
			address = (address + MEM_SIZE) % MEM_SIZE;
			skrr->map[address++] = (unsigned char)(chmp->reg_value >> shift & 0x000000ff);
			shift -= 8;
		}
	}
	else if (flag == 2)
	{
		while (++i < 4)
		{
			address = (address + MEM_SIZE) % MEM_SIZE;
			value[i] = skrr->map[address++];
		}
		reg = reg_param(skrr, &skrr->map[skrr->chmp->tmp_PC], 2);
		chmp->registry[reg] = value[0] | value[1] | value[2] | value[3];
	}
}

void 	from_reg(unsigned char *q, t_chmp *chmp, t_skrr *skrr, short i)
{
	chmp->reg_value = 0; 															// maybe can delete this. already init this variable in [new_chmp.c].
	if (q[i] == T_REG && (chmp->tmp_PC += 1))
		chmp->reg_value = (unsigned int)reg_param(skrr, &skrr->map[skrr->chmp->tmp_PC], 1);
	else if (q[i] == T_DIR && (chmp->tmp_PC += 1))
		chmp->reg_value = (unsigned int)dir_param(skrr, &skrr->map[skrr->chmp->tmp_PC], g_tab[10].dir_size);
	else if (q[i] == T_IND && (chmp->tmp_PC += 1))
		chmp->reg_value =  (unsigned int)ind_param(skrr, &skrr->map[skrr->chmp->tmp_PC]);
}

//void	to_reg(t_chmp *chmp, t_skrr *skrr, int reg, short i)
//{
//
//}

int 	get_address(unsigned char *q, t_skrr *skrr, t_chmp *chmp, short i)
{
	int adr;

	adr = 0;
	if (q[i] == T_REG && (chmp->tmp_PC += 1))
		adr = reg_param(skrr, &skrr->map[chmp->tmp_PC], 1);
	else if (q[i] == T_DIR && (chmp->tmp_PC += 1))
		adr = dir_param(skrr, &skrr->map[chmp->tmp_PC], g_tab[10].dir_size);
	else if (q[i] == T_IND && (chmp->tmp_PC += 1))
		adr = ind_param(skrr, &skrr->map[chmp->tmp_PC]);
	i++;
	if (q[i] == T_REG && (chmp->tmp_PC += 1))
		adr += reg_param(skrr, &skrr->map[chmp->tmp_PC], 1);
	else if (q[i] == T_DIR && (chmp->tmp_PC += 1))
		adr += dir_param(skrr, &skrr->map[chmp->tmp_PC], g_tab[10].dir_size);
	else if (q[i] == T_IND && (chmp->tmp_PC += 1))
		adr += ind_param(skrr, &skrr->map[chmp->tmp_PC]);
	adr = (chmp->PC + (adr % IDX_MOD));
	return (adr);
}
