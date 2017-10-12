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

#include "../../corewar.h"

/*
** TODO can move 'exit (0)' to botton of the func and delete '{}'
*/

void	chk_open(t_skrr *skrr, char **argv, int i, int flag)
{
	if (flag == 0)
		ft_printf("Too many champions! (Max %d)\n", MAX_PLAYERS);
	else if (flag == 1)
	{
		skrr->fd = open(argv[i], O_RDONLY);
		if (skrr->fd < 0)
		{
			ft_printf("Can't read source file"RED" %s "RESET"\n", argv[i]);
			close(skrr->fd) < 0 ? exit(0) : 0;
			exit(flag);
		}
	}
	else if (flag == 2)
		ft_printf("Error: File"RED" %s "RESET"has an invalid header\n", *argv);
	else if (flag == 3)
		ft_printf("Error:"RED" %s "RESET"is a directory\n", *argv);
	else if (flag == 4)
		ft_printf(""RED"Error:"RESET" Please enter a player number from 1 to"
	" %i\n", skrr->max_player);
	else if (flag == 5)
		ft_printf(""RED"Error:"RESET" You typed too many flags "GRN"\"-n\""
	""RESET"\n");
	else if (flag == 6)
		ft_printf(""RED"Error:"RESET" You typed wrong player number\n");
	(flag != 1) ? exit(flag) : 0;
}

void	instr_err(int op)
{
	ft_printf(MAG"Warning:"RESET " You changed number of args in");
	(op == 0) ? ft_printf(" %s :(\n", g_tab[op].name) : 0;
	(op == 1) ? ft_printf(" %s :(\n", g_tab[op].name) : 0;
	(op == 2) ? ft_printf(" %s :(\n", g_tab[op].name) : 0;
	(op == 3) ? ft_printf(" %s :(\n", g_tab[op].name) : 0;
	(op == 4) ? ft_printf(" %s :(\n", g_tab[op].name) : 0;
	(op == 5) ? ft_printf(" %s :(\n", g_tab[op].name) : 0;
	(op == 6) ? ft_printf(" %s :(\n", g_tab[op].name) : 0;
	(op == 7) ? ft_printf(" %s :(\n", g_tab[op].name) : 0;
	(op == 8) ? ft_printf(" %s :(\n", g_tab[op].name) : 0;
	(op == 9) ? ft_printf(" %s :(\n", g_tab[op].name) : 0;
	(op == 10) ? ft_printf(" %s :(\n", g_tab[op].name) : 0;
	(op == 11) ? ft_printf(" %s :(\n", g_tab[op].name) : 0;
	(op == 12) ? ft_printf(" %s :(\n", g_tab[op].name) : 0;
	(op == 13) ? ft_printf(" %s :(\n", g_tab[op].name) : 0;
	(op == 14) ? ft_printf(" %s :(\n", g_tab[op].name) : 0;
	(op == 15) ? ft_printf(" %s :(\n", g_tab[op].name) : 0;
	exit(op);
}

void	sizes_err(char *name, int flag)
{
	(flag == 1) ? ft_printf(MAG"Warning:"RESET " %s != 1\n", name) : 0;
	(flag == 2) ? ft_printf(MAG"Warning:"RESET " %s != 2 or 4\n", name) : 0;
	(flag == 3) ? ft_printf(MAG"Warning:"RESET " %s != 2\n", name) : 0;
	exit(flag);
}

void	usage_e(void)
{
	ft_printf(YEL"Usage: ./corewar [-dump N -n N -v -a]\n"RESET
	"    -a        : Prints output from \"aff\" "
	"(Default is to hide it)\n"
	"    -n N      : Sets the number of the next player\n"
	CYN"###################### "YEL"TEXT OUTPUT MODE"RESET" "
	""CYN"########################\n"RESET
	"    -dump N   : Dumps memory after N cycles then exits\n"
	CYN"#################### "YEL"NCURSES OUTPUT MODE"RESET" "
	""CYN"#######################\n"RESET
	"    -v        : Ncurses output mode\n"
	CYN"#####################################################"
	"###########\n"RESET);
	exit(1);
}
