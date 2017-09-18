/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 22:57:22 by vinvimo           #+#    #+#             */
/*   Updated: 2017/09/18 22:57:25 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	initialize(t_struct *t, t_piece *p)
{
	t->x = 0;
	t->y = 0;
	t->i = 0;
	t->j = 0;
	t->superposition = 0;
	t->l_plateau = 0;
	t->h_plateau = 0;
	t->grid = NULL;
	p->piece = NULL;
	p->l_carre = 0;
	p->h_carre = 0;
	p->l = 0;
	p->h = 0;
	p->i = 0;
	p->j = 0;
	p->coorx = NULL;
	p->coory = NULL;
}
