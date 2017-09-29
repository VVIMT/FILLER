/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 22:55:20 by vinvimo           #+#    #+#             */
/*   Updated: 2017/09/29 22:00:40 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

# define ERRORCHECK(x) if (!x) return (-1)
# define BUFF_SIZE 150

typedef struct		s_struct
{
	int				fd;
	int				x;
	int				y;
	int				i;
	int				j;
	int				a;
	int				b;
	int				superposition;
	long			l_plateau;
	long			h_plateau;
	int				player_number;
	char			c;
	char			c_maj;
	char			enemy;
	int				tborder;
	int				bborder;
	int				lborder;
	int				rborder;
	long long		dis_hor;
	long long		dis_ver;
	long long		dis_tmp1;
	long long		dis_tmp2;
	long long		dis_x;
	long long		dis_y;
	long long		dis;
	char			**grid;
	int				sig;
}					t_struct;

typedef struct		s_piece
{
	char			**piece;
	int				l_carre;
	int				h_carre;
	int				left;
	int				top;
	int				bot;
	int				right;
	int				ver;
	int				hor;
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
void				players(t_struct *t, char *line, int *i);
void				plate(t_struct *t, char **line, int *i, int *sig1);
void				piece(t_piece *p, char *line, int *i, int *sig2);
void				copy_plate(t_struct *t, char **line, int *sig1);
void				copy_piece(t_struct *t, t_piece *p, char **line, int *sig2);
void				solve(t_struct *t, t_piece *p, char *line);
int					get_next_line(const int fd, char **line);
int					*ft_intnew(size_t size);
char				**create_tab(int i, int j);
void				compensate(t_piece *p);
void				top_line(t_piece *p, int i);
void				left_line(t_piece *p, int i);
void				bottom_line(t_piece *p, int i);
void				right_line(t_piece *p, int i);
void				put_coor(t_piece *p, int i, int j);
void				loop_coor(t_piece *p, int i, int j, int n);
void				shape(t_piece *p);
int					check(t_struct *t, t_piece *p, char **grid);
int					borders(t_struct *t);
long long			tmp_distance(t_struct *t, t_piece *p, char enemy);
int					distanceh1(t_struct *t, t_piece *p, char enemy);
int					distanceh2(t_struct *t, char enemy);
int					distancev1(t_struct *t, t_piece *p, char enemy);
int					distancev2(t_struct *t, char enemy);
int					greatest(t_struct *t, int plateau, int a, int b);
int					choose_targets(t_struct *t, int i, int j);
int					sweeph1(t_struct *t, int sig1, int sig2);
int					sweeph2(t_struct *t, int sig1, int sig2);
int					sweepv1(t_struct *t, int sig1, int sig2);
int					sweepv2(t_struct *t, int sig1, int sig2);
long				distance(t_struct *t);
void				algo(t_struct *t, t_piece *p);
void				init_algo(t_struct *t, t_piece *p);
void				loop_main_algo(t_struct *t, t_piece *p);
void				loop_algo(t_struct *t, t_piece *p);
void				loop_init_algo(t_struct *t, t_piece *p);
long				ft_print(char **data, int fd);

#endif
