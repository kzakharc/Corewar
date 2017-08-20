/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_virtual_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:12:55 by vpoltave          #+#    #+#             */
/*   Updated: 2017/08/16 15:49:32 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtualm.h"

void	init(t_skrr *skrr, int argc)
{
	skrr->fd = 0;
	skrr->i = (unsigned int)argc;
	skrr->n = 0;
	skrr->j = 0;
}

void	chk_open(t_skrr *skrr, char **argv, int argc, int flag)
{
	if (flag)
	{
		skrr->fd = open(argv[skrr->j], O_RDONLY);
		if (skrr->fd < 0)
		{
			ft_printf("Can't read source file"RED" %s"RESET"\n", argv[skrr->j]);
			exit (0);
		}
	}
	else
	{
		ft_printf("Too many champions! (Max 4) You gave me: %d\n", (argc - 1));
		exit (0);
	}
}

void	usage_e(void)
{
	ft_printf(YEL"Usage: ./corewar [-d N -s N -v N | -b --stealth | -n "
			  "--stealth] [-a] <champion1.cor> <...>\n"RESET
			  "    -a        : Prints output from \"aff\" (Default is to hide"
			  " it)\n"
			  CYN"TEXT OUTPUT MODE\n"RESET
			  "    -d N      : Dumps memory after N cycles then exits\n"
			  "    -s N      : Runs N cycles, dumps memory, pauses, then "
			  "repeats\n"
			  "    -v N      : Verbosity levels, can be added together to "
			  "enable several\n"
			  "                - 0 : Show only essentials\n"
			  "                - 1 : Show lives\n"
			  "                - 2 : Show cycles\n"
			  "                - 4 : Show operations (Params are NOT "
			  "litteral ...)\n"
			  "                - 8 : Show deaths\n"
			  "                - 16 : Show PC movements (Except for jumps)\n"
			  CYN"BINARY OUTPUT MODE\n"RESET
			  "    -b        : Binary output mode for corewar.42.fr\n"
			  "    --stealth : Hides the real contents of the memory\n"
			  CYN"NCURSES OUTPUT MODE\n"RESET
			  "    -n        : Ncurses output mode\n"
			  "    --stealth : Hides the real contents of the "
			  "memory\n");
}
