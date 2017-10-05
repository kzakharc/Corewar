/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:39:57 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/02 18:39:57 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../virtual_machine/virtualm.h"

int 	ld_instr(t_skrr *skrr, t_chmp *chmp, int op)
{
	unsigned char 	*q;
	int 			address;
	int 			reg;

	if ((skrr->process->current_cycles != 0) &&
			(skrr->process->current_cycles) % (g_tab[skrr->op].cycles) == 0)
	{
		address = 0;
		if (!(q = malloc(sizeof(unsigned char) * g_tab[op].numb_of_arg)))
			exit(0);
		if (!(same_start(q, skrr, op, g_tab[op].numb_of_arg)))
			return (0);
		if (q[0] == T_IND && (skrr->process->tmp_pc += 1))
			address = ind_param(skrr, &skrr->map[skrr->process->tmp_pc], 0, 4);
		else if (q[0] == T_DIR && (skrr->process->tmp_pc += 1) &&
				 (chmp->offset += 2))
			address = dir_param(skrr, &skrr->map[skrr->process->tmp_pc], g_tab[op].dir_size);
		if (q[1] == T_REG && (skrr->process->tmp_pc += 1)) {
			if (!(reg = reg_param(skrr, &skrr->map[skrr->process->tmp_pc], 2)) &&
				(g_err) && !(g_err = 0))
				return (0);
			skrr->process->registry[reg] = (unsigned int)address;
		}
		skrr->process->carry = 1;                            // TODO don't know how its works
		skrr->process->pc += chmp->offset + 2;
		ft_printf("ld\tcurrent_cycles: %d\npc: %d\n", skrr->process->current_cycles, skrr->process->pc);
	}
	return (1);
}
