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

	init(&skrr, argc);
	(argc == 1) ? usage_e() : 0;
	(argc > 5) ? chk_open(&skrr, argv, argc, 0) : 0;
	while (++skrr.j < argc)
	{
		chk_open(&skrr, argv, argc, 1);
		just_read(&skrr, argv[skrr.j], argc);
	}
	(skrr.n != 0) ? print_info(&skrr, argc) : 0;
	print_map(&skrr);
	close(skrr.fd);
	return (0);
}
