/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 22:59:28 by vinvimo           #+#    #+#             */
/*   Updated: 2017/09/18 22:59:33 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	distanceh1(t_struct *t, char enemy)
{
	int	sig;
	int	c;
	int	i;
	int	j;

	sig = 0;
	c = 0;
	j = t->j;
	while (t->grid[0][j])
	{
		i = -1;
		while (t->grid[++i])
		{
			if (t->grid[i][j] == enemy)
				sig = 1;
		}
		if (sig == 0)
			c++;
		j++;
	}
	if (sig == 1)
		t->dis_hor = c - 1;
}

void	distanceh2(t_struct *t, char enemy)
{
	int	sig;
	int	c;
	int	i;
	int	j;

	sig = 0;
	c = 0;
	j = t->j;
	while (j >= 0)
	{
		i = -1;
		while (t->grid[++i])
		{
			if (t->grid[i][j] == enemy)
				sig = 1;
		}
		if (sig == 0)
			c++;
		j--;
	}
	if (sig == 1)
		t->dis_hor = c - 1;
}

void	distancev1(t_struct *t, char enemy)
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
		{
			if (t->grid[i][j] == enemy)
				sig = 1;
		}
		if (sig == 0)
			c++;
		i++;
	}
	if (sig == 1)
		t->dis_ver = c - 1;
}

void	distancev2(t_struct *t, char enemy)
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
		{
			if (t->grid[i][j] == enemy)
				sig = 1;
		}
		if (sig == 0)
			c++;
		i--;
	}
	if (sig == 1)
		t->dis_ver = c - 1;
}
