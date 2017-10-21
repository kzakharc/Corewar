//
// Created by Dmytrii Spyrydonov on 9/24/17.
//

#include "../../corewar.h"

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
		mvwaddch(skrr->vis->menu, y + skrr->max_player * 4, 3, '[' | COLOR_PAIR(27) | A_BOLD);
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
		wattron(skrr->vis->menu, COLOR_PAIR(27) | A_BOLD);
		mvwaddch(skrr->vis->menu, y + skrr->max_player * 4, x, ']');
	}
	else
	{
		wattron(skrr->vis->menu, COLOR_PAIR(27) | A_BOLD);
		mvwaddstr(skrr->vis->menu, 12 + + skrr->max_player * 4, 3, "[--------------------------------------------------]");
	}
}

void	del_live(t_skrr *skrr)
{
	t_live	*current;
	t_live	*prev;

	prev = NULL;
	current = skrr->vis->live;
	if (current->id == skrr->i)
	{
		skrr->vis->live = current->next;
		free(current);
		return ;
	}
	while (current != NULL)
	{
		if (current->id == skrr->i)
		{
			prev->next = current->next;
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

void add_to_live(t_skrr *skrr, int proctmp)
{
	t_live *newnode;

	newnode = (t_live*)malloc(sizeof(t_live));
	newnode->id = skrr->i;
	newnode->cycle = g_cycles + 50;
	newnode->colorid = (proctmp > 9) ? proctmp / 10 + 10 : proctmp + 10;
	newnode->next = skrr->vis->live;
	skrr->vis->live = newnode;
}

int findlive(t_skrr *skrr)
{
	t_live *livetmp;
	t_proc *proctmp;

	livetmp = skrr->vis->live;
	proctmp = skrr->process;

	while (livetmp != NULL)
	{
		if (livetmp->id == skrr->i)
		{
			if (livetmp->cycle <= g_cycles || skrr->map[skrr->i] != 01)
			{
				del_live(skrr);
				wattrset(skrr->vis->code,
						 COLOR_PAIR(livetmp->colorid) | A_BOLD);
				return (1);
			}
			wattrset(skrr->vis->code,
					COLOR_PAIR(livetmp->colorid) | A_BOLD);
			return (1);
		}
		livetmp = livetmp->next;
	}
	while (proctmp != NULL)
	{
		if (proctmp->live_pc == skrr->i && proctmp->live_color == 1 && skrr->map[skrr->i] == 01)
		{
			add_to_live(skrr, skrr->mapid[skrr->i]);
			wattrset(skrr->vis->code,
					 COLOR_PAIR(skrr->vis->live->colorid) | A_BOLD);
			proctmp->live_color = 0;
			return (1);
		}
		proctmp = proctmp->next;
	}
	return (0);
}

void	cycles_limit(int c, t_skrr *skrr)
{
	if (c == 113 && skrr->vis->cycles > 1)
		skrr->vis->cycles -= (skrr->vis->cycles > 10) ? 10 : 1;
	if (c == 101)
		skrr->vis->cycles += 1;
	if (c == 49)
		skrr->vis->cycles = 50;
	if (c == 50)
		skrr->vis->cycles = 100;
	if (c == 51)
		skrr->vis->cycles = 500;
	if (c == 52)
		skrr->vis->cycles = 1000;
	if (c == 52)
		skrr->vis->cycles = 2000;
	if (c == 53)
		skrr->vis->cycles = 4000;
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
		mvwaddstr(skrr->vis->menu, 2, 3, "** PAUSED ** ");
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
