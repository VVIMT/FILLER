/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 22:55:41 by vinvimo           #+#    #+#             */
/*   Updated: 2017/09/27 23:54:23 by vinvimo          ###   ########.fr       */
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
		while (t->grid[p->i][p->j])
		{
			loop_algo(t, p);
			p->j++;
		}
		p->i++;
	}
	ft_putnbr(t->x);
	ft_putchar(' ');
	ft_putnbr(t->y);
	ft_putchar('\n');
}

void	algo_2(t_struct *t, t_piece *p)
{
	p->i = 0;
	while (t->grid[p->i])
	{
		p->j = 0;
		while (t->grid[p->i][p->j])
		{
			loop_algo_2(t, p);
			p->j++;
		}
		p->i++;
	}
}

void	loop_algo(t_struct *t, t_piece *p)
{
	t->i = p->i - p->top;
	t->j = p->j - p->left;
	if (check(t, p, t->grid) == 1)
	{
		t->i = p->i;
		t->j = p->j;
		if (choose_targets(t, 0, 0))
		{
		if (p->i - p->top + p->bot <= t->h_plateau
		&& p->j - p->left + p->right <= t->l_plateau
		&& (tmp_distance(t, '1') <= distance(t)
		|| tmp_distance(t, '2') <= distance(t)))
		{
			t->dis_x = t->dis_hor;
			t->dis_y = t->dis_ver;
			t->x = p->i - p->top;
			t->y = p->j - p->left;
		}
		}
		else
			algo_2(t, p);
	}
}

void	loop_algo_2(t_struct *t, t_piece *p)
{
	t->i = p->i - p->top;
	t->j = p->j - p->left;
	if (check(t, p, t->grid) == 1)
	{
		t->i = p->i;
		t->j = p->j;
		if (p->i - p->top + p->bot <= t->h_plateau
		&& p->j - p->left + p->right <= t->l_plateau
		&& tmp_distance(t, t->enemy) < distance(t))
		{
			t->dis_x = t->dis_hor;
			t->dis_y = t->dis_ver;
			t->x = p->i - p->top;
			t->y = p->j - p->left;
		}
	}
}

