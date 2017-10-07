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

int 	and_instr(t_skrr *skrr, t_chmp *chmp, int op)
{
	unsigned char	*q;
	int 			address;
	int 			reg;

	if (!(q = malloc(sizeof(unsigned char) * g_tab[op].numb_of_arg)))
		exit(0);
	if (!(same_start(q, skrr, op, g_tab[op].numb_of_arg)))
		return (0);
	address = determination_of_action(q, skrr, 0, 3);
	return (1);

}
