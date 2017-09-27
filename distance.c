/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 22:56:16 by vinvimo           #+#    #+#             */
/*   Updated: 2017/09/27 22:27:44 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

long	distance(t_struct *t)
{
	return (ft_power(t->dis_x, 2) + ft_power(t->dis_y, 2));
}

int		greatest(int a, int b)
{
	if (a > b)
		b = a;
	else if (a <= b)
		a = b;
	return (a);
}
