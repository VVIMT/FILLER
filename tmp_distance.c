/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 22:59:28 by vinvimo           #+#    #+#             */
/*   Updated: 2017/09/29 22:00:26 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

long long	tmp_distance(t_struct *t, t_piece *p, char enemy)
{
	distanceh1(t, p, enemy);
	distanceh2(t, enemy);
//	distancev1(t, p, enemy);
//	distancev2(t, enemy);
	if (t->dis_tmp1 < t->dis_tmp2)
		return (t->dis_tmp1);
	else
		return (t->dis_tmp2);
}

int	distanceh1(t_struct *t, t_piece *p, char enemy)
{
	int	sig;
	int	c;
	int	i;
	int	j;

	sig = 0;
	c = 0;
	t->dis_tmp1 = (t->l_plateau * t->l_plateau) + (t->l_plateau * t->l_plateau);
	j = t->j;
	while (t->grid[0][j])
	{
		i = -1;
		while (t->grid[++i])
		{
			if (t->grid[i][j] == enemy
			&& ft_power(c, 2) + ft_power(t->i - i, 2) < t->dis_tmp1)
			{
				t->dis_tmp1 = ft_power(c, 2) + ft_power(t->i - i, 2);
				sig = 1;
			}
		}
		c++;
		j++;
	}
	if (sig == 1)
	{
		t->dis_hor = c - (p->right - p->left);
		return (1);
	}
	return (0);
}

int	distanceh2(t_struct *t, char enemy)
{
	int	sig;
	int	c;
	int	i;
	int	j;

	sig = 0;
	c = 0;
	t->dis_tmp2 = (t->l_plateau * t->l_plateau) + (t->l_plateau * t->l_plateau);
	j = t->j;
	while (j >= 0)
	{
		i = -1;
		while (t->grid[++i])
		{
			if (t->grid[i][j] == enemy
			&& ft_power(c, 2) + ft_power(t->i - i, 2) < t->dis_tmp2)
			{
				t->dis_tmp2 = ft_power(c, 2) + ft_power(t->i - i, 2);
				sig = 1;
			}
		}
		c++;
		j--;
	}
	if (sig == 1)
	{
		t->dis_hor = c;
		return (1);
	}
	return (0);
}

int	distancev1(t_struct *t, t_piece *p, char enemy)
{
	int	sig;
	int	c;
	int	i;
	int	j;

	sig = 0;
	c = 0;
	i = t->i;
	while (t->grid[i])
	{
		j = -1;
		while (t->grid[i][++j])
			if (t->grid[i][j] == enemy)
				sig = 1;
		if (sig == 0)
			c++;
		i++;
	}
	if (sig == 1)
	{
		t->dis_ver = c - (p->bot - p->top);
		return (1);
	}
	return (0);
}

int	distancev2(t_struct *t, char enemy)
{
	int	sig;
	int	c;
	int	i;
	int	j;

	sig = 0;
	c = 0;
	i = t->i;
	while (i >= 0)
	{
		j = -1;
		while (t->grid[i][++j])
			if (t->grid[i][j] == enemy)
				sig = 1;
		if (sig == 0)
			c++;
		i--;
	}
	if (sig == 1)
	{
		t->dis_ver = c;
		return (1);
	}
	return (0);
}
