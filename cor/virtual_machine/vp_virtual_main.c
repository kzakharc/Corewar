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

int 	main(int argc, char **argv)
{
	t_skrr	skrr;
	int 	cnt;

	cnt = 0;
	init(&skrr);
	(argc == 1) ? usage_e() : 0;
	while (++cnt < argc)
		how_many_players(&skrr, argv[cnt], &cnt, argc);
	while (++skrr.j < argc)
	{
		!ft_strcmp(argv[skrr.j], "-n") ? flag_n(argv[skrr.j + 1], &skrr) : 0;
		chk_open(&skrr, argv, argc, 1);
		push_chmp(&skrr.chmp, &skrr);
		just_read(&skrr, argv[skrr.j], argc, skrr.chmp);
		skrr.n++;
	}
	(skrr.n) ? print_info(&skrr, argc, skrr.chmp) : 0;
	close(skrr.fd) < 0 ? exit(0) : 0;
	return (0);
}