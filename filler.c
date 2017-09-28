/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 22:55:29 by vinvimo           #+#    #+#             */
/*   Updated: 2017/09/28 23:33:37 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	solve(t_struct *t, t_piece *p, char *line)
{
	int	x;

	put_coor(p, 0, 0);
	algo(t, p);
ft_print(t->grid, 0);
	x = 0;
	while (x <= p->h_carre + 2 && p->piece[x])
		ft_strdel(&(p->piece[x++]));
	if (p->piece)
		free(p->piece);
	x = 0;
	while (x <= t->h_plateau + 2 && t->grid[x])
		ft_strdel(&(t->grid[x++]));
	if (t->grid)
		free(t->grid);
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
	while (get_next_line(t->fd, &line))
	{
		sig1 = 0;
		sig2 = 0;
		i = -1;
		while (line[++i])
		{
			if (ft_strncmp(line + i, "vinvimo.filler]", 15) == 0)
				players(t, line, &i);
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

//t.fd = open("Plateau", O_RDONLY);
t.fd = 0;
	t.player_number = 0;
	t.c = 0;
	t.c_maj = 0;
	filler(&t, &p, 0, 0);
	return (0);
}
