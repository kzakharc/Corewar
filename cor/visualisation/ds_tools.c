/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 21:04:54 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/10/21 21:11:55 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void	hints(t_skrr *skrr)
{
	mvwaddstr(skrr->vis->menu, 55, 3, "Keymap:");
	mvwaddstr(skrr->vis->menu, 57, 3, "[space] - pause/continue");
	mvwaddstr(skrr->vis->menu, 58, 3, "[s] - next cycle");
	mvwaddstr(skrr->vis->menu, 59, 3, "[q] - decrease Cycles/second limit by 10");
	mvwaddstr(skrr->vis->menu, 60, 3, "[e] - increase Cycles/second limit by 1");
	mvwaddstr(skrr->vis->menu, 61, 3, "[1] - set cycles/second to 50");
	mvwaddstr(skrr->vis->menu, 62, 3, "[2] - set cycles/second to 100");
	mvwaddstr(skrr->vis->menu, 63, 3, "[3] - set cycles/second to 500");
	mvwaddstr(skrr->vis->menu, 64, 3, "[4] - set cycles/second to 2000");
	mvwaddstr(skrr->vis->menu, 65, 3, "[5] - set cycles/second to 4000");
}

void	printwinner(t_skrr *skrr, char *name, int id)
{
	int c;

	c = -1;
	wattrset(skrr->vis->menu, COLOR_PAIR(26) | A_BOLD);
	mvwprintw(skrr->vis->menu, 25 + (skrr->max_player * 4), 3, "The winner is"\
	": ");
	wattron(skrr->vis->menu, COLOR_PAIR(champ_color(skrr, id)));
	mvwprintw(skrr->vis->menu, 25 + (skrr->max_player * 4), 19, "%s", name);
	wrefresh(skrr->vis->menu);
	while (c == -1)
	{
		mvwprintw(skrr->vis->menu, 27 + (skrr->max_player * 4), 3, "         "\
		"            ");
		wrefresh(skrr->vis->menu);
		napms(500);
		wattrset(skrr->vis->menu, COLOR_PAIR(26) | A_BOLD);
		mvwprintw(skrr->vis->menu, 27 + (skrr->max_player * 4), 3, "Press any"\
		" key to exit");
		wrefresh(skrr->vis->menu);
		napms(500);
		c = wgetch(skrr->vis->menu);
	}
	endwin();
}

void	visualize_init(t_skrr *skrr)
{
	init_visualisation(skrr);
	start_color();
	skrr->vis->code = newwin(68, 254 - 57, 0, 0);
	skrr->vis->menu = newwin(68, 57, 0, 254 - 57);
	keypad(skrr->vis->code, TRUE);
	nodelay(skrr->vis->menu, TRUE);
	printmargins(skrr->vis->code, skrr->vis->menu, 254, 68);
	menufields(skrr->vis->menu, skrr);
	wrefresh(skrr->vis->menu);
	wrefresh(skrr->vis->code);
}

/*
** 5 - champ 5
** 6 - champ 6
** 7 - champ 7
** 8 - champ 8
** 15 - live proc champ 5
** 16 - live proc champ 6
** 17 - live proc champ 7
** 18 - live proc champ 8
*/

void	init_add_players_colors(void)
{
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_YELLOW, COLOR_BLACK);
	init_pair(7, COLOR_GREEN, COLOR_BLACK);
	init_pair(8, COLOR_BLUE, COLOR_BLACK);
	init_pair(15, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(16, COLOR_WHITE, COLOR_YELLOW);
	init_pair(17, COLOR_WHITE, COLOR_GREEN);
	init_pair(18, COLOR_WHITE, COLOR_BLUE);
}

/*
** 27 - grey map cells
** 1 - champ 1
** 2 - champ 2
** 3 - champ 3
** 4 - champ 4
** 25 - margins color
** 26 - text in menu
** 28 - testing highlighting in map
** 11 - live proc champ 1
** 12 - live proc champ 2
** 13 - live proc champ 3
** 14 - live proc champ 4
*/

void	init_visualisation(t_skrr *skrr)
{
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	start_color();
	init_pair(27, COLOR_BLACK, COLOR_BLACK);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(25, COLOR_CYAN, COLOR_BLACK);
	init_pair(26, COLOR_WHITE, COLOR_BLACK);
	init_pair(28, COLOR_WHITE, COLOR_CYAN);
	init_pair(29, 8, COLOR_BLACK);
	init_pair(11, COLOR_WHITE, COLOR_GREEN);
	init_pair(12, COLOR_WHITE, COLOR_BLUE);
	init_pair(13, COLOR_WHITE, COLOR_RED);
	init_pair(14, COLOR_WHITE, COLOR_CYAN);
	if (skrr->max_player > 4)
		init_add_players_colors();
	skrr->vis->cycles = 50;
	skrr->vis->highl = NULL;
	skrr->vis->live = NULL;
}
