/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_ft_instr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 18:34:54 by yzakharc          #+#    #+#             */
/*   Updated: 2017/10/05 18:34:55 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../virtual_machine/virtualm.h"

int 	determination_of_action(unsigned char *q, t_skrr *skrr, int l, int key)
{
	int		result;
	short	i;

	result = 0;
	i = 0;
	if (key == 1 && (skrr->process->tmp_pc += 1))
	{
		result = reg_param(skrr, &skrr->map[skrr->process->tmp_pc], 1);
		skrr->process->tmp_pc += 1;
		result += reg_param(skrr, &skrr->map[skrr->process->tmp_pc], 1);
	}
	else if (key == 2 && (skrr->process->tmp_pc += 1))
	{
		result = reg_param(skrr, &skrr->map[skrr->process->tmp_pc], 1);
		skrr->process->tmp_pc += 1;
		result -= reg_param(skrr, &skrr->map[skrr->process->tmp_pc], 1);
	}
	(l == 0) ? result = (skrr->process->pc + (result % IDX_MOD)) : 0;
	return (result);

}