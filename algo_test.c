#include "filler.h"

void algo(t_struct *t, t_piece *p)
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
	if (t->x == -(t->l_plateau + t->h_plateau)
		|| t->y == -(t->l_plateau + t->h_plateau))
		init_algo(t, p);
	ft_putnbr(t->x);
	ft_putchar(' ');
	ft_putnbr(t->y);
	ft_putchar('\n');
}

void init_algo(t_struct *t, t_piece *p)
{
	t->x = 0;
	t->y = 0;
	p->i = 0;
	while (t->grid[p->i])
	{
		p->j = 0;
		while (t->grid[p->i][p->j])
		{
			loop_init_algo(t, p);
			p->j++;
		}
		p->i++;
	}
}

void loop_algo(t_struct *t, t_piece *p)
{
	t->i = p->i - p->top;
	t->j = p->j - p->left;
	if (check(t, p, t->grid) == 1)
	{
		t->i = p->i;
		t->j = p->j;
		if (p->i - p->top + p->bot <= t->h_plateau
			&& p->j - p->left + p->right <= t->l_plateau
			&& tmp_distance(t, p, t->enemy) < distance(t))
		{
			t->dis_x = t->dis_hor;
			t->dis_y = t->dis_ver;
			t->x = p->i - p->top;
			t->y = p->j - p->left;
		}
	}
}

void loop_init_algo(t_struct *t, t_piece *p)
{
	t->i = p->i - p->top;
	t->j = p->j - p->left;
	if (check(t, p, t->grid) == 1)
	{
		t->i = p->i;
		t->j = p->j;
		if (p->i - p->top + p->bot <= t->h_plateau
			&& p->j - p->left + p->right <= t->l_plateau
			&& tmp_distance(t, p, t->enemy - 32) < distance(t))
		{
			t->dis_x = t->dis_hor;
			t->dis_y = t->dis_ver;
			t->x = p->i - p->top;
			t->y = p->j - p->left;
		}
	}
}
