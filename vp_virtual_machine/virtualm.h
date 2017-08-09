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

typedef struct	s_skrr
{
	int 		j;
	int 		i;
	header_t 	*header;
}				t_skrr;

void			usage_e(void);
void			argc_e(int argc);

#endif
