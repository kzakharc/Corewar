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

unsigned char	two_bytes(unsigned char *map)
{
	unsigned char dst;

	dst = *map;
	dst = (unsigned char)((dst << 8) & 0xff00);
	return (dst);
}

unsigned char	four_bytes(unsigned char *map) // for dir_size = 4b, still not finished
{
	unsigned char dst;

	dst = *map;
	return (dst);
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
