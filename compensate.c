/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compensate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 18:37:19 by vinvimo           #+#    #+#             */
/*   Updated: 2017/10/01 18:37:23 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	compensate(t_piece *p)
{
	top_line(p, -1);
	left_line(p, -1);
	bottom_line(p, -1);
	right_line(p, -1);
}

void	top_line(t_piece *p, int i)
{
	p->top = p->coorx[0];
	while (p->coorx[++i] != -1)
		if (p->coorx[i] < p->top)
			p->top = p->coorx[i];
}

void	left_line(t_piece *p, int i)
{
	p->left = p->coory[0];
	while (p->coory[++i] != -1)
		if (p->coory[i] < p->left)
			p->left = p->coory[i];
}

void	bottom_line(t_piece *p, int i)
{
	p->bot = p->coorx[0];
	while (p->coorx[++i] != -1)
		if (p->coorx[i] > p->bot)
			p->bot = p->coorx[i];
}

void	right_line(t_piece *p, int i)
{
	p->right = p->coory[0];
	while (p->coory[++i] != -1)
		if (p->coory[i] > p->right)
			p->right = p->coory[i];
}
