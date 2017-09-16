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

	if (!(q = malloc(sizeof(unsigned char) * g_tab[op].numb_of_arg)))
		exit (0);
//	chmp->tmp_PC = chmp->process->PC + 1;
//	if (&skrr->map[chmp->tmp_PC] == NULL)
//		return (0);
//	(!(q = malloc(sizeof(unsigned char) * g_tab[op].numb_of_arg))) ? exit (0) : 0;
//	skrr->i = 0;
//	(g_tab[op].numb_of_arg != 3) ? instr_err(op) : 0;
//	while (skrr->i < g_tab[op].numb_of_arg)
//		q[skrr->i++] = arg_types(skrr, chmp, chmp->tmp_PC);
	if (!(same_start(q, skrr, op, g_tab[op].numb_of_arg)))
		return (0);
	if ((!from_reg(q, chmp, skrr, 0) && (g_err) && !(g_err = 0)))
		return (0);
	address = get_address(q, skrr, 0, 1);
	load_into(address, chmp, skrr, 1);
	skrr->process->pc+= chmp->offset + 2;
	return (1);
}
