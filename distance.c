#include "filler.h"

void	distanceh1(t_struct *s)
{
	int	sig;
	int	c;
	int	i;
	int	j;

	sig = 0;
	c = 0;
	j = s->j;
	while (s->grid[0][j])
	{
		i = -1;
		while (s->grid[++i])
		{
			if (s->grid[i][j] == s->enemy)
				sig = 1;
		}
		if (sig == 0)
			c++;
		j++;
	}
	if (sig == 1)
		s->dis_hor = c - 1;
}

void	distanceh2(t_struct *s)
{
	int	sig;
	int	c;
	int	i;
	int	j;

	sig = 0;
	c = 0;
	j = s->j;
	while (j >= 0)
	{
		i = -1;
		while (s->grid[++i])
		{
			if (s->grid[i][j] == s->enemy)
				sig = 1;
		}
		if (sig == 0)
			c++;
		j--;
	}
	if (sig == 1)
		s->dis_hor = c - 1;
}

void	distancev1(t_struct *s)
{
	int	sig;
	int	c;
	int	i;
	int	j;

	sig = 0;
	c = 0;
	i = s->i;
	while (s->grid[i])
	{
		j = -1;
		while (s->grid[i][++j])
		{
			if (s->grid[i][j] == s->enemy)
				sig = 1;
		}
		if (sig == 0)
			c++;
		i++;
	}
	if (sig == 1)
		s->dis_ver = c - 1;
}

void	distancev2(t_struct *s)
{
	int	sig;
	int	c;
	int	i;
	int	j;

	sig = 0;
	c = 0;
	i = s->i;
	while (i >= 0)
	{
		j = -1;
		while (s->grid[i][++j])
		{
			if (s->grid[i][j] == s->enemy)
				sig = 1;
		}
		if (sig == 0)
			c++;
		i--;
	}
	if (sig == 1)
		s->dis_ver = c - 1;
}
