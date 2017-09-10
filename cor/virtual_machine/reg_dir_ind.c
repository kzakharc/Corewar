/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_dir_ind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 17:30:59 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/10 17:31:00 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtualm.h"

int		reg_param(t_skrr *skrr, unsigned char *map, int flag)
{
	if ((*map > 16) || (*map == 0) || (*map < 0))
		return (0);
	if (flag == 1)
		return (skrr->chmp->registry[*(map - 1)]);
	else if (flag == 2)
		return (*map);
	return (0);
}

int		dir_param(t_skrr *skrr, unsigned char *map, int dir_size)
{
	int address;

	address = 0;
	if (dir_size == 1)
	{
		address = two_bytes(map) | (*(map + 1));
		skrr->chmp->tmp_PC += 1;
	}
	else if (dir_size == 0)	// TODO for some instr dir size == 4 (in op.c if 0 = 4b, 1 = 2b) so need to make else if for 4 bytes T_DIR
	{
		address = four_bytes(map);
	}
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
