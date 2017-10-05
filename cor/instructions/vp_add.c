/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 16:49:35 by yzakharc          #+#    #+#             */
/*   Updated: 2017/10/05 16:49:37 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../virtual_machine/virtualm.h"

int 	add_instr(t_skrr *skrr, t_chmp *chmp, int op)
{
	unsigned char	*q;
	int 			address;
	int 			reg;

	if (!(q = malloc(sizeof(unsigned char) * g_tab[op].numb_of_arg)))
		exit(0);
	if (!(same_start(q, skrr, op, g_tab[op].numb_of_arg)))
		return (0);
	address = determination_of_action(q, skrr, 0, 1);
	skrr->process->tmp_pc += 1;
	reg = reg_param(skrr, &skrr->map[skrr->process->tmp_pc], 2);
	skrr->process->registry[reg] = (unsigned int)address;
	skrr->process->carry = 1;
	return (1);
}
