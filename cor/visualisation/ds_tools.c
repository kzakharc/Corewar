//
// Created by Dmytrii Spyrydonov on 10/14/17.
//

#include "../../corewar.h"

void init_visualisation(t_skrr *skrr)
{
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	start_color();
	init_pair(7, COLOR_BLACK, COLOR_BLACK);//grey map cells
	init_pair(1 ,COLOR_GREEN, COLOR_BLACK);//champ 1
	init_pair(2 ,COLOR_BLUE, COLOR_BLACK);//champ 2
	init_pair(3, COLOR_RED, COLOR_BLACK);//champ 3
	init_pair(4, COLOR_CYAN, COLOR_BLACK);//champ 4
	init_pair(5, COLOR_CYAN, COLOR_BLACK);//margins color
	init_pair(6, COLOR_WHITE, COLOR_BLACK);//text in menu
	init_pair(8, COLOR_WHITE, COLOR_CYAN);//testing highlighting in map
	init_pair(11, COLOR_WHITE, COLOR_GREEN);//live proc champ 1;
	init_pair(12, COLOR_WHITE, COLOR_BLUE);//live proc champ 2;
	init_pair(13, COLOR_WHITE, COLOR_RED);//live proc champ 3;
	init_pair(14, COLOR_WHITE, COLOR_CYAN);//live proc champ 4
	init_pair(9, COLOR_BLACK, COLOR_WHITE);//grey carret
	skrr->vis->cycles = 50;
	skrr->vis->highl = NULL;
	skrr->vis->live = NULL;
}