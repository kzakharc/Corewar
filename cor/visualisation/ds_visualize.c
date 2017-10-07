//
// Created by Dmytrii Spyrydonov on 9/24/17.
//

#include "../../corewar.h"

void printmargins(WINDOW *code, WINDOW *menu, int width, int height)
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
	attroff(1);
}

int main()
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
	wrefresh(code);
	wrefresh(menu);
	wgetch(code);
	endwin();
	return (0);
}