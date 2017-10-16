//
// Created by Yaroslav Zakharchuk on 10/10/17.
//

#ifndef VISUALIZE_H
# define VISUALIZE_H

# include <math.h>
# include "../../corewar.h"

typedef struct		s_highl
{
	int 			id;
	unsigned long	cycle;
	struct s_highl 	*next;
}					t_highl;

typedef struct 		s_live
{
	int				id;
	unsigned long	cycle;
	struct s_live	*next;
}					t_live;

struct 		s_vis
{
	WINDOW			*code;
	WINDOW			*menu;
	int 			cycles;
	int 			c;
	int 			s;
	t_highl			*highl;
	t_live			*live;
};

void	visualize(t_skrr *skrr, t_chmp *chmp);
void	visualize_init(t_skrr *skrr);
int		highlight(t_skrr *skrr, int id);
void	init_visualisation(t_skrr *skrr);
void breakdown_current(t_skrr *skrr, int y);

#endif
