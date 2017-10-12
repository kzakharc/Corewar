//
// Created by Dmytrii Spyrydonov on 9/24/17.
//

#include "../../corewar.h"

void	printmargins(WINDOW *code, WINDOW *menu, int width, int height)
{
	int i;

	i = 0;
	wattron(code, COLOR_PAIR(5));
	wattron(menu, COLOR_PAIR(5));
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
	wattroff(code, COLOR_PAIR(5));
	wattroff(menu, COLOR_PAIR(5));
}

void	menufields(WINDOW *menu)
{
	wattron(menu, COLOR_PAIR(6));
	wattron(menu, A_BOLD);
	mvwaddstr(menu, 2, 2, "** RUNNING **");
	mvwaddstr(menu, 4, 2, "Cycles/second limit :");
	mvwaddstr(menu, 7, 2, "Cycle :");
	mvwaddstr(menu, 9, 2, "Processes :");
	mvwaddstr(menu, 9, 2, "Player -n :");
	mvwaddstr(menu, 10, 4, "Last live :");
	mvwaddstr(menu, 11, 4, "Lives in current period :");
	mvwaddstr(menu, 13, 2, "Live breakdown for current period :");
	wattron(menu, COLOR_PAIR(0));
	mvwaddstr(menu, 14, 2, "[--------------------------------------------------]");
	wattron(menu, COLOR_PAIR(6));
	mvwaddstr(menu, 16, 2, "Live breakdown for last period :");
	wattron(menu, COLOR_PAIR(0));
	mvwaddstr(menu, 17, 2, "[--------------------------------------------------]");
	wattron(menu, COLOR_PAIR(6));
	mvwaddstr(menu, 19, 2, "CYCLE_TO_DIE :");
	mvwaddstr(menu, 21, 2, "CYCLE_DELTA :");
	mvwaddstr(menu, 23, 2, "NBR_LIVE :");
	mvwaddstr(menu, 25, 2, "MAX_CHECKS :");
}

void	printdata(WINDOW *menu, t_skrr *skrr, t_chmp *chmp)
{
	mvwprintw(menu, 7, 10, "%d", g_cycles);
	mvwprintw(menu, 19, 17, "%d", skrr->cycle_to_die);
	mvwprintw(menu, 21, 16, "%d", CYCLE_DELTA);
	mvwprintw(menu, 23, 13, "%d", skrr->nbr_live);
	mvwprintw(menu, 25, 15, "%d", skrr->max_checks);
}

int		findprocess(t_skrr *skrr, int pc)
{
	t_proc *tmp;

	tmp = skrr->process;
	while (tmp != NULL)
	{
		if (tmp->pc == pc)
			return (1);
		else
			tmp = tmp->next;
	}
	return (0);
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
	wattron(code, A_BOLD);
	while (skrr->i < MEM_SIZE)
	{
		while (i < 64)
		{
			if (findprocess(skrr, skrr->i) == 1)
			{
				wattrset(code, COLOR_PAIR(8));
				mvwprintw(code, y, x, "%hh.2x", skrr->map[skrr->i++]);
				wattrset(code, COLOR_PAIR(0));
				mvwprintw(code, y, x + 2, " ");
			}
			else
			{
				wattrset(code, COLOR_PAIR(0));
				mvwprintw(code, y, x, "%hh.2x ", skrr->map[skrr->i++]);
			}
			x = x + 4;
			i++;
		}
		y++;
		x = 2;
		i = 0;
	}
}

void	init_colors()
{
	start_color();
	init_pair(0, COLOR_BLACK, COLOR_BLACK);//grey map cells
	init_pair(1 ,COLOR_GREEN, COLOR_BLACK);//champ 1
	init_pair(2 ,COLOR_BLUE, COLOR_BLACK);//champ 2
	init_pair(3, COLOR_RED, COLOR_BLACK);//champ 3
	init_pair(4, COLOR_CYAN, COLOR_BLACK);//champ 4
	init_pair(5, COLOR_CYAN, COLOR_BLACK);//margins color
	init_pair(6, COLOR_WHITE, COLOR_BLACK);//text in menu
	init_pair(8, COLOR_WHITE, COLOR_CYAN);//testing highlighting in map
}
void	visualize_init(t_skrr *skrr)
{
	initscr();
	cbreak();
	init_colors();
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
	wgetch(skrr->vis->menu);
}