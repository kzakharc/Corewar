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
	unsigned char *line;

	player_position(skrr, argc - 1);
	(skrr->flag == -1) ? init_map(skrr) : 0;
	line = (unsigned char*)ft_strnew(CHAMP_MAX_SIZE);
	skrr->i = 0;
	while (read(skrr->fd, &line[skrr->i], 1) != 0)
		skrr->i++;
//	ft_printf("Player: %d\tposition: %d\n", skrr->j, skrr->player_pos);
	unsafe_copy(skrr, line);
	skrr->registry[0] = (unsigned int)skrr->j * (-1);
//	ft_printf("%x\n", skrr->registry[0]);
	entry_point(skrr);
}

void	unsafe_copy(t_skrr *skrr, unsigned char *line)
{
	int pos;

	pos = skrr->player_pos;
	if (line == NULL)
		exit (1);
	while (skrr->i-- > 0)
		skrr->map[pos++] = *line++;
}

void	print_map(t_skrr *skrr)
{
	skrr->i = 0;
	ft_printf("\n");
	while (skrr->i < MEM_SIZE)
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
	skrr->flag = 1;
	skrr->i = 0;
	while (skrr->i < MEM_SIZE)
		skrr->map[skrr->i++] = 0;
}

static void	player_position(t_skrr *skrr, int argc)
{
	unsigned int tmp;

	tmp = 0;
	(skrr->j == 1) ? skrr->player_pos = 0 : 0;
	(skrr->j != 1) ? tmp = (unsigned int)(MEM_SIZE / argc) : 0;
	(skrr->j == 2) ? skrr->player_pos += tmp : 0;
	(skrr->j == 3) ? skrr->player_pos = tmp * 2 : 0;
	(skrr->j == 4) ? skrr->player_pos = tmp * 3 : 0;
}
