/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_virtual_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:12:55 by vpoltave          #+#    #+#             */
/*   Updated: 2017/08/16 15:49:32 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtualm.h"

void		just_read(t_skrr *skrr, char *argv)
{
	char 			magic[4];
	unsigned int 	m[4];

	read(skrr->fd, magic, 4);
	skrr->i = 0;
	skrr->flags.shift = 24;
	while (skrr->i < 4)
	{
		m[skrr->i] = get_magic_size(magic[skrr->i], skrr->flags.shift, 1);
		skrr->flags.shift -= 8;
		skrr->i++;
	}
	skrr->header.magic = m[0] | m[1] | m[2] | m[3];
	if (skrr->header.magic == COREWAR_EXEC_MAGIC)
		get_name_comments(skrr);
	else
	{
		ft_printf("Error: File"RED" %s "RESET"has an invalid header\n", argv);
		exit (1);
	}
}

void			get_name_comments(t_skrr *skrr)
{
	(skrr->j == 1) ? ft_printf("Introducing contestants...\n") : 0;
	ft_printf("* Player %d, ", skrr->j);
	lseek(skrr->fd, 4, SEEK_SET);
	read(skrr->fd, skrr->header.prog_name, 128);
	ft_printf("Name:" GRN" \"%s\", "RESET, skrr->header.prog_name);
	lseek(skrr->fd, 138, SEEK_SET);
	prog_size(skrr);
	ft_printf("weighing" GRN" %u "RESET "bytes, ", skrr->header.prog_size);
	lseek(skrr->fd, 140, SEEK_SET);
	read(skrr->fd, skrr->header.comment, 2048);
	ft_printf("comment:" GRN" \"%s\"\n"RESET, skrr->header.comment);
}

void		prog_size(t_skrr *skrr)
{
	char 			size[2];
	unsigned int	s[2];

	read(skrr->fd, size, 2);
	skrr->i = 0;
	skrr->flags.shift = 8;
	while (skrr->i < 2)
	{
		s[skrr->i] = get_magic_size(size[skrr->i], skrr->flags.shift, 0);
		skrr->flags.shift -= 8;
		skrr->i++;
	}
	skrr->header.prog_size = s[0] | s[1];
}

unsigned int 	get_magic_size(unsigned int m, int shift, int flag)
{
	unsigned int magic;

	magic = 0;
	if (flag)
	{
		(shift == 24) ? (magic = m << shift) : 0;
		(shift == 16) ? (magic = m << shift & 0x00ffffff) : 0;
		(shift == 8) ? (magic = m << shift & 0x0000ffff) : 0;
		(shift == 0) ? (magic = m & 0x000000ff) : 0;
	}
	else
	{
		(shift == 8) ? (magic = m << shift) : 0;
		(shift == 0) ? (magic = m << shift & 0x000000ff) : 0;
	}
	return (magic);
}