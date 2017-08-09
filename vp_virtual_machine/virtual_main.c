/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:12:55 by vpoltave          #+#    #+#             */
/*   Updated: 2017/08/08 15:42:25 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtualm.h"

int 	main(int argc, char **argv)
{
	int		fd;
	t_skrr	skrr;

	skrr.i = argc;
	(argc == 1) ? usage_e() : 0;
	(argc > 5) ? argc_e(argc) : 0;
	while (skrr.i > 1)
	{
		fd = open(argv[skrr.i - 1], O_RDONLY);
		skrr.j = fd;
		ft_printf("fd: %d\n", skrr.j);
		skrr.i--;
	}

	return (1);
}

void	argc_e(int argc)
{
	ft_printf("Too many champions! (Max 4) You gave me: %d\n", (argc - 1));
	exit (0);
}

void	usage_e(void)
{
	ft_printf("Usage: ./corewar [-d N -s N -v N | -b --stealth | -n "
			  "--stealth] [-a] <champion1.cor> <...>\n"
			  "    -a        : Prints output from \"aff\" (Default is to hide"
			  " it)\n");
	ft_printf(CYN"TEXT OUTPUT MODE\n"RESET);
	ft_printf("    -d N      : Dumps memory after N cycles then exits\n"
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
			  "                - 16 : Show PC movements (Except for jumps)\n");
	ft_printf(CYN"BINARY OUTPUT MODE\n"RESET);
	ft_printf("    -b        : Binary output mode for corewar.42.fr\n"
			  "    --stealth : Hides the real contents of the memory\n");
	ft_printf(CYN"NCURSES OUTPUT MODE\n"RESET);
	ft_printf("    -n        : Ncurses output mode\n");
	ft_printf("    --stealth : Hides the real contents of the "
			  "memory\n"
			  "############################################################\n");
}
