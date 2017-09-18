/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 22:55:20 by vinvimo           #+#    #+#             */
/*   Updated: 2017/09/18 22:55:22 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

# define ERRORCHECK(x) if (!x) return (-1)
# define BUFF_SIZE 100

typedef struct		s_struct
{
	int				x;
	int				y;
	int				i;
	int				j;
	int				superposition;
	long			l_plateau;
	long			h_plateau;
	int				player_number;
	char			*player_name;
	char			c;
	char			c_maj;
	char			enemy;
	int				dis_hor;
	int				dis_ver;
	int				dis_x;
	int				dis_y;
	char			**grid;
}					t_struct;

typedef struct		s_piece
{
	char			**piece;
	int				l_carre;
	int				h_carre;
	int				l;
	int				h;
	int				i;
	int				j;
	int				*coorx;
	int				*coory;
}					t_piece;

typedef struct		s_gnl
{
	char			*content;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;

void				initialize(t_struct *t, t_piece *p);
void				players(t_struct *t, char *line, int *i, int j);
void				plate(t_struct *t, char **line, int *i, int *sig1);
void				piece(t_piece *p, char *line, int *i, int *sig2);
void				copy_plate(t_struct *t, char **line, int *sig1);
void				copy_piece(t_struct *t, t_piece *p, char **line, int *sig2);
void				solve(t_struct *t, t_piece *p, char *line);
int					get_next_line(const int fd, char **line);
int					*ft_intnew(size_t size);
char				**create_tab(int i, int j);
void				compensate(t_piece *v);
void				hauteur(t_piece *v, int i, int j, int sig);
void				largeur(t_piece *v, int i, int j, int sig);
void				put_coor(t_piece *v, int i, int j);
void				loop_coor(t_piece *v, int i, int j, int n);
int					check(t_struct *t, t_piece *p, char **grid);
void				distanceh1(t_struct *t, char enemy);
void				distanceh2(t_struct *t, char enemy);
void				distancev1(t_struct *t, char enemy);
void				distancev2(t_struct *t, char enemy);
long				tmp_distance(t_struct *t);
long				distance(t_struct *t);
void				init_algo(t_struct *t, t_piece *p);
void				algo(t_struct *t, t_piece *p);
void				loop_algo(t_struct *t, t_piece *p);
void				loop_init_algo(t_struct *t, t_piece *p);
long				ft_print(char **data, int fd);

#endif
