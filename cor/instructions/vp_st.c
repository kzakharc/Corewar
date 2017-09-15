/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:40:14 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/02 18:40:14 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../virtual_machine/virtualm.h"

int 	st_instr(t_skrr *skrr, t_chmp *chmp, int op)
{
	unsigned char	*q;
	int 			address;

	if (!(q = malloc(sizeof(unsigned char) * g_tab[op].numb_of_arg)))
		exit (0);
	if (!(same_start(q, skrr, op, g_tab[op].numb_of_arg)))
		return (0);
	if (!from_reg(q, chmp, skrr, 0)  && (g_err) && !(g_err = 0))
		return (0);
	address = simple_address(q, skrr, chmp, 1);
	(q[1] == T_IND) ? load_into(address, chmp, skrr, 1) : 0;
	(q[1] == T_REG) ? (skrr->process->registry[address] = chmp->reg_value) : 0;
	skrr->process->pc += chmp->offset + 2;
	return (1);
}
