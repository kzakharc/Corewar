/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_output_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 17:31:58 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/10 17:31:59 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtualm.h"

void	instr_err(int op)
{
	if (op == 10)
		ft_printf("You changed number of args in %s :(\n", g_tab[op].name);
	else if (op == 11)
		ft_printf("You changed number of args in %s :(\n", g_tab[op].name);
	exit (op);
}
