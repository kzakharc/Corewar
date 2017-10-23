/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds_visualize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 21:12:09 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/10/21 21:27:45 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void	breakdown_calculations(t_skrr *skrr, int y, double total)
{
	int id;
	int i;
	int x;

	id = -1;
	i = 0;
	x = 4;
	mvwaddch(skrr->vis->menu, y + skrr->max_player * 4, 3, '[' |\
			COLOR_PAIR(27) | A_BOLD);
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

void	breakdown_current(t_skrr *skrr, int y)
{
	t_chmp	*tmp;
	double	total;

	tmp = skrr->chmp;
	total = 0;
	while (tmp != NULL)
	{
		total += tmp->live_count;
		tmp = tmp->next;
	}
	if (total > 0)
		breakdown_calculations(skrr, y, total);
	else
	{
		wattron(skrr->vis->menu, COLOR_PAIR(27) | A_BOLD);
		mvwaddstr(skrr->vis->menu, 12 + skrr->max_player * 4, 3, "[--------"\
				"------------------------------------------]");
	}
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

void	visualize(t_skrr *skrr)
{
	int c;

	printdata(skrr->vis->menu, skrr);
	printmem(skrr);
	wrefresh(skrr->vis->code);
	wrefresh(skrr->vis->menu);
	napms(1000 / skrr->vis->cycles);
	c = wgetch(skrr->vis->menu);
	if (c == 32 || c == 115 || g_cycles == 1 || skrr->vis->c == 1)
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
