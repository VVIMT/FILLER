#include "filler.h"

int		greatest(int a, int b)
{
	if (a > b)
		b = a;
	else if (a <= b)
		a = b;
	return (a);
}

long	choose_targets(t_struct *t)
{
	int	a;
	int	b;

	a = sweeph1(t);
	b = sweeph2(t);
	greatest(a, b);
	if (a > -1)
	{
		if (t->grid[0][a] == '.')
			t->grid[0][a] = '1';
		if (t->grid[t->h_plateau - 1][a] == '.')
			t->grid[t->h_plateau - 1][a] = '2';
	}
	a = sweepv1(t);
	b = sweepv2(t);
	greatest(a, b);
	if (a > -1)
	{
		if (t->grid[a][t->l_plateau] == '.')
			t->grid[a][t->l_plateau] = '3';
		if (t->grid[a][0] == '.')
			t->grid[a][0] = '4';
	}
	return (0);
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
			return (j - 1);
		else if (sig2 == 1)
			return (-1);
		if (sig3 == 1)
			sig1 = 1;
		j++;
	}
	return (-1);
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
			return (j + 1);
		else if (sig2 == 1)
			return (-1);
		if (sig3 == 1)
			sig1 = 1;
		j--;
	}
	return (-1);
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
			return (i - 1);
		else if (sig2 == 1)
			return (-1);
		if (sig3 == 1)
			sig1 = 1;
		i++;
	}
	return (-1);
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
			return (i + 1);
		else if (sig2 == 1)
			return (-1);
		if (sig3 == 1)
			sig1 = 1;
		i--;
	}
	return (-1);
}
