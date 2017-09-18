#include "filler.h"

void	solve(t_struct *t, t_piece *p, char *line)
{
	put_coor(p, 0, 0);
	algo(t, p);
	if (*p->piece)
		while (--p->h_carre >= 0 && p->piece[p->h_carre])
			free(p->piece[p->h_carre]);
	if (*t->grid)
		while (--t->h_plateau >= 0 && t->grid[t->h_plateau])
			free(t->grid[t->h_plateau]);
	free(p->coorx);
	free(p->coory);
	initialize(t, p);
	ft_strdel(&line);
}

void	filler(t_struct *t, t_piece *p, int sig1, int sig2)
{
	char	*line;
	int		i;

	initialize(t, p);
	while (get_next_line(0, &line))
	{
		sig1 = 0;
		sig2 = 0;
		i = -1;
		while (line[++i])
		{
			if (ft_strncmp(line + i, "vinvimo.filler]", 15) == 0)
				players(t, line, &i, 0);
			else if (ft_strncmp(line + i, "Plateau ", 8) == 0)
				plate(t, &line, &i, &sig1);
			else if (ft_strncmp(line + i, "Piece ", 6) == 0)
				piece(p, line, &i, &sig2);
		}
		if (sig1 == 1)
			copy_plate(t, &line, &sig1);
		if (sig2 == 1)
			copy_piece(t, p, &line, &sig2);
		if (sig2 == 2)
			solve(t, p, line);
	}
}

int		main(void)
{
	t_struct	t;
	t_piece		p;

	t.player_name = NULL;
	t.player_number = 0;
	t.c = 0;
	t.c_maj = 0;
	filler(&t, &p, 0, 0);
	return (0);
}
