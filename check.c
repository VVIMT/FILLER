/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 22:57:45 by vinvimo           #+#    #+#             */
/*   Updated: 2017/09/28 19:33:35 by vinvimo          ###   ########.fr       */
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
		&& grid[a][b] != 'o' && grid[a][b] != 'O' && grid[a][b] != '!')
			return (0);
		if (grid[a][b] == t->c || grid[a][b] == t->c_maj)
			t->superposition++;
	}
	if (t->superposition == 1)
		return (1);
	return (0);
}

int	borders(t_struct *t)
{
	int a;
	int sig1;
	int sig2;
	int sig3;
	int sig4;
	int i;

	sig1 = 0;
	a = 0;
	i = -1;
	while (t->grid[++i])
	{
		if (t->grid[i][0] == t->c || t->grid[i][0] == t->c_maj)
			sig1 = 1;
		if (t->grid[i][0] == '!')
			a = i;
	}
	if (sig1 == 1 && t->grid[a][0] == '!')
		t->grid[a][0] = '.';
	sig2 = 0;
	a = 0;
	i = -1;
	while (t->grid[++i])
	{
		if (t->grid[i][t->l_plateau - 1] == t->c
		|| t->grid[i][t->l_plateau - 1] == t->c_maj)
			sig2 = 1;
		if (t->grid[i][t->l_plateau - 1] == '!')
			a = i;
	}
	if (sig2 == 1 && t->grid[a][t->l_plateau - 1] == '!')
		t->grid[a][t->l_plateau - 1] = '.';
	sig3 = 0;
	a = 0;
	i = -1;
	while (t->grid[0][++i])
	{
		if (t->grid[0][i] == t->c || t->grid[0][i] == t->c_maj)
			sig3 = 1;
		if (t->grid[0][i] == '!')
			a = i;
	}
	if (sig3 == 1 && t->grid[0][a] == '!')
		t->grid[0][a] = '.';
	sig4 = 0;
	a = 0;
	i = -1;
	while (t->grid[t->h_plateau - 1][++i])
	{
		if (t->grid[t->h_plateau - 1][i] == t->c
		|| t->grid[t->h_plateau - 1][i] == t->c_maj)
			sig4 = 1;
		if (t->grid[t->h_plateau - 1][i] == '!')
			a = i;
	}
	if (sig4 == 1 && t->grid[t->h_plateau - 1][a] == '!')
		t->grid[t->h_plateau - 1][a] = '.';
	return (sig1 + sig2 + sig3 + sig4);
}
