/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_coor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 22:56:47 by vinvimo           #+#    #+#             */
/*   Updated: 2017/09/18 22:56:50 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	put_coor(t_piece *v, int i, int j)
{
	int	n;

	n = 0;
	i = -1;
	while (v->piece[++i])
	{
		j = -1;
		while (v->piece[i][++j])
			if (v->piece[i][j] == '*')
				n++;
	}
	v->coorx = ft_intnew(n + 1);
	v->coory = ft_intnew(n + 1);
	loop_coor(v, 0, 0, 0);
}

void	loop_coor(t_piece *v, int i, int j, int n)
{
	i = -1;
	while (v->piece[++i])
	{
		j = -1;
		while (v->piece[i][++j])
		{
			if (v->piece[i][j] == '*')
			{
				v->coorx[n] = i;
				v->coory[n] = j;
				n++;
			}
		}
		j = 0;
	}
	v->coorx[n] = -1;
	v->coory[n] = -1;
}
