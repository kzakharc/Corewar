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

void		just_read(t_skrr *skrr, char *argv, int argc)
{
	char 			magic[4];
	unsigned int 	m[4];

	if (read(skrr->fd, magic, 4) < 0)
	{
		ft_printf("Error:"RED" %s "RESET"is a directory\n", argv);
		exit(0);
	}
	skrr->i = 0;
	skrr->shift = 24;
	while (skrr->i < 4)
	{
		m[skrr->i++] = get_magic_size(magic[skrr->i], skrr->shift);
		skrr->shift -= 8;
	}
	skrr->header[skrr->n].magic = m[0] | m[1] | m[2] | m[3];
	if (skrr->header[skrr->n].magic == COREWAR_EXEC_MAGIC)
		get_name_comments(skrr, argv, argc);
	else
	{
		ft_printf("Error: File"RED" %s "RESET"has an invalid header\n", argv);
		exit (0);
	}
	skrr->n++;
}

void		get_name_comments(t_skrr *skrr, char *argv, int argc)
{
	(lseek(skrr->fd, 4, SEEK_SET) < 0) ? exit (0) : 0;
	(read(skrr->fd, skrr->header[skrr->n].prog_name, PROG_NAME_LENGTH + 1) < 0) ? exit(0) : 0;
	(lseek(skrr->fd, COMMENT_POS, SEEK_SET) < 0) ? exit (0) : 0;
	(read(skrr->fd, skrr->header[skrr->n].comment, COMMENT_LENGTH + 1) < 0) ? exit(0) : 0;
	(lseek(skrr->fd, SIZE_POS, SEEK_SET) < 0) ? exit (0) : 0;
	prog_size(skrr, argv);
	(lseek(skrr->fd, COMMANDS_POS, SEEK_SET) < 0) ? exit(0) : 0;
	prog_commands(skrr, argc);

}

void		prog_size(t_skrr *skrr, char *argv)
{
	char 			size[4];
	unsigned int	s[4];

	if (read(skrr->fd, size, 4) < 0)
	{
		perror("Error");
		exit(0);
	}
	skrr->i = 0;
	skrr->shift = 24;
	while (skrr->i < 4)
	{
		s[skrr->i++] = get_magic_size(size[skrr->i], skrr->shift);
		skrr->shift -= 8;
	}
	skrr->header[skrr->n].prog_size = s[0] | s[1] | s[2] | s[3];
	if (skrr->header[skrr->n].prog_size > CHAMP_MAX_SIZE)
	{
		ft_printf("Error: File" RED" %s "RESET "has too large a code "
						  "(%u bytes vs %u bytes)\n",
				  argv, skrr->header[skrr->n].prog_size, CHAMP_MAX_SIZE);
		exit(0);
	}
}

unsigned int 	get_magic_size(unsigned int m, int shift)
{
	unsigned int magic;

	magic = 0;
	(shift == 24) ? (magic = m << shift) : 0;
	(shift == 16) ? (magic = m << shift & 0x00ffffff) : 0;
	(shift == 8) ? (magic = m << shift & 0x0000ffff) : 0;
	(shift == 0) ? (magic = m & 0x000000ff) : 0;
	return (magic);
}

void		print_info(t_skrr *skrr, int argc)
{
	skrr->i = 0;
	skrr->n = 1;
	(skrr->i == 0) ? ft_printf("Introducing contestants...\n") : 0;
	while (skrr->n < argc)
	{
		ft_printf("* Player %d, ", skrr->n++);
		ft_printf("Name:" GRN" \"%s\", "RESET, skrr->header[skrr->i].prog_name);
		ft_printf("weighing" GRN" %u "RESET "bytes, ",
				  skrr->header[skrr->i].prog_size);
		ft_printf("comment:" GRN" \"%s\"\n"RESET,
				  skrr->header[skrr->i].comment);
		skrr->i++;
	}
}