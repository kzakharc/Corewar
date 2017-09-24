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

/*
**	flag = 1 -> get value from registry, 2 -> just get number of registry
*/

int		reg_param(t_skrr *skrr, unsigned char *map, int flag)
{
	(REG_SIZE != 1) ? sizes_err("REG_SIZE", 1) : 0;
	if (((*map > 16) || (*map <= 0)) && (g_err = 1))
		return (0);
	if (flag == 1)
		return (skrr->process->registry[*map - 1]);
	else if (flag == 2)
		return (*map - 1);
	return (0);
}


/*
**	dir_size, if dir_size = 1 -> means DIR_SIZE = 2 bytes, 0 -> DIR_SIZE = 4 bytes
*/

int		dir_param(t_skrr *skrr, unsigned char *map, short dir_size)
{
	int address;

	address = 0;
	if (dir_size == 1)
	{
		(DIR_SIZE != 2) ? sizes_err("DIR_SIZE", 2) : 0;
		address = (short)two_four_bytes(map, 2);
		skrr->process->tmp_pc += 1;
	}
	else if (dir_size == 0)
	{
		(DIR_SIZE + 2 != 4) ? sizes_err("DIR_SIZE", 2) : 0;
		address = two_four_bytes(map, 4);
		skrr->process->tmp_pc += 3;
	}
	return (address);
}

/*
**	int l, if l = 1 -> for long function, means without %IDX_MOD
*/

int		ind_param(t_skrr *skrr, unsigned char *map, int l, int bytes)
{
	int 			address;
	unsigned int	ind[bytes];
	int 			i;

	(IND_SIZE != 2) ? sizes_err("IND_SIZE", 3) : 0;
	i = -1;
	address = 0;
	skrr->shift = (bytes == 4) ? 24 : 8;
	(l == 0) ? address = (short)two_four_bytes(map, 2) % IDX_MOD : 0;
	(l == 1) ? address = (short)two_four_bytes(map, 2) : 0;
	while (++i < bytes)
	{
		address = (address + MEM_SIZE) % MEM_SIZE;
		ind[i] = get_magic_size(skrr->map[address], skrr->shift);
		skrr->shift -= 8;
		address++;
	}
	address = (bytes == 4) ? (ind[0] | ind[1] | ind[2] | ind[3]) : (ind[0] | ind[1]);
	skrr->process->tmp_pc += 1;
	return (address);
}
