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
		mvwaddch(menu, i, 0, ' ' | A_REVERSE);
		mvwaddch(menu, i++, 56, ' ' | A_REVERSE);
	}
	i = 0;
	while (i < width - 57)
	{
		mvwaddch(code, 0, i, ' ' | A_REVERSE);
		mvwaddch(code, height - 1, i++, ' ' | A_REVERSE);
	}
	i = 0;
	while (i < 57)
	{
		mvwaddch(menu, 0, i, ' ' | A_REVERSE);
		mvwaddch(menu, 67, i++, ' ' | A_REVERSE);
	}
	wattroff(code, COLOR_PAIR(5));
	wattroff(menu, COLOR_PAIR(5));
}

void menufields(WINDOW *menu, t_skrr *skrr)
{
	int y;

	y = (skrr->max_player * 4);
	wattron(menu, COLOR_PAIR(6));
	wattron(menu, A_BOLD);
	mvwaddstr(menu, 4, 3, "Cycles/second limit :");
	mvwaddstr(menu, 7, 3, "Cycle :");
	mvwaddstr(menu, 9, 3, "Processes :");
	mvwaddstr(menu, 11, 3, "Player -1 :");
	mvwaddstr(menu, 12, 5, "Last live :");
	mvwaddstr(menu, 13, 5, "Lives in current period :");
	if (skrr->max_player > 1)
	{
		mvwaddstr(menu, 15, 3, "Player -2 :");
		mvwaddstr(menu, 16, 5, "Last live :");
		mvwaddstr(menu, 17, 5, "Lives in current period :");
	}
	if (skrr->max_player > 2)
	{
		mvwaddstr(menu, 19, 3, "Player -3 :");
		mvwaddstr(menu, 20, 5, "Last live :");
		mvwaddstr(menu, 21, 5, "Lives in current period :");
	}
	if (skrr->max_player > 3)
	{
		mvwaddstr(menu, 23, 3, "Player -4 :");
		mvwaddstr(menu, 24, 5, "Last live :");
		mvwaddstr(menu, 25, 5, "Lives in current period :");
	}
	mvwaddstr(menu, 11 + y, 3, "Live breakdown for current period :");
	wattron(menu, COLOR_PAIR(6));
	mvwaddstr(menu, 14 + y, 3, "Live breakdown for last period :");
	if (g_cycles < skrr->cycle_to_die)
	{
		wattron(skrr->vis->menu, COLOR_PAIR(7) | A_BOLD);
		mvwaddstr(menu, 15 + y, 3, "[--------------------------------------------------]");
	}
	wattron(menu, COLOR_PAIR(6));
	mvwaddstr(menu, 17 + y, 3, "CYCLE_TO_DIE :");
	mvwaddstr(menu, 19 + y, 3, "CYCLE_DELTA :");
	mvwaddstr(menu, 21 + y, 3, "NBR_LIVE :");
	mvwaddstr(menu, 23 + y, 3, "MAX_CHECKS :");
}

char	*find_progname(t_skrr *skrr, int id)
{
	t_chmp *tmp;

	tmp = skrr->chmp;
	while (tmp != NULL)
	{
		if (tmp->ac == id)
			return (tmp->header.prog_name);
		tmp = tmp->next;
	}
	return (NULL);
}

long	find_last_live(t_skrr *skrr, int id)
{
	t_chmp *tmp;

	tmp = skrr->chmp;
	while (tmp != NULL)
	{
		if (tmp->ac == id)
			return (tmp->last_live);
		tmp = tmp->next;
	}
	return (0);
}

int		find_live_count(t_skrr *skrr, int id)
{
	t_chmp *tmp;

	tmp = skrr->chmp;
	while (tmp != NULL)
	{
		if (tmp->ac == id)
			return (tmp->live_count);
		tmp = tmp->next;
	}
	return (0);
}

int 	champ_color(t_skrr *skrr, int id)
{
	t_chmp *tmp;

	tmp = skrr->chmp;
	while (tmp != NULL)
	{
		if (tmp->ac == id)
			return (tmp->id * -1);
		tmp = tmp->next;
	}
	return (0);
}

