//
// Created by Dmytrii Spyrydonov on 9/24/17.
//

#include "../virtual_machine/virtualm.h"

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
		mvwaddch(code, i, width - 61, ' ' | A_REVERSE);
		mvwaddch(menu, i++, 59, ' ' | A_REVERSE);
	}
	i = 0;
	while (i < width - 61)
	{
		mvwaddch(code, 0, i, ' ' | A_REVERSE);
		mvwaddch(code, height - 1, i++, ' ' | A_REVERSE);
	}
	i = 0;
	while (i < 61)
	{
		mvwaddch(menu, 0, i, ' ' | A_REVERSE);
		mvwaddch(menu, height - 1, i++, ' ' | A_REVERSE);
	}
	wattroff(code, COLOR_PAIR(1));
	wattroff(menu, COLOR_PAIR(1));
}

void	menutext(WINDOW *menu)
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

void	visualize(t_skrr *skrr, t_chmp *chmp)
{
	initscr();
	int	startx, starty, width, height;
	getmaxyx(stdscr, height, width);
	start_color();
	WINDOW *code;
	WINDOW *menu;
	code = newwin(height, width - 60, 0, 0);
	menu = newwin(height, 60, 0, width - 60);
//	box(code, 0, 0);
//	box(menu, 0, 0);
	printmargins(code, menu, width, height);
	menutext(menu);
	wrefresh(code);
	wrefresh(menu);
	wgetch(code);
	endwin();
}