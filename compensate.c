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

void	compensate(t_piece *v)
{
	hauteur(v, 0, 0, 1);
	largeur(v, 0, 0, 1);
}

void	hauteur(t_piece *v, int i, int j, int sig)
{
	v->h = 0;
	i = -1;
	while (v->piece[++i])
	{
		j = -1;
		while (v->piece[i][++j])
		{
			if (v->piece[i][j] == '*')
				sig = 0;
		}
		if (sig == 1)
			(v->h)++;
	}
}

void	largeur(t_piece *v, int i, int j, int sig)
{
	sig = 1;
	v->l = 0;
	j = -1;
	while (v->piece[0][++j])
	{
		i = -1;
		while (v->piece[++i])
		{
			if (v->piece[i][j] == '*')
				sig = 0;
		}
		if (sig == 1)
			(v->l)++;
	}
}
