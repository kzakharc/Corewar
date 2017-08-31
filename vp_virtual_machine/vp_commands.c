/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_virtual_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:12:55 by vpoltave          #+#    #+#             */
/*   Updated: 2017/08/08 15:42:25 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtualm.h"

void		prog_commands(t_skrr *skrr, int argc)
{
	char	*line;

	line = NULL;
	player_position(skrr, argc - 1);
	(skrr->flag == -1) ? init_map(skrr) : 0;
	if ((get_next_line(skrr->fd, &line) < 0))
		exit (1);
	ft_strcpy(&skrr->map[skrr->player_pos], line);
}

void	print_map(t_skrr *skrr)
{
	skrr->i = 0;
	ft_printf("\n");
	while (skrr->i < 4096)
	{
		if ((skrr->i) % 1365 == 0)
			ft_printf(RED"%.2x "RESET, skrr->map[skrr->i]);
		else
			ft_printf("%hh.2x ", skrr->map[skrr->i]);
		((skrr->i + 1) % 64 == 0) ? ft_printf("\n") : 0;
		skrr->i++;
	}
}

static void	init_map(t_skrr *skrr)
{
	skrr->i = 0;
	while (skrr->i < 4096)
	{
		skrr->map[skrr->i] = 0;
		skrr->i++;
	}
	skrr->flag = 1;
}

static void	player_position(t_skrr *skrr, int argc)
{
	int tmp;

	tmp = 0;
	(skrr->j == 1) ? skrr->player_pos = 0 : 0;
	(skrr->j != 1) ? tmp = (MEM_SIZE / argc) : 0;
	(skrr->j == 2) ? skrr->player_pos += tmp : 0;
	(skrr->j == 3) ? skrr->player_pos = tmp * 2 : 0;
	(skrr->j == 4) ? skrr->player_pos = tmp * 3 : 0;
}
