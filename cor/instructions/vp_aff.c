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

	skrr->process->tmp_pc = skrr->process->pc + 2;
	print_it = (unsigned char)reg_param(skrr, process, 1);
	ft_printf("%c", (print_it % 256));
	return (1);
}