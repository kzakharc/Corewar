/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtualm.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:15:29 by vpoltave          #+#    #+#             */
/*   Updated: 2017/08/08 14:16:52 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIRTUALM_H
# define VIRTUALM_H

#include "../corewar.h"

typedef struct 		s_flags
{
	int 			shift;
}					t_flag;

typedef struct		s_skrr
{
	int 			fd;
	int 			j;
	unsigned int	i;
	int 			n;
	t_flag			flags;
	header_t 		header[MAX_PLAYERS];

}					t_skrr;

/*
**	usage and open checks functions
*/

void				usage_e(void);
void				chk_open(t_skrr *skrr, char **argv, int argc, int flag);

/*
**	init function
*/

void				init(t_skrr *skrr, int argc);

/*
**	main functions, for get info about "name", "weighing", "comments" ..
*/

void				just_read(t_skrr *skrr, char *argv);
unsigned int 		get_magic_size(unsigned int m, int shift, int flag);
void				get_name_comments(t_skrr *skrr, char *argv);
void				prog_size(t_skrr *skrr, char *argv);

/*
**	commands functions
*/

void				prog_commands(t_skrr *skrr);

/*
**	printing all players and their info
*/

void				print_info(t_skrr *skrr, int argc);

#endif
