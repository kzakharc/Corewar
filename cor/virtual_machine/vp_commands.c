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

void		prog_commands(t_skrr *skrr, char **av, t_chmp *chmp)
{
	unsigned char *line;
	t_chmp	*tmp;

	tmp = chmp;
	init_map(skrr);
	while (tmp)
	{
		player_position(tmp->process->registry[0],skrr, tmp);
		line = (unsigned char*)ft_strnew(tmp->header.prog_size);
		chk_size(skrr, av[tmp->ac], line, tmp);
		skrr->i = 0;
		while (read(tmp->fd, &line[skrr->i], 1))
			skrr->i++;
		unsafe_copy(skrr, line, tmp);
		tmp = tmp->next;
	}
	print_map(skrr);
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
	skrr->i = 0;
	while (skrr->i < MEM_SIZE)
		skrr->map[skrr->i++] = 0;
}

static void	player_position(int nbr, t_skrr *skrr, t_chmp *chmp)
{
	unsigned int tmp;

	tmp = (unsigned int)(MEM_SIZE / skrr->max_player);
	chmp->player_pos = nbr == -1 ? 0 : tmp * (-1 * nbr - 1);
}
