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

void	put_coor(t_piece *p, int i, int j)
{
	int	n;

	n = 0;
	i = -1;
	while (p->piece[++i])
	{
		j = -1;
		while (p->piece[i][++j])
			if (p->piece[i][j] == '*')
				n++;
	}
	p->coorx = ft_intnew(n + 1);
	p->coory = ft_intnew(n + 1);
	loop_coor(p, 0, 0, 0);
	shape(p);
}

void	loop_coor(t_piece *p, int i, int j, int n)
{
	i = -1;
	while (p->piece[++i])
	{
		j = -1;
		while (p->piece[i][++j])
		{
			if (p->piece[i][j] == '*')
			{
				p->coorx[n] = i;
				p->coory[n] = j;
				n++;
			}
		}
		j = 0;
	}
	p->coorx[n] = -1;
	p->coory[n] = -1;
}

void	shape(t_piece *p)
{
	if (p->bot - p->top >= p->right - p->left)
		p->ver = 1;
	else
		p->hor = 1;
}
