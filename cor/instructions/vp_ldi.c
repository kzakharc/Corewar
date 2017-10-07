/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:37:38 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/02 18:37:39 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../virtual_machine/virtualm.h"

int 	ldi_instr(t_skrr *skrr, t_proc *process)
{
	unsigned char	*q;
	int 			address;

	if ((process->current_cycles != 0) &&
		(process->current_cycles) % (g_tab[skrr->op].cycles) == 0)
	{
		if (!(q = malloc(sizeof(unsigned char) * g_tab[skrr->op].numb_of_arg)))
			exit(0);
		if (!(same_start(q, skrr, process, g_tab[skrr->op].numb_of_arg)))
			return (0);
		address = get_address(q, skrr, process, 0, 0);
		load_into(address, process, skrr, 2);
		process->pc += skrr->chmp->offset + 2;
		ft_printf("ldi\tcurrent_cycles: %d\npc: %d\n", process->current_cycles,
				  process->pc);
	}
	return (1);
}