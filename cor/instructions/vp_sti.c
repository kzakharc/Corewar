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
	unsigned int	q[3];

	chmp->PC++;
	if (chmp->PC == NULL)
		return (0);
	skrr->i = 0;
	chmp->offset = 0;
	while (skrr->i < op_tab[10].numb_of_arg)
		q[skrr->i++] = arg_types(skrr, chmp);
	skrr->i = 0;
	while (skrr->i < op_tab[10].numb_of_arg)
	{
		instr(q[skrr->i], chmp->PC);
		skrr->i++;
	}
	chmp->PC += (chmp->offset + 1);
	return (1);
}

unsigned int			arg_types(t_skrr *skrr, t_chmp *chmp)
{
	if (hex_to_bin(*chmp->PC, skrr->i) == REG_CODE && (chmp->offset += 1))
		return (T_REG);
	else if (hex_to_bin(*chmp->PC, skrr->i) == DIR_CODE && (chmp->offset += 2))
		return (T_DIR);
	else if (hex_to_bin(*chmp->PC, skrr->i) == IND_CODE && (chmp->offset += IND_SIZE))
		return (T_IND);
	else if ((hex_to_bin(*chmp->PC, skrr->i) == 0))
		return (0);
}

int 			instr(int q, unsigned char *c)
{
	if (q == T_REG)
	{

	}
	else if (q == T_DIR)
	{

	}
	else if (q == T_IND)
	{

	}
	else
		return (0);
	return (1);
}

unsigned int 	hex_to_bin(unsigned char c, int i)
{
	if ((i == 0) && (c = (c & 0x40) >> 6))
		return (c);
	else if ((i == 1) && (c = (c & 0x30) >> 4))
		return (c);
	else if ((i == 2) && (c = (c & 0xc) >> 2))
		return (c);
	return (0);
}