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

	chmp->tmp_PC = chmp->PC + 1;
	if (&skrr->map[chmp->tmp_PC] == NULL)
		return (0);
	(!(q = malloc(sizeof(unsigned int) * 3))) ? exit (0) : 0;
	skrr->i = 0;
	if (g_tab[op].numb_of_arg != 2)
		instr_err(op);
	while (skrr->i < 3)
		q[skrr->i++] = arg_types(skrr, chmp, chmp->tmp_PC);
	if (!from_reg(q, chmp, skrr, 0) && !(skrr->err = 0))
		return (0);
	address = simple_address(q, skrr, chmp, 1);
	(q[1] == T_IND) ? load_into(address, chmp, skrr, 1) : 0;
	(q[1] == T_REG) ? (chmp->registry[address] = chmp->reg_value) : 0;
	chmp->PC += chmp->offset + 2;
	ft_printf(" <- ST from reg (with pc and mod %d)\n", address);
	return (1);
}
