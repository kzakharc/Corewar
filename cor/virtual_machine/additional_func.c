/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 17:30:37 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/10 17:30:38 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtualm.h"

/*
**	for sti instr
*/

unsigned int	two_four_bytes(unsigned char *map, int size)
{
	unsigned int	f[4];
	unsigned int	dst;
	int				i;

	dst = 0;
	i = -1;
	while (++i < 4)
		f[i] = *map++;
	if (size == 2)
		dst = (f[0] << 8) | f[1];
	else if (size == 4)
		dst = ((f[0] << 24) | (f[1] << 16) | (f[2] << 8) | f[3]);
	return (dst);
}

unsigned char	arg_types(t_skrr *skrr, t_chmp *chmp, int ctk)
{
//	chmp->offset = 0;
	if (hex_to_bin(skrr->map[ctk], skrr->i) == REG_CODE && (chmp->offset += REG_SIZE))
		return (T_REG);
	else if (hex_to_bin(skrr->map[ctk], skrr->i) == DIR_CODE && (chmp->offset += DIR_SIZE))
		return (T_DIR);
	else if (hex_to_bin(skrr->map[ctk], skrr->i) == IND_CODE && (chmp->offset += IND_SIZE))
		return (T_IND);
	return (0);
}

unsigned char 		hex_to_bin(unsigned char c, int i)
{
	unsigned char dst;

	dst = c;
	if ((i == 0) && (dst = (dst >> 6)))
		return (dst);
	else if ((i == 1) && (dst = (unsigned char)((dst << 2) & 0x000000ff) >> 6))
		return (dst);
	else if ((i == 2) && (dst = (unsigned char)((dst << 4) & 0x000000ff) >> 6))
		return (dst);
	return (0);
}
