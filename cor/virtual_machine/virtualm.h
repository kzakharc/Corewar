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
**	struct for op_tab, which have inside all information about instructions.
*/

typedef struct 		s_op
{
	char 			*name;
	short		 	numb_of_arg;
	t_arg_type 		arg[3];
	short			opcode;
	short			cycles;
	short		 	codage;
	short			dir_size;
}					t_op;

/*
**	linked lists for process.
*/

typedef struct		s_proc
{
	int 			id;
	int 			pc;
	int 			tmp_pc;
	unsigned int 	registry[REG_NUMBER];
	int 			carry;
	int 			alive;
	struct s_proc	*next;
}					t_proc;

/*
**	linked lists for champs.
*/

typedef struct		s_chmp
{
	int 			id;
	int 			nbr_arg;
	int 			fd;
	int 			ac;
	unsigned int 	reg_value;
	int 			offset;
	unsigned int 	player_pos;
	header_t 		header;
	struct s_chmp	*next;
}					t_chmp;

/*
**	basic struct for additional info. / n - iterator for players
*/

typedef struct		s_skrr
{
	int 			fd;
	unsigned int	i;
	int 			j;
	int 			n;
	int 			op;
	int 			shift;
	int 			flag;
	int 			max_checks;
	int 			nbr_live;
	int		 		cycle_to_die;
	int 			*flag_n;
	int 			cnt_n;
	int 			flag_v;
	int 			flag_dump;
	int 			nbr_player;
	int 			max_player;
	unsigned char 	map[MEM_SIZE];
	t_chmp			*chmp;
	t_proc			*process;
}					t_skrr;


/*
**	global variables, g_inter - global itearator, op_tab array with info about instructions.
*/

t_op				g_tab[17];
unsigned long 		g_cycles;
int 				g_ctd;
int 				g_err;

/*
**	usage and open checks functions.  go -> [vp_err_u.c]
*/

void				usage_e(void);
void				chk_open(t_skrr *skrr, char **argv, int argc, int flag);
void				chk_size(t_skrr *skrr, char *argv, unsigned char *line, t_chmp *chmp);
//void				chck_for_usage(t_skrr *skrr, char *argv);

/*
**	init function. go -> [vp_err_u.c] for init all structure variables.
*/

void				init(t_skrr *skrr);

/*
**	main functions, for get info about "name", "weighing", "comments" .. go -> [vp_basic.c].
*/

void				just_read(t_skrr *skrr, char *argv, int argc, t_chmp *chmp);
unsigned int 		get_magic_size(unsigned int m, int shift);
void				get_name_comments(t_skrr *skrr, char *argv, int argc, t_chmp *chmp);
void				prog_size(t_skrr *skrr, char *argv, int argc, t_chmp *chmp);

/*
**	commands functions. Func for global while and stuff.
*/

void				prog_commands(t_skrr *skrr, char **av, t_chmp *chmp);
static void			player_position(int nbr, t_skrr *skrr, t_chmp *chmp);
void				unsafe_copy(t_skrr *skrr, unsigned char *src, t_chmp *chmp);
int 				entry_point(t_skrr *skrr, t_chmp *chmp);
int					which_instr(t_skrr *skrr, t_chmp *chmp);
int 				change_player(t_skrr *skrr, t_chmp *chmp);

/*
**	Adding new champ and init his data. go -> [new_chmp.c].
*/

int 				push_chmp(t_chmp **head, t_skrr *skrr);
void 				init_data(t_chmp *champ);
int 				push_process(t_proc **process, t_skrr *skrr, int player_num);

/*
**	Instructions. live, st .. etc go -> [./instructions/[name of instructions].c] etc ..
*/

int 				live_instr(t_skrr *skrr, t_chmp *chmp, int op);
int 				ld_instr(t_skrr *skrr, t_chmp *chmp, int op);
int 				st_instr(t_skrr *skrr, t_chmp *chmp, int op);
int 				add_instr(t_skrr *skrr);
int 				sub_instr(t_skrr *skrr);
int 				and_instr(t_skrr *skrr);
int 				or_instr(t_skrr *skrr);
int 				xor_instr(t_skrr *skrr);
int 				zjmp_instr(t_skrr *skrr, t_chmp *chmp, int op);
int 				ldi_instr(t_skrr *skrr, t_chmp *chmp, int op);
int 				sti_instr(t_skrr *skrr, t_chmp *chmp, int op);
int 				fork_instr(t_skrr *skrr, t_chmp *chmp, int op);
int 				lld_instr(t_skrr *skrr, t_chmp *chmp, int op);
int 				lldi_instr(t_skrr *skrr, t_chmp *chmp, int op);
int 				lfork_instr(t_skrr *skrr, t_chmp *chmp, int op);
int 				aff_instr(t_skrr *skrr, t_chmp *chmp);

/*
**	additional func for instr.
*/

unsigned char		hex_to_bin(unsigned char c, int i);
unsigned int		two_four_bytes(unsigned char *map, int dir_size);
int					from_reg(unsigned char *q, t_chmp *chmp, t_skrr *skrr, short i);
unsigned char		arg_types(t_skrr *skrr, t_chmp *chmp, int ctk);
int 				get_address(unsigned char *q, t_skrr *skrr, int l, short i);
int 				simple_address(unsigned char *q, t_skrr *skrr, t_chmp *chmp, short i);
void				load_into(int address, t_chmp *chmp, t_skrr *skrr, int flag);
void				instr_err(int op);
void				sizes_err(char *name, int flag);
int					same_start(unsigned char *q, t_skrr *skrr, int op, int num_arg);

int					reg_param(t_skrr *skrr, unsigned char *map, int flag);
int					dir_param(t_skrr *skrr, unsigned char *map, short dir_size);
int					ind_param(t_skrr *skrr,	unsigned char *map, int l, int bytes);

/*
**	init map and print map
*/

static void			init_map(t_skrr *skrr);
void				print_map(t_skrr *skrr);

/*
**	printing all players and their info.
*/

void				print_info(t_skrr *skrr, int argc, t_chmp *chmp);

/*
** function for flags
*/

void				parsing_arg(t_skrr *skrr, char **av, int ac);
void				flag_n(t_chmp *chmp, t_skrr *skrr);
unsigned int 		zero_reg(t_skrr *skrr);


#endif
