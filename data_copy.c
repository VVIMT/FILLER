/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 22:57:00 by vinvimo           #+#    #+#             */
/*   Updated: 2017/09/18 22:57:07 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	players(t_struct *t, char *line, int *i, int j)
{
	*i = 0;
	if (ft_strncmp(line + *i, "$$$ exec p", 10) == 0)
		*i = *i + 10;
	t->player_number = ft_atoi(line + *i);
	while (line[*i] && line[*i] != '[')
		(*i)++;
	j = 0;
	while (line[*i + j] && line[*i + j] != ']')
		j++;
	t->player_name = ft_strnew(j + 1);
	ft_bzero(t->player_name, j + 1);
	ft_strncpy(t->player_name, line + *i + 1, j - 1);
	if (t->player_number == 1)
	{
		t->c = 'o';
		t->c_maj = 'O';
		t->enemy = 'x';
	}
	else if (t->player_number == 2)
	{
		t->c = 'x';
		t->c_maj = 'X';
		t->enemy = 'o';
	}
	*i = ft_strlen(line);
}

void	plate(t_struct *t, char **line, int *i, int *sig1)
{
	*i = *i + 8;
	t->h_plateau = ft_atoi(*line + *i);
	while ((*line)[*i] && (*line)[*i] >= '0' && (*line)[*i] <= '9')
		(*i)++;
	while ((*line)[*i] && (*line)[*i] == ' ')
		(*i)++;
	t->l_plateau = ft_atoi(*line + *i);
	t->grid = create_tab(t->h_plateau, t->l_plateau);
	*sig1 = 1;
	ft_strdel(line);
	get_next_line(0, line);
}

void	piece(t_piece *p, char *line, int *i, int *sig2)
{
	*i = *i + 6;
	p->h_carre = ft_atoi(line + *i);
	while (line[*i] && line[*i] >= '0' && line[*i] <= '9')
		(*i)++;
	while (line[*i] && line[*i] == ' ')
		(*i)++;
	p->l_carre = ft_atoi(line + *i);
	p->piece = create_tab(p->h_carre, p->l_carre);
	*sig2 = 1;
}

void	copy_plate(t_struct *t, char **line, int *sig1)
{
	int	j;

	t->i = 0;
	while (t->i < t->h_plateau)
	{
		ft_strdel(line);
		get_next_line(0, line);
		j = 0;
		while (((*line)[j] >= '0' && (*line)[j] <= '9')
		|| (*line)[j] == ' ')
			j++;
		ft_strcpy(*(t->grid + t->i), *line + j);
		(t->i)++;
	}
	*sig1 = 2;
}

void	copy_piece(t_struct *t, t_piece *p, char **line, int *sig2)
{
	t->i = 0;
	while (t->i < p->h_carre)
	{
		ft_strdel(line);
		get_next_line(0, line);
		ft_strcpy(*(p->piece + t->i), *line);
		(t->i)++;
	}
	*sig2 = 2;
}
