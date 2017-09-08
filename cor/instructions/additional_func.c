/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_virtual_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:12:55 by vpoltave          #+#    #+#             */
/*   Updated: 2017/08/08 15:42:25 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../virtual_machine/virtualm.h"

/*
**	for sti instr
*/

short	two_bytes(unsigned char *tmp)
{
	short dst;

	dst = *tmp;
	dst = (short)((dst << 8) & 0xff00);
	return (dst);
}

int		reg_param(t_skrr *skrr, unsigned char *map)
{
	if ((*map > 16) || (*map == 0) || (*map < 0))
		return (0);
	return (skrr->chmp->registry[*map - 1]);
}

int		dir_param(t_skrr *skrr, unsigned char *map)
{
	int address;

	address = two_bytes(map) | (*(map + 1));
	skrr->chmp->tmp_PC += 1;
	return (address);
}

int		ind_param(t_skrr *skrr, unsigned char *map)
{
	int address;

	address = (two_bytes(map) | (*(map + 1))) % IDX_MOD;
	skrr->chmp->tmp_PC += 1;
	return (address);
}

/*
**
*/
