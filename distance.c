#include "filler.h"

long	tmp_distance(t_struct *t)
{
	return (ft_power(t->dis_hor, 2) + ft_power(t->dis_ver, 2));
}

long	distance(t_struct *t)
{
	return (ft_power(t->dis_x, 2) + ft_power(t->dis_y, 2));
}
