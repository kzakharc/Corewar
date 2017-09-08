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

short	two_bytes(unsigned char *map)
{
	short dst;

	dst = *map;
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
	int 			address;
	unsigned int	ind[4];
	int 			i;

	i = -1;
	skrr->shift = 24;
	address = (two_bytes(map) | (*(map + 1))) % IDX_MOD;
	while (++i < 4)
	{
		address = (address + MEM_SIZE) % MEM_SIZE;
		ind[i] = get_magic_size(skrr->map[address], skrr->shift);
		skrr->shift -= 8;
		address++;
	}
	address = ind[0] | ind[1] | ind[2] | ind[3];
	skrr->chmp->tmp_PC += 1;
	return (address);
}

/*
**
*/
