/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:40:42 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/02 18:40:43 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../virtual_machine/virtualm.h"

int 	sub_instr(t_skrr *skrr, t_chmp *chmp, int op)
{
	unsigned char	*q;
	int 			address;
	int 			reg;

	if (!(q = malloc(sizeof(unsigned char) * g_tab[op].numb_of_arg)))
		exit(0);
	if (!(same_start(q, skrr, op, g_tab[op].numb_of_arg)))
		return (0);
	address = determination_of_action(q, skrr, 0, 2);
	skrr->process->tmp_pc += 1;
	reg = reg_param(skrr, &skrr->map[skrr->process->tmp_pc], 2);
	skrr->process->registry[reg] = (unsigned int)address;
	skrr->process->carry = 1;
	return (1);
}
