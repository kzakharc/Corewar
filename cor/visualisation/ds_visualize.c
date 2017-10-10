//
// Created by Dmytrii Spyrydonov on 9/24/17.
//

#include "../../corewar.h"

void	printmargins(WINDOW *code, WINDOW *menu, int width, int height)
{
	int i;

	i = 0;
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	wattron(code, COLOR_PAIR(1));
	wattron(menu, COLOR_PAIR(1));
	while (i < height)
	{
		mvwaddch(code, i, 0, ' ' | A_REVERSE);
		mvwaddch(code, i, width - 71, ' ' | A_REVERSE);
		mvwaddch(menu, i++, 69, ' ' | A_REVERSE);
	}
	i = 0;
	while (i < width - 71)
	{
		mvwaddch(code, 0, i, ' ' | A_REVERSE);
		mvwaddch(code, height - 1, i++, ' ' | A_REVERSE);
	}
	i = 0;
	while (i < 71)
	{
		mvwaddch(menu, 0, i, ' ' | A_REVERSE);
		mvwaddch(menu, height - 1, i++, ' ' | A_REVERSE);
	}
	wattroff(code, COLOR_PAIR(1));
	wattroff(menu, COLOR_PAIR(1));
}

void	menufields(WINDOW *menu)
{
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_BLACK, COLOR_BLACK);
	wattron(menu, COLOR_PAIR(2));
	wattron(menu, A_BOLD);
	mvwaddstr(menu, 2, 2, "** RUNNING **");
	mvwaddstr(menu, 4, 2, "Cycles/second limit :");
	mvwaddstr(menu, 7, 2, "Cycle :");
	mvwaddstr(menu, 9, 2, "Processes :");
	mvwaddstr(menu, 9, 2, "Player -n :");
	mvwaddstr(menu, 10, 4, "Last live :");
	mvwaddstr(menu, 11, 4, "Lives in current period :");
	mvwaddstr(menu, 13, 2, "Live breakdown for current period :");
	wattron(menu, COLOR_PAIR(3));
	mvwaddstr(menu, 14, 2, "[--------------------------------------------------]");
	wattron(menu, COLOR_PAIR(2));
	mvwaddstr(menu, 16, 2, "Live breakdown for last period :");
	wattron(menu, COLOR_PAIR(3));
	mvwaddstr(menu, 17, 2, "[--------------------------------------------------]");
	wattron(menu, COLOR_PAIR(2));
	mvwaddstr(menu, 19, 2, "CYCLE_TO_DIE :");
	mvwaddstr(menu, 21, 2, "CYCLE_DELTA :");
	mvwaddstr(menu, 23, 2, "NBR_LIVE :");
	mvwaddstr(menu, 25, 2, "MAX_CHECKS :");
}

void	printdata(WINDOW *menu, t_skrr *skrr, t_chmp *chmp)
{
	mvwprintw(menu, 7, 10, "%d", g_cycles);
}

void	printmem(WINDOW *code, t_skrr *skrr)
{
	int y;
	int x;
	int i;

	x = 2;
	y = 3;
	skrr->i = 0;
	i = 0;
	wattron(code, COLOR_PAIR(3));
	wattron(code, A_BOLD);
	while (skrr->i < MEM_SIZE)
	{
		while (i < 64)
		{
			mvwprintw(code, y, x, "%hh.2x ", skrr->map[skrr->i++]);
			x = x + 4;
			i++;
		}
		y++;
		x = 2;
		i = 0;
	}
}

void	visualize_init(t_skrr *skrr)
{
	initscr();
	cbreak();
	int	width, height;
	getmaxyx(stdscr, height, width);
	start_color();
	WINDOW *code;
	WINDOW *menu;
	code = newwin(height, width - 70, 0, 0);
	menu = newwin(height, 70, 0, width - 70);
	printmargins(code, menu, width, height);
	menufields(menu);
	wrefresh(menu);
	wrefresh(code);
	skrr->vis->code = code;
	skrr->vis->menu = menu;

}

void	visualize(t_skrr *skrr, t_chmp *chmp)
{
	printdata(skrr->vis->menu, skrr, chmp);
	printmem(skrr->vis->code, skrr);
	wrefresh(skrr->vis->code);
	wrefresh(skrr->vis->menu);
	usleep(10000);
}