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
	if (op == 0)
		ft_printf(RED"You changed number of args in %s :(\n", g_tab[op].name);
	else if (op == 2)
		ft_printf(RED"You changed number of args in %s :(\n", g_tab[op].name);
	else if (op == 10)
		ft_printf(RED"You changed number of args in %s :(\n", g_tab[op].name);
	else if (op == 11)
		ft_printf(RED"You changed number of args in %s :(\n", g_tab[op].name);
	exit (op);
}

void	sizes_err(char *name, int flag)
{
	(flag == 1) ? ft_printf("%s != 1\n", name) : 0;
	(flag == 2) ? ft_printf("%s != 2 or 4\n", name) : 0;
	(flag == 3) ? ft_printf("%s != 2\n", name) : 0;
	exit (flag);
}