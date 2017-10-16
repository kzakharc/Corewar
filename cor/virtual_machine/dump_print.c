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

void	print_info(t_skrr *skrr, t_chmp *chmp)
{
	t_chmp *champ_tmp;


	skrr->i = 0;
	skrr->n = 1;
	champ_tmp = chmp;
	(skrr->i == 0) ? ft_printf("Introducing contestants...\n") : 0;
	while (champ_tmp)
	{
		ft_printf("* Player %d, ", champ_tmp->ac * (-1));
		ft_printf("Name:" GRN" \"%s\", "RESET, champ_tmp->header.prog_name);
		ft_printf("weighing" GRN" %u "RESET "bytes, ",
				  champ_tmp->header.prog_size);
		ft_printf("comment:" GRN" \"%s\"\n"RESET,
				  champ_tmp->header.comment);
		champ_tmp = champ_tmp->next;
		skrr->i++;
	}
}

void	dump_print(t_skrr *skrr)
{
	print_info(skrr, skrr->chmp);
	print_map(skrr);
}