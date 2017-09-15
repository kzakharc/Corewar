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

#include "virtualm.h"

void			maybe_flag(char **av, int *i, t_skrr *skrr)
{
	skrr->flag_n == NULL ? skrr->flag_n = ft_memalloc(33) : 0;
	if (!ft_strcmp(av[*i], "-n"))
	{
		skrr->flag_n[skrr->cnt_n] = ft_atoi(av[*i + 1]);
		skrr->flag_n[skrr->cnt_n] != 0 ? (*i) += 2 : (*i)++;
		skrr->cnt_n++;
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
}

void 			find_player(char **av, int *i, t_skrr *skrr)
{
	chk_open(skrr, av, *i, 1);
	push_chmp(&skrr->chmp, skrr);
	just_read(skrr, av[*i], *i, skrr->chmp);
	skrr->max_player++;
	skrr->chmp->ac = *i;
	(*i)++;
}

void			parsing_arg(t_skrr *skrr, char **av, int ac)
{
	int i;

	i = 1;
	while (i < ac)
	{
		maybe_flag(av, &i, skrr);
		if (i != ac)
			find_player(av, &i, skrr);
		else
			break ;
	}
	flag_n(skrr->chmp, skrr);
	prog_commands(skrr, av, skrr->chmp);
}

unsigned int 	zero_reg(t_skrr *skrr)
{
	static int	nbr;
	static int	tmp;
	int			c;

	c = -1;
	while (++c < skrr->cnt_n)
	{
		if (skrr->flag_n[c] == tmp)
			tmp++;
	}
	if (skrr->flag_n[nbr] == 0)
	{
		skrr->flag_n[nbr] = tmp;
		nbr++;
		return (unsigned int)(tmp * -1);
	}
	else
		return (unsigned int)(skrr->flag_n[nbr] * -1);
}

void			flag_n(t_chmp *chmp, t_skrr *skrr)
{
	int	i;
	t_chmp *tmp;

	i = 0;
	tmp = chmp;
	skrr->cnt_n > skrr->max_player ? chk_open(skrr, 0, 0, 5) : 0;
	while (i < skrr->cnt_n)
	{
		skrr->flag_n[i] < 0 || skrr->flag_n[i] > skrr->max_player ? chk_open(skrr, 0, 0, 4) : 0;
		while (tmp->nbr_arg != i)
			tmp = tmp->next;
		tmp->process->registry[0] = zero_reg(skrr);
		i++;
		tmp = chmp;
	}
}