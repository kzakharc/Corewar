/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:38:18 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/02 18:38:18 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../virtual_machine/virtualm.h"

int 	lld_instr(t_skrr *skrr, t_chmp *chmp, int op)
{
	unsigned char 	*q;
	int 			address;
	int 			reg;

	address = 0;
	chmp->tmp_PC = chmp->process->PC + 1;
	if (&skrr->map[chmp->tmp_PC] == NULL)
		return (0);
	(!(q = malloc(sizeof(unsigned int) * 3))) ? exit(0) : 0;
	skrr->i = 0;
	(g_tab[op].numb_of_arg != 2) ? instr_err(op) : 0;
	while (skrr->i < 3)
		q[skrr->i++] = arg_types(skrr, chmp, chmp->tmp_PC);
	if (q[0] == T_IND && (chmp->tmp_PC += 1))
		address = ind_param(skrr, &skrr->map[chmp->tmp_PC], 1, 2);
	else if (q[0] == T_DIR && (chmp->tmp_PC += 1) && (chmp->offset += 2))
		address = dir_param(skrr, &skrr->map[chmp->tmp_PC], g_tab[op].dir_size);
	if (q[1] == T_REG && (chmp->tmp_PC += 1))
	{
		reg = reg_param(skrr, &skrr->map[skrr->chmp->tmp_PC], 2);
		chmp->process->registry[reg] = (unsigned int)address;
	}
	chmp->process->carry = 1; 							// TODO don't know how its works
	chmp->process->PC += chmp->offset + 2;
	return (1);
}