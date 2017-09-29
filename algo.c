#include "filler.h"

void algo(t_struct *t, t_piece *p)
{
	compensate(p);
	t->x = t->l_plateau + t->h_plateau;
	t->y = t->l_plateau + t->h_plateau;
	t->dis = (t->l_plateau * t->l_plateau) + (t->l_plateau * t->l_plateau);
	/*if (choose_targets(t, 0, 0) > 0 && borders(t) == 0)
	{
		p->i = 0;
		while (t->grid[p->i])
		{
			p->j = 0;
			while (t->grid[p->i][p->j])
			{
				loop_main_algo(t, p);
				p->j++;
			}
			p->i++;
		}
	}
	else
	{*/
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
//	}
	ft_putnbr(t->x);
	ft_putchar(' ');
	ft_putnbr(t->y);
	ft_putchar('\n');
}

void loop_main_algo(t_struct *t, t_piece *p)
{
	long long	a;

	t->i = p->i - p->top;
	t->j = p->j - p->left;
	if (check(t, p, t->grid) == 1)
	{
		t->i = p->i;
		t->j = p->j;
		a = tmp_distance(t, p, '!');
		if (p->i - p->top + p->bot <= t->h_plateau
		&& p->j - p->left + p->right <= t->l_plateau
		&& a < t->dis)
		{
			t->dis = a;
			t->x = p->i - p->top;
			t->y = p->j - p->left;
		}
	}
}

void loop_algo(t_struct *t, t_piece *p)
{
	long long	a;
	long long	b;

	t->i = p->i - p->top;
	t->j = p->j - p->left;
	if (check(t, p, t->grid) == 1)
	{
		t->i = p->i;
		t->j = p->j;
		a = tmp_distance(t, p, t->enemy);
		b = tmp_distance(t, p, t->enemy - 32);
		if (a > b)
			a = b;
		if (p->i - p->top + p->bot <= t->h_plateau
		&& p->j - p->left + p->right <= t->l_plateau
		&& a < t->dis)
		{
			t->dis = a;
			t->x = p->i - p->top;
			t->y = p->j - p->left;
		}
	}
}
