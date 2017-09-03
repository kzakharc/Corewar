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

int 	sti_instr(t_skrr *skrr)
{
	unsigned int q[3];

	skrr->PC++;
	if (skrr->PC == NULL)
		return (0);
	skrr->i = 0;
	while (skrr->i < op_tab[10].numb_of_arg)
	{
		q[skrr->i] = 0;
		if (hex_to_bin(*skrr->PC, skrr->i) == REG_CODE && (skrr->PC += 1))
			q[skrr->i] = T_REG;
		else if (hex_to_bin(*skrr->PC, skrr->i) == DIR_CODE && (skrr->PC += 2))
			q[skrr->i] = T_DIR;
		else if (hex_to_bin(*skrr->PC, skrr->i) == IND_CODE && (skrr->PC += IND_SIZE))
			q[skrr->i] = T_IND;
		else if ((hex_to_bin(*skrr->PC, skrr->i) == 0))
			return (0);
		skrr->i++;
	}
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