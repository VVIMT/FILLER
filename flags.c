#include "filler.h"

int		choose_targets(t_struct *t, int tmp1, int tmp2)
{
	t->a = sweeph1(t, 0, 0, 0);
	t->b = sweeph2(t, 0, 0, 0);
	tmp1 = greatest(t->a, t->b);
	t->a = sweepv1(t, 0, 0, 0);
	t->b = sweepv2(t, 0, 0, 0);
	tmp2 = greatest(t->a, t->b);
	if (tmp1 > tmp2 && tmp1 > -1)
	{
		if (t->grid[0][tmp1] == '.')
			t->grid[0][tmp1] = '1';
		if (t->grid[t->h_plateau - 1][tmp1] == '.')
			t->grid[t->h_plateau - 1][tmp1] = '2';
		return (1);
	}
	else if (tmp1 <= tmp2 && tmp2 > -1)
	{
		if (t->grid[tmp2][t->l_plateau - 1] == '.')
			t->grid[tmp2][t->l_plateau - 1] = '1';
		if (t->grid[tmp2][0] == '.')
			t->grid[tmp2][0] = '2';
		return (2);
	}
	return (0);
}

int		sweeph1(t_struct *t, int sig1, int sig2, int sig3)
{
	int	i;
	int	j;

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

int		sweeph2(t_struct *t, int sig1, int sig2, int sig3)
{
	int	i;
	int	j;

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

int		sweepv1(t_struct *t, int sig1, int sig2, int sig3)
{
	int	i;
	int	j;

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

int		sweepv2(t_struct *t, int sig1, int sig2, int sig3)
{
	int	i;
	int	j;

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
