/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 18:19:52 by yzakharc          #+#    #+#             */
/*   Updated: 2017/10/11 18:19:56 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void	print_map(t_skrr *skrr)
{
	int line;

	line = 0;
	skrr->i = 0;
	ft_printf("0x0000 : ");
	while (skrr->i < MEM_SIZE)
	{
		ft_printf("%hh.2x ", skrr->map[skrr->i]);
		if ((skrr->i + 1) % 64 == 0 && skrr->i != 4095)
			ft_printf("\n%06#x : ", line += 64);
		skrr->i++;
	}
}

void	dump_print(t_skrr *skrr)
{
	print_info(skrr, skrr->chmp);
	print_map(skrr);
}