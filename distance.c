/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 22:56:16 by vinvimo           #+#    #+#             */
/*   Updated: 2017/09/29 23:12:06 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
