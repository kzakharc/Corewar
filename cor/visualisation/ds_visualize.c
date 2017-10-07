//
// Created by Dmytrii Spyrydonov on 9/24/17.
//

#include "../../corewar.h"

int main()
{
	initscr();
	int	startx, starty, width, height;
	getmaxyx(stdscr, height, width);
	start_color();
	WINDOW *code;
	WINDOW *menu;
	code = newwin(height, width - 50, 0, 0);
	menu = newwin(height, 49, 0, width - 49);
	box(code, 0, 0);
	box(menu, 0, 0);
	wrefresh(code);
	wrefresh(menu);
	wgetch(code);
	endwin();
	return (0);
}