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

void			how_many_players(t_skrr *skrr, char *av, int *cnt, int ac)
{
	static int	nbr;
	int 		fd;

	fd = open(av, O_RDONLY);
	fd > 0 ? nbr++ : 0;
	if (*cnt == ac - 1)
	{
		skrr->max_player = nbr;
		(nbr > MAX_ARGS_NUMBER) ? chk_open(skrr, &av, ac, 0) : 0;
	}
}

int 			find_new_nbr(char **nbr)
{

}

unsigned int 	zero_reg(t_skrr *skrr)
{
	static char	*nbr;
	static int 	cnt;
	int			cnt_player;
	int 		i;

	nbr == NULL ? nbr = ft_strdup("0000") : 0;
	if (ft_strchr(nbr, skrr->nbr_player + 48))
	{
		cnt_player = find_new_nbr(&nbr);
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