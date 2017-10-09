/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:40:54 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/02 18:40:56 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../virtual_machine/virtualm.h"

int 	and_instr(t_skrr *skrr, t_proc *process)
{
	unsigned char	*q;
	int 			address;
	int 			reg;

	if (!(q = malloc(sizeof(unsigned char) * g_tab[skrr->op].numb_of_arg)))
		exit(0);
	if (!(same_start(q, skrr, process, g_tab[skrr->op].numb_of_arg)))
		return (0);
	address = determination_of_action(q, skrr, 0, 3, process);
	process->tmp_pc += 1;
	reg = reg_param(skrr, process, 2);
	process->registry[reg] = (unsigned int) address;
	process->carry = 1;
	return (1);
}