/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 17:31:21 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/10 17:31:23 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtualm.h"

void		prog_commands(t_skrr *skrr, int argc, char *argv, t_chmp *chmp)
{
	unsigned char *line;

	player_position(skrr, argc - 1, chmp);
	(skrr->flag == -1) ? init_map(skrr) : 0;
	line = (unsigned char *)ft_strnew(chmp->header.prog_size);
	chk_size(skrr, argv, line, chmp);
	skrr->i = 0;
	while (read(skrr->fd, &line[skrr->i], 1))
		skrr->i++;
	unsafe_copy(skrr, line, chmp);
}

void	unsafe_copy(t_skrr *skrr, unsigned char *line, t_chmp *chmp)
{
	int pos;

	pos = chmp->player_pos;
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

static void	player_position(t_skrr *skrr, int argc, t_chmp *chmp)
{
	unsigned int tmp;

	tmp = 0;
	(skrr->j == 1) ? chmp->player_pos = 0 : 0;
	(skrr->j != 1) ? tmp = (unsigned int)(MEM_SIZE / argc) : 0;
	(skrr->j == 2) ? chmp->player_pos += tmp : 0;
	(skrr->j == 3) ? chmp->player_pos = tmp * 2 : 0;
	(skrr->j == 4) ? chmp->player_pos = tmp * 3 : 0;
}
