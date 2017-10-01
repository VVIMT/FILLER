/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 18:37:08 by vinvimo           #+#    #+#             */
/*   Updated: 2017/10/01 18:37:11 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	check(t_struct *t, t_piece *p, char **grid)
{
	int	a;
	int	b;
	int	n;

	t->superposition = 0;
	n = -1;
	while (p->coorx[++n] != -1 && p->coory[n] != -1)
	{
		a = t->i + p->coorx[n];
		b = t->j + p->coory[n];
		if (a >= t->h_plateau || b >= t->l_plateau
		|| grid[a][b] == t->enemy || grid[a][b] == t->enemy - 32)
			return (0);
		if (grid[a][b] != '.' && grid[a][b] != 'x' && grid[a][b] != 'X'
		&& grid[a][b] != 'o' && grid[a][b] != 'O')
			return (0);
		if (grid[a][b] == t->c || grid[a][b] == t->c_maj)
			t->superposition++;
	}
	if (t->superposition == 1)
		return (1);
	return (0);
}
