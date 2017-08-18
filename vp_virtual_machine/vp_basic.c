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
		m[skrr->i] = get_magic(magic[skrr->i], skrr->flags.shift, skrr->i);
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
	lseek(skrr->fd, 4, SEEK_SET);
	read(skrr->fd, skrr->header.prog_name, 128);
//	ft_printf("prog_name: %s\n", skrr->header.prog_name);
	lseek(skrr->fd, 138, SEEK_SET);
	prog_size(skrr);
	lseek(skrr->fd, 140, SEEK_SET);
	read(skrr->fd, skrr->header.comment, 2048);
//	ft_printf("comments: %s\n", skrr->header.comment);
}

unsigned int	prog_size(t_skrr *skrr)
{
	char 			size[2];
	unsigned int	s[2];

	read(skrr->fd, size, 2);
	skrr->i = 0;
	skrr->flags.shift = 8;
	while (skrr->i < 2)
	{
		s[skrr->i] = get_size(size[skrr->i], skrr->flags.shift, skrr->i);
		ft_printf("size[%d]: %x\n", skrr->i, size[skrr->i]);
		skrr->flags.shift -= 8;
		skrr->i++;
	}
	skrr->header.prog_size = s[0] | s[1];
	ft_printf("prog_size: %u\n", skrr->header.prog_size);
	return (1);
}

unsigned  int	get_size(unsigned int s, int shift, int flag)
{
	unsigned int size;

	if (flag == 0)
		size = s << shift;
	else if (flag == 1)
		size = s << shift & 0x000000ff;
	else
		exit(0);
	return (size);
}

unsigned int 	get_magic(unsigned int m, int shift, int flag)
{
	unsigned int magic;

	if (flag == 0)
		magic = m << shift;
	else if (flag == 1)
		magic = m << shift & 0x00ffffff;
	else if (flag == 2)
		magic = m << shift & 0x0000ffff;
	else if (flag == 3)
		magic = m & 0x000000ff;
	else
		exit(0);
	return (magic);
}