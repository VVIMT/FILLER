#include "filler.h"

long	choose_targets(t_struct *t)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (sweeph1(t) > sweeph2(t))
		a = 1;
	else
		a = 2;
	if (sweepv1(t) > sweepv2(t))
		b = 4;
	else
		b = 8;
	return (a + b);
}

int		sweeph1(t_struct *t)
{
	int	sig1;
	int	sig2;
	int	sig3;
	int	i;
	int	j;

	sig1 = 0;
	sig2 = 0;
	j = 0;
	while (t->grid[0][j])
	{
		sig3 = 0;
		i = -1;
		while (t->grid[++i])
		{
			if (t->grid[i][j] == t->c || t->grid[i][j] == t->c_maj)
				sig3 = 1;
			if (t->grid[i][j] == t->enemy
			|| t->grid[i][j] == t->enemy - 32)
				sig2 = 1;
		}
		if (sig2 == 1 && sig1 == 1 && j > 0)
		{
			if (t->grid[0][j - 1] == '.')
				t->grid[0][j - 1] = '1';
			if (t->grid[t->h_plateau - 1][j - 1] == '.')
				t->grid[t->h_plateau - 1][j - 1] = '2';
			return (j);
		}
		else if (sig2 == 1)
			return (0);
		if (sig3 == 1)
			sig1 = 1;
		j++;
	}
	return (0);
}

int		sweeph2(t_struct *t)
{
	int	sig1;
	int	sig2;
	int	sig3;
	int	i;
	int	j;

	sig1 = 0;
	sig2 = 0;
	j = t->l_plateau - 1;
	while (j >= 0)
	{
		sig3 = 0;
		i = -1;
		while (t->grid[++i])
		{
			if (t->grid[i][j] == t->c || t->grid[i][j] == t->c_maj)
				sig3 = 1;
			if (t->grid[i][j] == t->enemy
			|| t->grid[i][j] == t->enemy - 32)
				sig2 = 1;
		}
		if (sig2 == 1 && sig1 == 1 && j < t->l_plateau - 1)
		{
			if (t->grid[0][j + 1] == '.')
				t->grid[0][j + 1] = '3';
			if (t->grid[t->h_plateau - 1][j + 1] == '.')
				t->grid[t->h_plateau - 1][j + 1] = '4';
			return (j);
		}
		else if (sig2 == 1)
			return (0);
		if (sig3 == 1)
			sig1 = 1;
		j--;
	}
	return (0);
}

int		sweepv1(t_struct *t)
{
	int	sig1;
	int	sig2;
	int	sig3;
	int	i;
	int	j;

	sig1 = 0;
	sig2 = 0;
	i = 0;
	while (t->grid[i])
	{
		sig3 = 0;
		j = -1;
		while (t->grid[i][++j])
		{
			if (t->grid[i][j] == t->c || t->grid[i][j] == t->c_maj)
				sig3 = 1;
			if (t->grid[i][j] == t->enemy
			|| t->grid[i][j] == t->enemy - 32)
				sig2 = 1;
		}
		if (sig2 == 1 && sig1 == 1 && i > 0)
		{
			if (t->grid[i - 1][t->l_plateau] == '.')
				t->grid[i - 1][t->l_plateau] = '5';
			if (t->grid[i - 1][0] == '.')
				t->grid[i - 1][0] = '6';
			return (i);
		}
		else if (sig2 == 1)
			return (0);
		if (sig3 == 1)
			sig1 = 1;
		i++;
	}
	return (0);
}

int		sweepv2(t_struct *t)
{
	int	sig1;
	int	sig2;
	int	sig3;
	int	i;
	int	j;

	sig1 = 0;
	sig2 = 0;
	i = t->h_plateau - 1;
	while (i >= 0)
	{
		sig3 = 0;
		j = -1;
		while (t->grid[i][++j])
		{
			if (t->grid[i][j] == t->c || t->grid[i][j] == t->c_maj)
				sig3 = 1;
			if (t->grid[i][j] == t->enemy
			|| t->grid[i][j] == t->enemy - 32)
				sig2 = 1;
		}
		if (sig2 == 1 && sig1 == 1 && i < t->h_plateau - 1)
		{
			if (t->grid[i + 1][t->l_plateau] == '.')
				t->grid[i + 1][t->l_plateau] = '7';
			if (t->grid[i + 1][0] == '.')
				t->grid[i + 1][0] = '8';
			return (i);
		}
		else if (sig2 == 1)
			return (0);
		if (sig3 == 1)
			sig1 = 1;
		i--;
	}
	return (0);
}
