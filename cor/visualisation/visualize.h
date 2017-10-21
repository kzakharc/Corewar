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
	int 			colorid;
	unsigned long	cycle;
	struct s_live	*next;
}					t_live;

struct 		s_vis
{
	WINDOW			*code;
	WINDOW			*menu;
	int 			cycles;//real cycles
	int 			cycles_print;
	int 			c;
	int 			s;
	t_highl			*highl;
	t_live			*live;
};

void	visualize(t_skrr *skrr, t_chmp *chmp);
void	visualize_init(t_skrr *skrr);
int		highlight(t_skrr *skrr, int id);
void	init_visualisation(t_skrr *skrr);
void 	breakdown_current(t_skrr *skrr, int y);
void 	printwinner(t_skrr *skrr, char *name, int id);
void	printdata(WINDOW *menu, t_skrr *skrr, t_chmp *chmp);
int		find_live_count(t_skrr *skrr, int id);
int 	champ_color(t_skrr *skrr, int id);
long	find_last_live(t_skrr *skrr, int id);
char	*find_progname(t_skrr *skrr, int id);
void	printmargins(WINDOW *code, WINDOW *menu, int width, int height);
void	menufields(WINDOW *menu, t_skrr *skrr);
void	printmem(t_skrr *skrr);
int		findprocess(t_skrr *skrr, int pc);
int		findlive(t_skrr *skrr);

#endif
