/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 22:59:28 by vinvimo           #+#    #+#             */
/*   Updated: 2017/09/29 23:36:34 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

long long	tmp_distance(t_struct *t, t_piece *p, char enemy)
{
	distance_r(t, p, enemy);
	distance_l(t, enemy);
	if (t->dis_tmp1 < t->dis_tmp2)
		return (t->dis_tmp1);
	else
		return (t->dis_tmp2);
}

int	distance_r(t_struct *t, t_piece *p, char enemy)
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
			&& ft_power(c - (p->right - p->left), 2) + ft_power(t->i - i, 2) < t->dis_tmp1)
			{
				t->dis_tmp1 = ft_power(c - (p->right - p->left), 2) + ft_power(t->i - i, 2);
				sig = 1;
			}
		}
		c++;
		j++;
	}
	if (sig == 1)
		return (1);
	return (0);
}

int	distance_l(t_struct *t, char enemy)
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
		return (1);
	return (0);
}

