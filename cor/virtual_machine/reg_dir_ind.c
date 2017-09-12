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
	(REG_SIZE != 1) ? sizes_err("REG_SIZE", 1) : 0;
	if ((*map > 16) || (*map == 0) || (*map < 0))
	{
		skrr->err = 1;
		return (0);
	}
	if (flag == 1)
		return (skrr->chmp->registry[*map - 1]);
	else if (flag == 2)
		return (*map - 1);
	return (0);
}

int		dir_param(t_skrr *skrr, unsigned char *map, short dir_size)
{
	int address;

	address = 0;
	if (dir_size == 1)
	{
		(DIR_SIZE != 2) ? sizes_err("DIR_SIZE", 2) : 0;
		address = (short)two_four_bytes(map, 2);
		skrr->chmp->tmp_PC += 1;
	}
	else if (dir_size == 0)
	{
		(DIR_SIZE + 2 != 4) ? sizes_err("DIR_SIZE", 2) : 0;
		address = two_four_bytes(map, 4);
		skrr->chmp->tmp_PC += 3;
	}
	return (address);
}

int		ind_param(t_skrr *skrr, unsigned char *map)
{
	int 			address;
	unsigned int	ind[4];
	int 			i;

	(IND_SIZE != 2) ? sizes_err("IND_SIZE", 3) : 0;
	i = -1;
	skrr->shift = 24;
	address = (short)two_four_bytes(map, 2) % IDX_MOD;
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
