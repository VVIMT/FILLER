/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 22:55:41 by vinvimo           #+#    #+#             */
/*   Updated: 2017/09/18 22:55:44 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	algo(t_struct *t, t_piece *p)
{
	compensate(p);
	t->x = -(t->l_plateau + t->h_plateau);
	t->y = -(t->l_plateau + t->h_plateau);
	t->dis_x = t->l_plateau;
	t->dis_y = t->h_plateau;
	t->dis_hor = t->l_plateau;
	t->dis_ver = t->h_plateau;
	p->i = 0;
	while (t->grid[p->i])
	{
		p->j = 0;
		loop_algo(t, p);
		p->i++;
	}
	if (t->x == -(t->l_plateau + t->h_plateau)
	|| t->y == -(t->l_plateau + t->h_plateau))
		init_algo(t, p);
	ft_putnbr(t->x);
	ft_putchar(' ');
	ft_putnbr(t->y);
	ft_putchar('\n');
}

void	init_algo(t_struct *t, t_piece *p)
{
	t->x = 0;
	t->y = 0;
	p->i = 0;
	while (t->grid[p->i])
	{
		p->j = 0;
		loop_init_algo(t, p);
		p->i++;
	}
}

void	loop_algo(t_struct *t, t_piece *p)
{
	while (t->grid[p->i][p->j])
	{
		t->i = p->i - p->h;
		t->j = p->j - p->l;
		if (check(t, p, t->grid) == 1)
		{
			t->i = p->i + p->h;
			t->j = p->j + p->l;
			if (p->i + p->h < t->h_plateau && p->j + p->l < t->l_plateau)
			{
				distanceh1(t, t->enemy);
				distanceh2(t, t->enemy);
				distancev1(t, t->enemy);
				distancev2(t, t->enemy);
			}
			if (tmp_distance(t) < distance(t))
			{
				t->dis_x = t->dis_hor;
				t->dis_y = t->dis_ver;
				t->x = p->i - p->h;
				t->y = p->j - p->l;
			}
		}
		p->j++;
	}
}

void	loop_init_algo(t_struct *t, t_piece *p)
{
	while (t->grid[p->i][p->j])
	{
		t->i = p->i - p->h;
		t->j = p->j - p->l;
		if (check(t, p, t->grid) == 1)
		{
			t->i = p->i + p->h;
			t->j = p->j + p->l;
			if (p->i + p->h < t->h_plateau && p->j + p->l < t->l_plateau)
			{
				distanceh1(t, t->enemy - 32);
				distanceh2(t, t->enemy - 32);
				distancev1(t, t->enemy - 32);
				distancev2(t, t->enemy - 32);
			}
			if (tmp_distance(t) <= distance(t))
			{
				t->dis_x = t->dis_hor;
				t->dis_y = t->dis_ver;
				t->x = p->i - p->h;
				t->y = p->j - p->l;
			}
		}
		p->j++;
	}
}
