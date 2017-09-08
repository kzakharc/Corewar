/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:37:47 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/02 18:37:48 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../virtual_machine/virtualm.h"

int 			sti_instr(t_skrr *skrr, t_chmp *chmp)
{
	unsigned char	*q;
	int 			address;

	chmp->tmp_PC = chmp->PC + 1;
	if (&skrr->map[chmp->tmp_PC] == NULL)
		return (0);
	(!(q = malloc(sizeof(unsigned int) * 3))) ? exit (0) : 0;
	skrr->i = 0;
	if (g_tab[10].numb_of_arg != 3)
	{
		ft_printf("You bastard, changed number of arguments in op.c\n");
		exit (0);
	}
	while (skrr->i < g_tab[10].numb_of_arg)
		q[skrr->i++] = arg_types(skrr, chmp, chmp->tmp_PC);
	address = instr(q, chmp, skrr);
	chmp->PC += chmp->offset + 2;
	return (address);
}

unsigned char	arg_types(t_skrr *skrr, t_chmp *chmp, int ctk)
{
	if (hex_to_bin(skrr->map[ctk], skrr->i) == REG_CODE && (chmp->offset += REG_SIZE))
		return (T_REG);
	else if (hex_to_bin(skrr->map[ctk], skrr->i) == DIR_CODE && (chmp->offset += DIR_SIZE))
		return (T_DIR);
	else if (hex_to_bin(skrr->map[ctk], skrr->i) == IND_CODE && (chmp->offset += IND_SIZE))
		return (T_IND);
	return (0);
}

short 		hex_to_bin(unsigned char c, int i)
{
	short dst;

	dst = c;
	if ((i == 0) && (dst = (short)(dst & 0x40) >> 6))
		return (dst);
	else if ((i == 1) && (dst = (short)(dst & 0x30) >> 4))
		return (dst);
	else if ((i == 2) && (dst = (short)(dst & 0xc) >> 2))
		return (dst);
	return (0);
}

int 			instr(unsigned char *q, t_chmp *chmp, t_skrr *skrr)
{
	int 			address;
	unsigned short	i;

	i = 0;
	chmp->reg_n = 0; 															// maybe can delete this. already init this variable in [new_chmp.c].
	if (q[i] == T_REG && (chmp->tmp_PC += 1))
		chmp->reg_n = reg_param(skrr, &skrr->map[skrr->chmp->tmp_PC]);
	else if (q[i] == T_DIR && (chmp->tmp_PC += 1))
		chmp->reg_n = dir_param(skrr, &skrr->map[skrr->chmp->tmp_PC]);
	else if (q[i] == T_IND && (chmp->tmp_PC += 1))
		chmp->reg_n =  ind_param(skrr, &skrr->map[skrr->chmp->tmp_PC]);
	i++;
	address = get_address(q, skrr, chmp, i);
	return (address);
}

int 	get_address(unsigned char *q, t_skrr *skrr, t_chmp *chmp, unsigned short i)
{
	int adr;

	adr = 0;
	if (q[i] == T_REG && (chmp->tmp_PC += 1))
		adr = reg_param(skrr, &skrr->map[chmp->tmp_PC]);
	else if (q[i] == T_DIR && (chmp->tmp_PC += 1))
		adr = dir_param(skrr, &skrr->map[chmp->tmp_PC]);
	else if (q[i] == T_IND && (chmp->tmp_PC += 1))
		adr = ind_param(skrr, &skrr->map[chmp->tmp_PC]);
	i++;
	if (q[i] == T_REG && (chmp->tmp_PC += 1))
		adr += reg_param(skrr, &skrr->map[chmp->tmp_PC]);
	else if (q[i] == T_DIR && (chmp->tmp_PC += 1))
		adr += dir_param(skrr, &skrr->map[chmp->tmp_PC]);
	else if (q[i] == T_IND && (chmp->tmp_PC += 1))
		adr += ind_param(skrr, &skrr->map[chmp->tmp_PC]);
	adr = (chmp->PC + (adr % IDX_MOD));
	return (adr);
}