void	printdata(WINDOW *menu, t_skrr *skrr, t_chmp *chmp)
{
	int y;

	y = (skrr->max_player * 4);
	mvwaddstr(skrr->vis->menu, 2, 3, "** RUNNING **");
	mvwprintw(menu, 4, 25, "%d  ", skrr->vis->cycles);
	mvwprintw(menu, 9, 15, "%d", skrr->process_count);
	mvwprintw(menu, 7, 11, "%d", g_cycles);
	wattron(menu, COLOR_PAIR(champ_color(skrr, -1)));
	mvwprintw(menu, 11, 15, "%s", find_progname(skrr, -1));
	wattron(menu, COLOR_PAIR(6));
	mvwprintw(menu, 12, 37, "%ld", find_last_live(skrr, -1));
	mvwprintw(menu, 13, 37, "%d      ", find_live_count(skrr, -1));
	if (skrr->max_player > 1)
	{
		wattron(menu, COLOR_PAIR(champ_color(skrr, -2)));
		mvwprintw(menu, 15, 15, "%s", find_progname(skrr, -2));
		wattron(menu, COLOR_PAIR(6));
		mvwprintw(menu, 16, 37, "%ld", find_last_live(skrr, -2));
		mvwprintw(menu, 17, 37, "%d      ", find_live_count(skrr, -2));
	}
	if (skrr->max_player > 2)
	{
		wattron(menu, COLOR_PAIR(champ_color(skrr, -3)));
		mvwprintw(menu, 19, 15, "%s", find_progname(skrr, -3));
		wattron(menu, COLOR_PAIR(6));
		mvwprintw(menu, 20, 37, "%ld", find_last_live(skrr, -3));
		mvwprintw(menu, 21, 37, "%d      ", find_live_count(skrr, -3));
	}
	if (skrr->max_player > 3)
	{
		wattron(menu, COLOR_PAIR(champ_color(skrr, -4)));
		mvwprintw(menu, 23, 15, "%s", find_progname(skrr, -4));
		wattron(menu, COLOR_PAIR(6));
		mvwprintw(menu, 24, 37, "%ld", find_last_live(skrr, -4));
		mvwprintw(menu, 25, 37, "%d      ", find_live_count(skrr, -4));
	}
	breakdown_current(skrr, 12);
	if (g_ctd == skrr->cycle_to_die)
		breakdown_current(skrr, 15);
	wattron(menu, COLOR_PAIR(6));
	mvwprintw(menu, 17 + y, 18, "%d ", skrr->cycle_to_die);
	mvwprintw(menu, 19 + y, 17, "%d ", CYCLE_DELTA);
	mvwprintw(menu, 21 + y, 14, "%d ", NBR_LIVE);
	mvwprintw(menu, 23 + y, 16, "%d ", skrr->max_checks);
}

void breakdown_current(t_skrr *skrr, int y)
{
	t_chmp	*tmp;
	double	total;
	int 	x;
	int 	id;
	int		i;

	tmp = skrr->chmp;
	total = 0;
	x = 4;
	id = -1;
	i = 0;
	while (tmp != NULL)
	{
		total += tmp->live_count;
		tmp = tmp->next;
	}
	if (total > 0)
	{
		mvwaddch(skrr->vis->menu, y + skrr->max_player * 4, 3, '[' | COLOR_PAIR(7) | A_BOLD);
		while (id > -5)
		{
			if (find_live_count(skrr, id) > 0)
			{
				while (i < ((50 * (find_live_count(skrr, id) / total))) && x < 54)
				{
					wattron(skrr->vis->menu, COLOR_PAIR(champ_color(skrr, id)));
					mvwaddch(skrr->vis->menu, y + skrr->max_player * 4, x++, '-');
					i++;
				}
			}
			id--;
			i = 0;
		}
		wattron(skrr->vis->menu, COLOR_PAIR(7) | A_BOLD);
		mvwaddch(skrr->vis->menu, y + skrr->max_player * 4, x, ']');
	}
	else
	{
		wattron(skrr->vis->menu, COLOR_PAIR(7) | A_BOLD);
		mvwaddstr(skrr->vis->menu, 12 + + skrr->max_player * 4, 3, "[--------------------------------------------------]");
	}
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

void printmem(t_skrr *skrr)
{
	int y;
	int x;
	int i;

	x = 3;
	y = 2;
	skrr->i = 0;
	i = 0;
	while (skrr->i < MEM_SIZE)
	{
		while (i < 64)
		{
			if (findprocess(skrr, skrr->i) == 1)
			{
				wattrset(skrr->vis->code, COLOR_PAIR(skrr->mapid[skrr->i]));
				if (skrr->mapid[skrr->i] > 9)
					highlight(skrr, skrr->i);
				wattron(skrr->vis->code, A_REVERSE);
				mvwprintw(skrr->vis->code, y, x, "%hh.2x", skrr->map[skrr->i++]);
				wattrset(skrr->vis->code, COLOR_PAIR(0) | A_NORMAL);
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
			x = x + 3;
			i++;
		}
		y++;
		x = 3;
		i = 0;
	}
}

void	visualize_init(t_skrr *skrr)
{
	int	width;
	int	height;

	init_visualisation(skrr);
	getmaxyx(stdscr, height, width);
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

void	cycles_limit(int c, t_skrr *skrr)
{
	if (c == 113 && skrr->vis->cycles > 1)
		skrr->vis->cycles -= (skrr->vis->cycles > 10) ? 10 : 1;
	if (c == 101)
		skrr->vis->cycles += 1;
	mvwprintw(skrr->vis->menu, 4, 25, "%d  ", skrr->vis->cycles);
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
		mvwaddstr(skrr->vis->menu, 2, 2, "** PAUSED ** ");
		wrefresh(skrr->vis->menu);
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