//
// Created by Dmytrii Spyrydonov on 10/14/17.
//

#include "../../corewar.h"

void 	printwinner(t_skrr *skrr, char *name, int id)
{
	int c;

	c = -1;
	wattrset(skrr->vis->menu, COLOR_PAIR(26) | A_BOLD);
	mvwprintw(skrr->vis->menu, 25 + (skrr->max_player * 4) , 3, "The winner is"\
	": ");
	wattron(skrr->vis->menu, COLOR_PAIR(champ_color(skrr, id)));
	mvwprintw(skrr->vis->menu, 25 + (skrr->max_player * 4) , 19, "%s", name);
	wrefresh(skrr->vis->menu);
	while (c == -1)
	{
		mvwprintw(skrr->vis->menu, 27 + (skrr->max_player * 4) , 3, "         "\
		"            ");
		wrefresh(skrr->vis->menu);
		napms(500);
		wattrset(skrr->vis->menu, COLOR_PAIR(26) | A_BOLD);
		mvwprintw(skrr->vis->menu, 27 + (skrr->max_player * 4) , 3, "Press any"\
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
	nodelay(skrr->vis->menu, TRUE); //no to wait for the wgetch
	printmargins(skrr->vis->code, skrr->vis->menu, 254, 68);
	menufields(skrr->vis->menu, skrr);
	wrefresh(skrr->vis->menu);
	wrefresh(skrr->vis->code);
}

void	init_add_players_colors()
{
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);//champ 5
	init_pair(6, COLOR_YELLOW, COLOR_BLACK);//champ 6
	init_pair(7, COLOR_GREEN, COLOR_BLACK);//champ 7
	init_pair(8, COLOR_BLUE, COLOR_BLACK);//champ 8
	init_pair(15, COLOR_WHITE, COLOR_MAGENTA);//live proc champ 5
	init_pair(16, COLOR_WHITE, COLOR_YELLOW);//live proc champ 6
	init_pair(17, COLOR_WHITE, COLOR_GREEN);//live proc champ 7
	init_pair(18, COLOR_WHITE, COLOR_BLUE);//live proc champ 8
}

void	init_visualisation(t_skrr *skrr)
{
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	start_color();
	init_pair(27, COLOR_BLACK, COLOR_BLACK);//grey map cells
	init_pair(1 ,COLOR_GREEN, COLOR_BLACK);//champ 1
	init_pair(2 ,COLOR_BLUE, COLOR_BLACK);//champ 2
	init_pair(3, COLOR_RED, COLOR_BLACK);//champ 3
	init_pair(4, COLOR_CYAN, COLOR_BLACK);//champ 4
	init_pair(25, COLOR_CYAN, COLOR_BLACK);//margins color
	init_pair(26, COLOR_WHITE, COLOR_BLACK);//text in menu
	init_pair(28, COLOR_WHITE, COLOR_CYAN);//testing highlighting in map
	init_pair(11, COLOR_WHITE, COLOR_GREEN);//live proc champ 1;
	init_pair(12, COLOR_WHITE, COLOR_BLUE);//live proc champ 2;
	init_pair(13, COLOR_WHITE, COLOR_RED);//live proc champ 3;
	init_pair(14, COLOR_WHITE, COLOR_CYAN);//live proc champ 4
	if (skrr->max_player > 4)
		init_add_players_colors();
	skrr->vis->cycles = 50;
	skrr->vis->highl = NULL;
	skrr->vis->live = NULL;
}