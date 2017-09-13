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
//		ft_printf("value to address: [%d] from reg: ", address);
		while (++i < 4)
		{
			address = (address + MEM_SIZE) % MEM_SIZE;
			skrr->map[address++] = (unsigned char)(chmp->reg_value >> shift & 0x000000ff);
//			ft_printf("%x", skrr->map[address - 1]);
			shift -= 8;
		}
	}
	else if (flag == 2)
	{
		while (++i < 4)
		{
			address = (address + MEM_SIZE) % MEM_SIZE;
			value[i] = get_magic_size(skrr->map[address++], shift);
			shift -= 8;
		}
		chmp->tmp_PC += 1;
		reg = reg_param(skrr, &skrr->map[skrr->chmp->tmp_PC], 2);
		chmp->process->registry[reg] = value[0] | value[1] | value[2] | value[3];
//		ft_printf("value to reg is loaded: [%.8x]", chmp->registry[reg]);
	}
}

int 	from_reg(unsigned char *q, t_chmp *chmp, t_skrr *skrr, short i)
{
	chmp->reg_value = 0; 					// maybe can delete this. already init this variable in [new_chmp.c].
	if (q[i] == T_REG && (chmp->tmp_PC += 1))
		chmp->reg_value = (unsigned int)reg_param(skrr, &skrr->map[skrr->chmp->tmp_PC], 1);
	else if (q[i] == T_DIR && (chmp->tmp_PC += 1))
		chmp->reg_value = (unsigned int)dir_param(skrr, &skrr->map[skrr->chmp->tmp_PC], g_tab[10].dir_size);
	else if (q[i] == T_IND && (chmp->tmp_PC += 1))
		chmp->reg_value =  (unsigned int)ind_param(skrr, &skrr->map[skrr->chmp->tmp_PC], 0, 4);
	if (skrr->err == 1)
		return (0);
	return (1);

}

int 	get_address(unsigned char *q, t_skrr *skrr, int l, short i)
{
	int adr;

	adr = 0;
	if (q[i] == T_REG && (skrr->chmp->tmp_PC += 1))
		adr = reg_param(skrr, &skrr->map[skrr->chmp->tmp_PC], 1);
	else if (q[i] == T_DIR && (skrr->chmp->tmp_PC += 1))
		adr = dir_param(skrr, &skrr->map[skrr->chmp->tmp_PC], g_tab[10].dir_size);
	else if (q[i] == T_IND && (skrr->chmp->tmp_PC += 1))
		adr = ind_param(skrr, &skrr->map[skrr->chmp->tmp_PC], l, 4);
	i++;
	if (q[i] == T_REG && (skrr->chmp->tmp_PC += 1))
		adr += reg_param(skrr, &skrr->map[skrr->chmp->tmp_PC], 1);
	else if (q[i] == T_DIR && (skrr->chmp->tmp_PC += 1))
		adr += dir_param(skrr, &skrr->map[skrr->chmp->tmp_PC], g_tab[10].dir_size);
	else if (q[i] == T_IND && (skrr->chmp->tmp_PC += 1))
		adr += ind_param(skrr, &skrr->map[skrr->chmp->tmp_PC], l, 4);
	adr = (skrr->chmp->process->PC + (adr % IDX_MOD));
	return (adr);
}

int 	simple_address(unsigned char *q, t_skrr *skrr, t_chmp *chmp, short i)
{
	int adr;

	adr = 0;
	if (q[i] == T_IND && (chmp->tmp_PC += 1))
	{
		(IND_SIZE != 2) ? sizes_err("IND_SIZE", 3) : 0;
		adr = (short)two_four_bytes(&skrr->map[chmp->tmp_PC], 2);
		adr = (chmp->process->PC + (adr % IDX_MOD));
	}
	else if ((q[i] == T_REG) && (chmp->tmp_PC += 1))
		adr = reg_param(skrr, &skrr->map[skrr->chmp->tmp_PC], 2);
	return (adr);
}
