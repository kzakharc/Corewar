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

# define COMMENT_POS	(PROG_NAME_LENGTH + 13 - ((PROG_NAME_LENGTH + 1) % 4))
# define SIZE_POS		(PROG_NAME_LENGTH + 9 - ((PROG_NAME_LENGTH + 1) % 4))
# define COMMANDS_POS	(COMMENT_POS + COMMENT_LENGTH + 4)

#include "../corewar.h"

typedef struct 		s_op
{
	char 			*name;
	unsigned int 	numb_of_arg;
	t_arg_type 		arg[3];
	unsigned int	opcode;
	unsigned int	cycles;
	unsigned int 	codage;
	unsigned int	wtf;
}					t_op;

typedef struct		s_skrr
{
	int 			fd;
	int 			j;
	unsigned int	i;
	int 			n;
	int 			shift;
	header_t 		header[MAX_PLAYERS];

}					t_skrr;

t_op				op_tab[17];

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
unsigned int 		get_magic_size(unsigned int m, int shift);
void				get_name_comments(t_skrr *skrr, char *argv);
void				prog_size(t_skrr *skrr, char *argv);

/*
**	commands functions
*/

void				prog_commands(t_skrr *skrr);
int 				zjmp(t_skrr *skrr, int i);

/*
**	printing all players and their info
*/

void				print_info(t_skrr *skrr, int argc);

#endif
