/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compensate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 22:55:53 by vinvimo           #+#    #+#             */
/*   Updated: 2017/09/18 22:55:56 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	compensate(t_piece *p)
{
	hauteur(p, 0, 0, 1);
	largeur(p, 0, 0, 1);
	bottom_line(p, 0, 0, 1);
	right_line(p, 0, 0, 1);
}

void	hauteur(t_piece *p, int i, int j, int sig)
{
	p->h = 0;
	i = -1;
	while (p->piece[++i])
	{
		j = -1;
		while (p->piece[i][++j])
		{
			if (p->piece[i][j] == '*')
				sig = 0;
		}
		if (sig == 1)
			(p->h)++;
	}
}

void	largeur(t_piece *p, int i, int j, int sig)
{
	p->l = 0;
	j = -1;
	while (p->piece[0][++j])
	{
		i = -1;
		while (p->piece[++i])
		{
			if (p->piece[i][j] == '*')
				sig = 0;
		}
		if (sig == 1)
			(p->l)++;
	}
}

void	bottom_line(t_piece *p, int i, int j, int sig)
{
	int	c;

	c = 0;
	i = p->h_carre;
	while (--i >= 0)
	{
		j = -1;
		while (p->piece[i][++j])
		{
			if (p->piece[i][j] == '*')
				sig = 0;
		}
		if (sig == 1)
			c++;
	}
	p->bline = p->h_carre - c;
}

void	right_line(t_piece *p, int i, int j, int sig)
{
	int	c;

	c = 0;
	j = p->l_carre;
	while (--j >= 0)
	{
		i = -1;
		while (p->piece[++i])
		{
			if (p->piece[i][j] == '*')
				sig = 0;
		}
		if (sig == 1)
			c++;
	}
	p->rline = p->l_carre - c;
}
