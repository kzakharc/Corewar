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

	if (read(skrr->fd, magic, 4) < 0)
	{
		ft_printf("Error:"RED" %s "RESET"is a directory\n", argv);
		exit(0);
	}
	skrr->i = 0;
	skrr->flags.shift = 24;
	while (skrr->i < 4)
	{
		m[skrr->i++] = get_magic_size(magic[skrr->i], skrr->flags.shift, 1);
		skrr->flags.shift -= 8;
	}
	skrr->header[skrr->n].magic = m[0] | m[1] | m[2] | m[3];
	if (skrr->header[skrr->n].magic == COREWAR_EXEC_MAGIC)
		get_name_comments(skrr, argv);
	else
	{
		ft_printf("Error: File"RED" %s "RESET"has an invalid header\n", argv);
		exit (0);
	}
	skrr->n++;
}

void		get_name_comments(t_skrr *skrr, char *argv)
{
	if (lseek(skrr->fd, 4, SEEK_SET) < 0)
		exit (0);
	if (read(skrr->fd, skrr->header[skrr->n].prog_name, 128) < 0)
		exit (0);
	if (lseek(skrr->fd, 140, SEEK_SET) < 0)
		exit (0);
	if (read(skrr->fd, skrr->header[skrr->n].comment, 2048) < 0)
		exit (0);
	if (lseek(skrr->fd, 138, SEEK_SET) < 0)
		exit (0);
	prog_size(skrr, argv);
	if (lseek(skrr->fd, 2180, SEEK_SET) < 0)
		exit (0);
	prog_commands(skrr);

}

void		prog_size(t_skrr *skrr, char *argv)
{
	char 			size[2];
	unsigned int	s[2];

	if (read(skrr->fd, size, 2) < 0)
	{
		perror("Error");
		exit(0);
	}
	skrr->i = 0;
	skrr->flags.shift = 8;
	while (skrr->i < 2)
	{
		s[skrr->i++] = get_magic_size(size[skrr->i], skrr->flags.shift, 0);
		skrr->flags.shift -= 8;
	}
	skrr->header[skrr->n].prog_size = s[0] | s[1];
	if (skrr->header[skrr->n].prog_size > CHAMP_MAX_SIZE)
	{
		ft_printf("Error: File" RED" %s "RESET "has too large a code "
						  "(%u bytes > %u bytes)\n",
				  argv, skrr->header[skrr->n].prog_size, CHAMP_MAX_SIZE);
		exit(0);
	}
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

void		print_info(t_skrr *skrr, int argc)
{
	skrr->i = 0;
	skrr->j = 1;
	(skrr->i == 0) ? ft_printf("Introducing contestants...\n") : 0;
	while (skrr->j < argc)
	{
		ft_printf("* Player %d, ", skrr->j++);
		ft_printf("Name:" GRN" \"%s\", "RESET, skrr->header[skrr->i].prog_name);
		ft_printf("weighing" GRN" %u "RESET "bytes, ",
				  skrr->header[skrr->i].prog_size);
		ft_printf("comment:" GRN" \"%s\"\n"RESET,
				  skrr->header[skrr->i].comment);
		skrr->i++;
	}
}