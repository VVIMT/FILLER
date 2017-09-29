#include "filler.h"

int		choose_targets(t_struct *t, int i, int j)
{
	int	area1 = 0;
	int	area2 = 0;

	t->sig = 0;
	t->a = sweeph1(t, 0, 0);
	t->b = sweeph2(t, 0, 0);
	j = greatest(t, t->l_plateau, t->a, t->b);
	if (t->sig == 0)
		area1 = t->h_plateau * j;
	else if (t->sig == 1)
		area1 = t->h_plateau * (t->l_plateau - j - 1);
	t->a = sweepv1(t, 0, 0);
	t->b = sweepv2(t, 0, 0);
	i = greatest(t, t->h_plateau, t->a, t->b);
	if (t->sig == 0)
		area2 = t->l_plateau * i;
	else if (t->sig == 1)
		area2 = t->l_plateau * (t->h_plateau - i - 1);
	if (area1 > area2 && j > 0)
	{
		if (t->grid[0][j] == '.')
			t->grid[0][j] = '!';
		if (t->grid[t->h_plateau - 1][j] == '.')
			t->grid[t->h_plateau - 1][j] = '!';

//		if (t->grid[0][t->l_plateau/2] == '.')
//			t->grid[0][t->l_plateau/2] = '!';
//		if (t->grid[t->h_plateau - 1][t->l_plateau/2] == '.')
//			t->grid[t->h_plateau - 1][t->l_plateau/2] = '!';

		return (1);
	}
	else if (area1 <= area2 && i > 0)
	{
		if (t->grid[i][t->l_plateau - 1] == '.')
			t->grid[i][t->l_plateau - 1] = '!';
		if (t->grid[i][0] == '.')
			t->grid[i][0] = '!';

//		if (t->grid[t->h_plateau/2][t->l_plateau - 1] == '.')
//			t->grid[t->h_plateau/2][t->l_plateau - 1] = '!';
//		if (t->grid[t->h_plateau/2][0] == '.')
//			t->grid[t->h_plateau/2][0] = '!';

		return (1);
	}
	return (0);
}

int		sweeph1(t_struct *t, int sig1, int sig2)
{
	int	i;
	int	j;

	j = 0;
	while (t->grid[0][j])
	{
		i = -1;
		while (t->grid[++i])
		{
			if (t->grid[i][j] == t->c || t->grid[i][j] == t->c_maj)
				sig1 = 1;
			if (t->grid[i][j] == t->enemy
			|| t->grid[i][j] == t->enemy - 32)
				sig2 = 1;
		}
		if (sig1 == 1 && sig2 == 1 && j >= 0)
			return (j);
		else if (sig1 == 0 && sig2 == 1)
			return (-1);
		j++;
	}
	return (-1);
}

int		sweeph2(t_struct *t, int sig1, int sig2)
{
	int	i;
	int	j;

	j = t->l_plateau - 1;
	while (j >= 0)
	{
		i = -1;
		while (t->grid[++i])
		{
			if (t->grid[i][j] == t->c || t->grid[i][j] == t->c_maj)
				sig1 = 1;
			if (t->grid[i][j] == t->enemy
			|| t->grid[i][j] == t->enemy - 32)
				sig2 = 1;
		}
		if (sig1 == 1 && sig2 == 1 && t->l_plateau - j - 1 >= 0)
			return (j);
		else if (sig1 == 0 && sig2 == 1)
			return (-1);
		j--;
	}
	return (-1);
}

int		sweepv1(t_struct *t, int sig1, int sig2)
{
	int	i;
	int	j;

	i = 0;
	while (t->grid[i])
	{
		j = -1;
		while (t->grid[i][++j])
		{
			if (t->grid[i][j] == t->c || t->grid[i][j] == t->c_maj)
				sig1 = 1;
			if (t->grid[i][j] == t->enemy
			|| t->grid[i][j] == t->enemy - 32)
				sig2 = 1;
		}
		if (sig1 == 1 && sig2 == 1 && i >= 0)
			return (i);
		else if (sig1 == 0 && sig2 == 1)
			return (-1);
		i++;
	}
	return (-1);
}

int		sweepv2(t_struct *t, int sig1, int sig2)
{
	int	i;
	int	j;

	i = t->h_plateau - 1;
	while (i >= 0)
	{
		j = -1;
		while (t->grid[i][++j])
		{
			if (t->grid[i][j] == t->c || t->grid[i][j] == t->c_maj)
				sig1 = 1;
			if (t->grid[i][j] == t->enemy
			|| t->grid[i][j] == t->enemy - 32)
				sig2 = 1;
		}
		if (sig1 == 1 && sig2 == 1 && t->h_plateau - i - 1 >= 0)
			return (i);
		else if (sig1 == 0 && sig2 == 1)
			return (-1);
		i--;
	}
	return (-1);
}
