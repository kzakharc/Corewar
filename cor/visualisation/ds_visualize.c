//
// Created by Dmytrii Spyrydonov on 9/24/17.
//

#include "../../corewar.h"

int main()
{
	initscr();
	start_color();
	WINDOW *code;
	WINDOW *menu;
	code = newwin(getmaxy(stdscr), getmaxx(stdscr) - 20, 10, 10);
	menu = newwin(getmaxy(stdscr), 20, 50, getmaxx(stdscr) - 20);
	box(code, 0, 0);
	box(menu, 0, 0);
	init_pair(1, COLOR_BLUE, COLOR_BLUE);
	wattron(code, COLOR_PAIR(1));
	wprintw(code, "****************");
	wprintw(menu, "****************");
	attroff(1);
	wgetch(code);
	wgetch(menu);
	endwin();
	return (0);
}