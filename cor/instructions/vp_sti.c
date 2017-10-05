/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:37:47 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/02 18:37:48 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../virtual_machine/virtualm.h"

int 			sti_instr(t_skrr *skrr, t_chmp *chmp, int op)
{
	unsigned char	*q;
	int 			address;

	if ((skrr->process->current_cycles != 0) &&
			(skrr->process->current_cycles) % (g_tab[skrr->op].cycles) == 0)
	{
		if (!(q = malloc(sizeof(unsigned char) * g_tab[op].numb_of_arg)))
			exit(0);
		if (!(same_start(q, skrr, op, g_tab[op].numb_of_arg)))
			return (0);
		if ((!from_reg(q, chmp, skrr, 0) && (g_err) && !(g_err = 0)))
			return (0);
		address = get_address(q, skrr, 0, 1);
		load_into(address, chmp, skrr, 1);
		skrr->process->pc += chmp->offset + 2;
		ft_printf("sti\tcurrent_cycles: %d\npc: %d\n", skrr->process->current_cycles, skrr->process->pc);
	}
	return (1);
}
