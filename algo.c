#include "filler.h"

void algo(t_struct *t, t_piece *p)
{
	int sig;

	sig = 1;
	compensate(p);
	t->x = 0;
	t->y = 0;
	t->dis_x = 0;
	t->dis_y = 0;
	t->dis_hor = 0;
	t->dis_ver = 0;
	if (choose_targets(t, 0, 0) > 0 && borders(t) == 0)
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
	{
		p->i = 0;
		while (t->grid[p->i])
		{
			p->j = 0;
			while (t->grid[p->i][p->j])
			{
				loop_algo(t, p, sig);
				p->j++;
			}
			p->i++;
		}
	}
	ft_putnbr(t->x);
	ft_putchar(' ');
	ft_putnbr(t->y);
	ft_putchar('\n');
}

void loop_main_algo(t_struct *t, t_piece *p)
{
	t->i = p->i - p->top;
	t->j = p->j - p->left;
	if (check(t, p, t->grid) == 1)
	{
		t->i = p->i;
		t->j = p->j;
		if (p->i - p->top + p->bot <= t->h_plateau
		&& p->j - p->left + p->right <= t->l_plateau
		&& tmp_distance(t, p, '!') < distance(t))
		{
			t->dis_x = t->dis_hor;
			t->dis_y = t->dis_ver;
			t->x = p->i - p->top;
			t->y = p->j - p->left;
		}
	}
}

void loop_algo(t_struct *t, t_piece *p, int sig)
{
	t->i = p->i - p->top;
	t->j = p->j - p->left;
	if (check(t, p, t->grid) == 1)
	{
		t->i = p->i;
		t->j = p->j;
		if (p->i - p->top + p->bot <= t->h_plateau
		&& p->j - p->left + p->right <= t->l_plateau
		&& (tmp_distance(t, p, t->enemy) < distance(t) || sig == 1))
		{
			sig = 0;
			t->dis_x = t->dis_hor;
			t->dis_y = t->dis_ver;
			t->x = p->i - p->top;
			t->y = p->j - p->left;
		}
	}
}
