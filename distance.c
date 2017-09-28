/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 22:56:16 by vinvimo           #+#    #+#             */
/*   Updated: 2017/09/28 23:32:15 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

long	distance(t_struct *t)
{
	return (ft_power(t->dis_x, 2) + ft_power(t->dis_y, 2));
}

int		greatest(t_struct *t, int plateau, int a, int b)
{
		if (a > -1 && a > plateau - b - 1)
		{
			t->sig = 0;
			return (a);
		}
		else if (b > -1 && a <= plateau - b - 1)
		{
			t->sig = 1;
			return (b);
		}
	return (0);
}
