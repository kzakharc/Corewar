/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:39:31 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/02 18:39:32 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int 	aff_instr(t_skrr *skrr, t_proc *process)
{
	unsigned char print_it;

	if ((process->waiting_cycles) == (g_tab[skrr->op].cycles))
	{
		process->tmp_pc = process->pc + 1;
		process->waiting_cycles = 0;
		print_it = (unsigned char)reg_param(skrr, process, 1);
		skrr->flag_a == 1 ? ft_printf("Aff: %c", (print_it % 256)) : 0;
	}
	return (1);
}