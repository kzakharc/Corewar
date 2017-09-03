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

/*
**	defines for lseeks, go -> [vp_basic.c]
*/

# define COMMENT_POS	(PROG_NAME_LENGTH + 13 - ((PROG_NAME_LENGTH + 1) % 4))
# define SIZE_POS		(PROG_NAME_LENGTH + 9 - ((PROG_NAME_LENGTH + 1) % 4))
# define COMMANDS_POS	(COMMENT_POS + COMMENT_LENGTH + 4)

#include "../../corewar.h"

/*
**	struct for op_tab, which have inside all information about instructions
*/

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

/*
**	basic struct for additional info
*/

typedef struct		s_skrr
{
	int 			fd;
	int 			j;
	unsigned int	i;
	int 			n;
	int 			op;
	int 			shift;
	int 			flag;
	unsigned int 	player_pos;
	int		 		cycle_to_die;
	int 			nbr_live;
//	int 			max_checks;
//	int 			carry;
	unsigned char	*PC;
	unsigned int 	registry[REG_NUMBER];
	unsigned char 	map[MEM_SIZE];
	header_t 		header[MAX_PLAYERS];
}					t_skrr;

/*
**	global variables, g_inter - global itearator, op_tab array with info about instructions.
*/

t_op				op_tab[17];
unsigned long 		g_iter;
int 				g_CTD;

/*
**	usage and open checks functions.  go -> [vp_err_u.c]
*/

void				usage_e(void);
void				chk_open(t_skrr *skrr, char **argv, int argc, int flag);

/*
**	init function. go -> [vp_err_u.c]
*/

void				init(t_skrr *skrr, int argc);

/*
**	main functions, for get info about "name", "weighing", "comments" .. go -> [vp_basic.c]
*/

void				just_read(t_skrr *skrr, char *argv, int argc);
unsigned int 		get_magic_size(unsigned int m, int shift);
void				get_name_comments(t_skrr *skrr, char *argv, int argc);
void				prog_size(t_skrr *skrr, char *argv);

/*
**	commands functions. Func for global while and stuff.
*/

void				prog_commands(t_skrr *skrr, int argc);
static void			player_position(t_skrr *skrr, int argc);
void				unsafe_copy(t_skrr *skrr, unsigned char *src);
int 				entry_point(t_skrr *skrr);
int					which_instr(t_skrr *skrr);

/*
**	Instructions. live, st .. etc go -> [./instructions/[name of instructions].c] etc
*/

int 				live_instr(t_skrr *skrr);
int 				ld_instr(t_skrr *skrr);
int 				st_instr(t_skrr *skrr);
int 				add_instr(t_skrr *skrr);
int 				sub_instr(t_skrr *skrr);
int 				and_instr(t_skrr *skrr);
int 				or_instr(t_skrr *skrr);
int 				xor_instr(t_skrr *skrr);
int 				zjmp_instr(t_skrr *skrr);
int 				ldi_instr(t_skrr *skrr);
int 				sti_instr(t_skrr *skrr);
int 				fork_instr(t_skrr *skrr);
int 				lld_instr(t_skrr *skrr);
int 				lldi_instr(t_skrr *skrr);
int 				lfork_instr(t_skrr *skrr);
int 				aff_instr(t_skrr *skrr);

/*
**	additional func for instr
*/

unsigned int		 hex_to_bin(unsigned char c, int i);

/*
**	manipulations with map
*/

void				print_map(t_skrr *skrr);
static void			init_map(t_skrr *skrr);

/*
**	printing all players and their info.
*/

void				print_info(t_skrr *skrr, int argc);

#endif
