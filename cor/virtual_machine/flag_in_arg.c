/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_in_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:11:09 by yzakharc          #+#    #+#             */
/*   Updated: 2017/09/14 11:11:10 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void			maybe_flag(char **av, int *i, t_skrr *skrr, int ac)
{
	skrr->flag_n == NULL ? skrr->flag_n = ft_intmalloc(MAX_PLAYERS) : 0;
	if (!ft_strcmp(av[*i], "-n"))
	{
		*i + 1 < ac ? skrr->flag_n[skrr->cnt_n] = ft_atoi(av[*i + 1]) : 0;
		skrr->flag_n[skrr->cnt_n] != 0 ? (*i) += 2 : (*i)++;
		return ;
	}
	else if (!ft_strcmp(av[*i], "-v"))
	{
		skrr->flag_v = 1;
		(*i)++;
		return ;
	}
	else if (!ft_strcmp(av[*i], "-dump"))
	{
		skrr->flag_dump = ft_atoi(av[*(i + 1)]);
		(*i)++;
		return ;
	}
	else if (!ft_strcmp(av[*i], "-a"))
	{
		skrr->flag_a = 1;
		(*i)++;
		return ;
	}
}

void 			find_player(char **av, int *i, t_skrr *skrr)
{
	chk_open(skrr, av, *i, 1);
	push_chmp(&skrr->chmp, skrr);
	just_read(skrr, av[*i], *i, skrr->chmp);
	skrr->max_player++;
	skrr->cnt_n++;
	skrr->chmp->ac = *i;
	(*i)++;
}

void			parsing_arg(t_skrr *skrr, char **av, int ac)
{
	int i;

	i = 1;
	(REG_SIZE != 1) ? sizes_err("REG_SIZE", 1) : 0;
	(DIR_SIZE != 2) ? sizes_err("DIR_SIZE", 2) : 0;
	(IND_SIZE != 2) ? sizes_err("IND_SIZE", 3) : 0;
	while (i < ac)
	{
		maybe_flag(av, &i, skrr, ac);
		if (i != ac)
			find_player(av, &i, skrr);
		else
			break ;
	}
	skrr->max_player > MAX_PLAYERS ? chk_open(0, 0, 0, 0) : 0;
	flag_n(skrr);
	prog_commands(skrr, av, skrr->chmp);
	if (skrr->flag_v == 1)
	{
		skrr->flag_a = 0;
		skrr->flag_dump = -1;
	}
}

unsigned int 	zero_reg(t_skrr *skrr)
{
	static int	nbr;
	static int	tmp;
	int			c;

	c = -1;
	while (++c < skrr->max_player)
	{
		if (skrr->flag_n[c] == tmp)
			tmp++;
	}
	if (skrr->flag_n[nbr] == 0)
	{
		skrr->flag_n[nbr] = tmp;
		nbr++;
		c = tmp;
		tmp++;
		return (unsigned int)(c * -1);
	}
	else
	{
		c = nbr;
		nbr++;
		return (unsigned int) (skrr->flag_n[c] * -1);
	}
}

void			flag_n(t_skrr *skrr)
{
	int		i;
	t_proc	*tmp;

	i = 0;
	skrr->init_id = 1;
	tmp = skrr->process;
	skrr->cnt_n > skrr->max_player ? chk_open(skrr, 0, 0, 5) : 0;
	while (i < skrr->max_player)
	{
		skrr->flag_n[i] < 0 || skrr->flag_n[i] > skrr->max_player ? chk_open(skrr, 0, 0, 4) : 0;
		while (tmp->id != skrr->init_id * (-1))
			tmp = tmp->next;
		tmp->registry[0] = zero_reg(skrr);
		i++;
		skrr->init_id++;
		tmp = skrr->process;
	}
	i = -1;
	while (++i < skrr->max_player)
		ft_intc(skrr->flag_n, skrr->flag_n[i], skrr->max_player) > 1 ? chk_open(skrr, 0, 0, 6) : 0;
}