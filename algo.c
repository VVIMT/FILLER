#include "filler.h"

void	sweep(t_struct *t, t_piece *p)
{
	compensate(p);
	t->x = 0;
	t->y = 0;
	t->dis = (t->l_plateau * t->l_plateau) + (t->l_plateau * t->l_plateau);
	p->i = 0;
	while (t->grid[p->i])
	{
		p->j = 0;
		while (t->grid[p->i][p->j])
		{
			algo(t, p);
			p->j++;
		}
		p->i++;
	}
	ft_putnbr(t->x);
	ft_putchar(' ');
	ft_putnbr(t->y);
	ft_putchar('\n');
}

void	algo(t_struct *t, t_piece *p)
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
