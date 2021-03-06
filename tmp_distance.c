/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 18:39:21 by vinvimo           #+#    #+#             */
/*   Updated: 2017/10/01 18:46:39 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

long long	tmp_distance(t_struct *t, t_piece *p, char enemy)
{
	distance_r(t, p, enemy);
	distance_l(t, p, enemy);
	if (t->dis_tmp1 < t->dis_tmp2)
		return (t->dis_tmp1);
	else
		return (t->dis_tmp2);
}

long long	pythagore(t_struct *t, t_piece *p, int i, int c)
{
	int	a;
	int	b;

	a = t->i - i;
	b = c;
	if (a < -(p->bot - p->top + 1) / 2)
		a = -(t->i - i) - (p->bot - p->top + 1) / 2;
	else
		a = t->i - i + (p->bot - p->top + 1) / 2;
	if (c < -(p->right - p->left + 1) / 2)
		b = -c + (p->right - p->left + 1) / 2;
	else
		b = c - (p->right - p->left + 1) / 2;
	return (ft_power(a, 2) + ft_power(b, 2));
}

void		distance_r(t_struct *t, t_piece *p, char enemy)
{
	int	c;
	int	i;
	int	j;

	c = 0;
	t->dis_tmp1 = (t->l_plateau * t->l_plateau) + (t->l_plateau * t->l_plateau);
	j = t->j;
	while (t->grid[0][j])
	{
		i = -1;
		while (t->grid[++i])
			if (t->grid[i][j] == enemy && pythagore(t, p, i, c) < t->dis_tmp1)
				t->dis_tmp1 = pythagore(t, p, i, c);
		c++;
		j++;
	}
}

void		distance_l(t_struct *t, t_piece *p, char enemy)
{
	int	c;
	int	i;
	int	j;

	c = 0;
	t->dis_tmp2 = (t->l_plateau * t->l_plateau) + (t->l_plateau * t->l_plateau);
	j = t->j;
	while (j >= 0)
	{
		i = -1;
		while (t->grid[++i])
			if (t->grid[i][j] == enemy && pythagore(t, p, i, c) < t->dis_tmp2)
				t->dis_tmp2 = pythagore(t, p, i, c);
		c--;
		j--;
	}
}
