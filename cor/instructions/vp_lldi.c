/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:39:09 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/02 18:39:10 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../virtual_machine/virtualm.h"

int 	lldi_instr(t_skrr *skrr, t_chmp *chmp, int op)
{
	unsigned char	*q;
	int 			address;

	if (!(q = malloc(sizeof(unsigned char) * g_tab[op].numb_of_arg)))
		exit (0);
	if (!(same_start(q, skrr, op, g_tab[op].numb_of_arg)))
		return (0);
	address = get_address(q, skrr, 1, 0);
	load_into(address, chmp, skrr, 2);
	skrr->process->pc += chmp->offset + 2;
	skrr->process->carry = 1;
	return (1);
}