#include "filler.h"

long	tmp_distance(t_struct *t, char enemy)
{
	sweeph1(t);
	sweeph2(t);
	sweepv1(t);
	sweepv2(t);
	return (ft_power(t->dis_hor, 2) + ft_power(t->dis_ver, 2));
}

int		sweeph1(t_struct *t)
{
	int	sig1;
	int	sig2;
	int	i;
	int	j;

	sig1 = 0;
	sig2 = 0;
	j = 0;
	while (t->grid[0][j])
	{
		i = -1;
		while (t->grid[++i])
		{
			if (t->grid[i][j] == t->enemy
			|| t->grid[i][j] == t->enemy - 32)
				sig2 = 1;
		}
		if (sig2 == 1)
			break ;
		j++;
	}
	return (0);
}

int		sweeph2(t_struct *t)
{
	int	sig1;
	int	sig2;
	int	i;
	int	j;

	sig1 = 0;
	sig2 = 0;
	j = t->l_plateau - 1;
	while (j >= 0)
	{
		i = -1;
		while (t->grid[++i])
		{
			if (t->grid[i][j] == t->enemy
			|| t->grid[i][j] == t->enemy - 32)
				sig2 = 1;
		}
		if (sig2 == 1)
			break ;
		j--;
	}
	return (0);
}

int		sweepv1(t_struct *t)
{
	int	sig1;
	int	sig2;
	int	i;
	int	j;

	sig1 = 0;
	sig2 = 0;
	i = 0;
	while (t->grid[i])
	{
		j = -1;
		while (t->grid[i][++j])
		{
			if (t->grid[i][j] == t->enemy
			|| t->grid[i][j] == t->enemy - 32)
				sig2 = 1;
		}
		if (sig2 == 1)
			break ;
		i++;
	}
	return (0);
}

int		sweepv2(t_struct *t)
{
	int	sig1;
	int	sig2;
	int	i;
	int	j;

	sig1 = 0;
	sig2 = 0;
	i = t->h_plateau - 1;
	while (i >= 0)
	{
		j = -1;
		while (t->grid[i][++j])
		{
			if (t->grid[i][j] == t->enemy
			|| t->grid[i][j] == t->enemy - 32)
				sig2 = 1;
		}
		if (sig2 == 1)
			break ;
		i--;
	}
	return (0);
}
