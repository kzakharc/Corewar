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

#include "../../corewar.h"

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
	int 			flag;
	unsigned int 	player_pos;
	long		 	cycle_to_die;
	int 			cycle_delta;
	int 			nbr_live;
//	int 			max_checks;
//	int 			carry;
	unsigned char	*PC;
	unsigned int 	registry[REG_NUMBER];
	unsigned char 	map[MEM_SIZE];
	header_t 		header[MAX_PLAYERS];
}					t_skrr;

t_op				op_tab[17];
unsigned long 		g_iter;

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

void				just_read(t_skrr *skrr, char *argv, int argc);
unsigned int 		get_magic_size(unsigned int m, int shift);
void				get_name_comments(t_skrr *skrr, char *argv, int argc);
void				prog_size(t_skrr *skrr, char *argv);

/*
**	commands functions
*/

void				prog_commands(t_skrr *skrr, int argc);
static void			player_position(t_skrr *skrr, int argc);
int 				entry_point(t_skrr *skrr);
int					which_instr(t_skrr *skrr);

/*
**	manipulations with map
*/

void				print_map(t_skrr *skrr);
static void			init_map(t_skrr *skrr);
void				unsafe_copy(t_skrr *skrr, unsigned char *src);

/*
**	printing all players and their info
*/

void				print_info(t_skrr *skrr, int argc);

#endif
