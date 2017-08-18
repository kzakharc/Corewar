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
	unsigned int	gt_magic;
}					t_flag;

typedef struct		s_skrr
{
	int 			fd;
	int 			j;
	unsigned int	i;
	t_flag			flags;
	header_t 		header;

}					t_skrr;

void				usage_e(void);
void				chk_open(t_skrr *skrr, char **argv, int argc, int flag);
void				init(t_skrr *skrr, int argc);
void				just_read(t_skrr *skrr, char *argv);
unsigned int 		get_magic(unsigned int m, int shift, int flag);
void				get_name_comments(t_skrr *skrr);

#endif
