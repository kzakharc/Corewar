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
	static int	cnt_n;

	skrr->flag_n == NULL ? skrr->flag_n = ft_memalloc(4) : 0;
	if (!ft_strcmp(av[*i], "-n"))
	{
		skrr->flag_n[cnt_n] = ft_atoi(av[*i + 1]);
		cnt_n++;
		skrr->flag_n[cnt_n] != 0 ? (*i) += 2 : (*i)++;
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
	push_chmp(&skrr.chmp, &skrr);
}

void			parsing_arg(t_skrr *skrr, char **av, int ac)
{
	int i;

	i = 1;
	while (i < ac)
	{
		maybe_flag(av, &i, skrr);
		find_player(av, &i, skrr);
	}
}

int 			find_new_nbr(char **nbr, int *cnt, int nbr_player)
{
	int i;

	i = 0;
	while (++i <= 4)
	{
		ft_strchr(*nbr, nbr_player + 48) ? chk_open(0, 0, 0, 6) : 0;
		if (!ft_strchr(*nbr, i + 48))
		{
			*(*nbr + (*cnt)) = (char)(i + 48);
			break ;
		}
	}
	return (i);
}

unsigned int 	zero_reg(t_skrr *skrr)
{
	static char	*nbr;
	static int 	cnt;
	int			cnt_player;

	nbr == NULL ? nbr = ft_strdup("0000") : 0;
	if (ft_strchr(nbr, skrr->nbr_player + 48))
	{
		cnt_player = find_new_nbr(&nbr, &cnt, skrr->nbr_player);
		cnt++;
		/*
		 * вивід гравця
		 */
		ft_printf("%s\n", nbr);
		return ((unsigned int) cnt_player * (-1));
	}
	else
	{
		nbr[cnt] = (char)(skrr->nbr_player + 48);
		cnt++;
		/*
		 * вивід гравця
		 */
		ft_printf("%s\n", nbr);
		return ((unsigned int) skrr->nbr_player * (-1));
	}
}

void			flag_n(char *nbr_player, t_skrr *skrr)
{
	int			nbr;
	static int	cnt_n;

	cnt_n++;
	cnt_n > skrr->max_player || nbr_player == NULL ? chk_open(skrr, 0, 0, 5) : 0;
	nbr = (int)ft_atoi(nbr_player);
	nbr < 0 || nbr > skrr->max_player ? chk_open(skrr, 0, 0, 4) : 0;
	(nbr > 0 && nbr <= skrr->max_player) ? skrr->nbr_player = nbr : 0;
	skrr->j = nbr == 0 ? skrr->j + 1 : skrr->j + 2;
}