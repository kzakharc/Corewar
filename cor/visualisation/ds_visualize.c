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
	mvwaddstr(menu, 10, 2, "Player -n :");
	mvwaddstr(menu, 12, 4, "Last live :");
	mvwaddstr(menu, 12, 4, "Lives in current period :");
	mvwaddstr(menu, 14, 2, "Live breakdown for current period :");
	wattron(menu, COLOR_PAIR(0));
	mvwaddstr(menu, 15, 2, "[--------------------------------------------------]");
	wattron(menu, COLOR_PAIR(6));
	mvwaddstr(menu, 17, 2, "Live breakdown for last period :");
	wattron(menu, COLOR_PAIR(0));
	mvwaddstr(menu, 18, 2, "[--------------------------------------------------]");
	wattron(menu, COLOR_PAIR(6));
	mvwaddstr(menu, 20, 2, "CYCLE_TO_DIE :");
	mvwaddstr(menu, 22, 2, "CYCLE_DELTA :");
	mvwaddstr(menu, 24, 2, "NBR_LIVE :");
	mvwaddstr(menu, 26, 2, "MAX_CHECKS :");
}

void	printdata(WINDOW *menu, t_skrr *skrr, t_chmp *chmp)
{
	mvwprintw(menu, 7, 10, "%d", g_cycles);
	mvwprintw(menu, 20, 17, "%d", skrr->cycle_to_die);
	mvwprintw(menu, 22, 16, "%d", CYCLE_DELTA);
	mvwprintw(menu, 24, 13, "%d", NBR_LIVE);
	mvwprintw(menu, 26, 15, "%d", skrr->max_checks);
	mvwprintw(menu, 4, 24, "%d ", skrr->vis->cycles);
	mvwprintw(menu, 9, 16, "%d", skrr->process_count);

}

int		findprocess(t_skrr *skrr, int pc)
{
	t_proc *tmp;

	tmp = skrr->process;
	while (tmp != NULL)
	{
		if (tmp->pc == pc)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		del_highl(t_skrr *skrr, int id)
{
	t_highl *current;
	t_highl *prev;

	prev = NULL;
	current = skrr->vis->highl;
	if (current->id == id)
	{
		skrr->vis->highl = current->next;
		free(current);
		return (1);
	}
	while (current != NULL)
	{
		if (current->id == id)
		{
			prev->next = current->next;
			free(current);
			return (1);
		}
		prev = current;
		current = current->next;
	}
	return (-1);
}

void	add_to_highl(t_skrr *skrr, int id)
{
	t_highl *newnode;

	newnode = (t_highl*)malloc(sizeof(t_highl));
	newnode->id = id;
	newnode->cycle = g_cycles + 100;
	newnode->next = skrr->vis->highl;
	skrr->vis->highl = newnode;
}

int		highlight(t_skrr *skrr, int id)
{
	t_highl *tmp;

	tmp = skrr->vis->highl;
	while (tmp != NULL)
	{
		if (tmp->id == id)
		{
			if (tmp->cycle == g_cycles)
			{
				skrr->mapid[skrr->i] /= 10;
				del_highl(skrr, id);
			}
			wattrset(skrr->vis->code, COLOR_PAIR(skrr->mapid[skrr->i] / 10));
			wattron(skrr->vis->code, A_BOLD);
			return (0);
		}
		tmp = tmp->next;
	}
	wattrset(skrr->vis->code, COLOR_PAIR(skrr->mapid[skrr->i] / 10));
	wattron(skrr->vis->code, A_BOLD);
	add_to_highl(skrr, id);
	return (1);
}

void printmem(t_skrr *skrr)
{
	int y;
	int x;
	int i;

	x = 2;
	y = 3;
	skrr->i = 0;
	i = 0;
	while (skrr->i < MEM_SIZE)
	{
		while (i < 64)
		{
			if (findprocess(skrr, skrr->i) == 1)
			{
				wattrset(skrr->vis->code, COLOR_PAIR(skrr->mapid[skrr->i]));
				wattron(skrr->vis->code, A_REVERSE);
				if (skrr->mapid[skrr->i] > 9)
					highlight(skrr, skrr->i);
				mvwprintw(skrr->vis->code, y, x, "%hh.2x", skrr->map[skrr->i++]);
				wattroff(skrr->vis->code, A_REVERSE);
				wattrset(skrr->vis->code, COLOR_PAIR(0));
				mvwprintw(skrr->vis->code, y, x + 2, " ");
			}
			else
			{
				if (skrr->mapid[skrr->i] == 0)
				{
					wattrset(skrr->vis->code, COLOR_PAIR(7));
					wattron(skrr->vis->code, A_BOLD);
				}
				else
				{
					wattrset(skrr->vis->code, COLOR_PAIR(skrr->mapid[skrr->i]));
					wattroff(skrr->vis->code, A_BOLD);
					if (skrr->mapid[skrr->i] > 9)
						highlight(skrr, skrr->i);
				}
				mvwprintw(skrr->vis->code, y, x, "%hh.2x ", skrr->map[skrr->i++]);
			}
			x = x + 4;
			i++;
		}
		y++;
		x = 2;
		i = 0;
	}
}

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
	skrr->vis->sleep = 16000;
	skrr->vis->cycles = 50;
	skrr->vis->highl = NULL;
}

void	visualize_init(t_skrr *skrr)
{
	int	width;
	int	height;

	init_visualisation(skrr);
	getmaxyx(stdscr, height, width);
	start_color();
	skrr->vis->code = newwin(height, width - 70, 0, 0);
	skrr->vis->menu = newwin(height, 70, 0, width - 70);
	keypad(skrr->vis->code, TRUE);
	nodelay(skrr->vis->menu, TRUE); //no to wait for the wgetch
	printmargins(skrr->vis->code, skrr->vis->menu, width, height);
	menufields(skrr->vis->menu);
	wrefresh(skrr->vis->menu);
	wrefresh(skrr->vis->code);
}

void	cycles_limit(int c, t_skrr *skrr)
{
	if (c == 113 && skrr->vis->cycles > 1)
		skrr->vis->cycles -= (skrr->vis->cycles > 10) ? 10 : 1;
	if (c == 101)
		skrr->vis->cycles += 1;
	mvwprintw(skrr->vis->menu, 4, 24, "%d ", skrr->vis->cycles);
	wrefresh(skrr->vis->menu);
}

void	visualize(t_skrr *skrr, t_chmp *chmp)
{
	int c;

	printdata(skrr->vis->menu, skrr, chmp);
	printmem(skrr);
	wrefresh(skrr->vis->code);
	wrefresh(skrr->vis->menu);
	napms(1000 / skrr->vis->cycles);
	c = wgetch(skrr->vis->menu);
	if (c == 32 || c == 115 || g_cycles == 0 || skrr->vis->c == 1)
	{
		skrr->vis->c = (c == 115) ? 1 : 0;
		c = 0;
		while (c != 32 && c != 115)
		{
			c = wgetch(skrr->vis->code);
			cycles_limit(c, skrr);
			if (c == 115)
				skrr->vis->c = 1;
		}
	}
	cycles_limit(c, skrr);
	wrefresh(skrr->vis->menu);
}