#include "filler.h"

void	algo(t_struct *t, t_piece *p)
{
	compensate(p);
	t->x = - (t->l_plateau + t->h_plateau);
	t->y = - (t->l_plateau + t->h_plateau);
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
			t->i = p->i - p->h;
			t->j = p->j - p->l;
			if (check(t, p, t->grid) == 1)
			{
				t->i = p->i + p->h;
				t->j = p->j + p->l;
				if (p->i + p->h < t->h_plateau && p->j + p->l < t->l_plateau)
				{
					distanceh1(t);
					distanceh2(t);
					distancev1(t);
					distancev2(t);
				}
				if (ft_power(t->dis_hor, 2) + ft_power(t->dis_ver, 2) < ft_power(t->dis_x, 2) + ft_power(t->dis_y, 2))
				{
					t->dis_x = t->dis_hor;
					t->dis_y = t->dis_ver;
					t->x = p->i - p->h;
					t->y = p->j - p->l;
				}
			}
			p->j++;
		}
		p->i++;
	}
	if (t->x == - (t->l_plateau + t->h_plateau) || t->y == - (t->l_plateau + t->h_plateau))
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
					t->enemy = t->enemy - 32;
					distanceh1(t);
					distanceh2(t);
					distancev1(t);
					distancev2(t);
					t->enemy = t->enemy + 32;
				}
				if (ft_power(t->dis_hor, 2) + ft_power(t->dis_ver, 2) <= ft_power(t->dis_x, 2) + ft_power(t->dis_y, 2))
				{
					t->dis_x = t->dis_hor;
					t->dis_y = t->dis_ver;
					t->x = p->i - p->h;
					t->y = p->j - p->l;
				}
			}
			p->j++;
		}
		p->i++;
	}
}
