//
// Created by Yaroslav Zakharchuk on 10/10/17.
//

#ifndef VISUALIZE_H
# define VISUALIZE_H

# include "../../corewar.h"

struct 		s_vis
{
	WINDOW			*code;
	WINDOW			*menu;
	int 			sleep;
	int 			cycles;
	int 			c;
	int 			s;
};

void	visualize(t_skrr *skrr, t_chmp *chmp);
void	visualize_init(t_skrr *skrr);

#endif
