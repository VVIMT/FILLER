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
	int				superposition;
	long			l_plateau;
	long			h_plateau;
	int				player_number;
	char			c;
	char			c_maj;
	char			enemy;
	long long		dis_tmp1;
	long long		dis_tmp2;
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
	int				right;
	int				top;
	int				bot;
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
long long			tmp_distance(t_struct *t, t_piece *p, char enemy);
long long			pythagore(t_struct *t, t_piece *p, int i, int c);
void				distance_r(t_struct *t, t_piece *p, char enemy);
void				distance_l(t_struct *t, t_piece *p, char enemy);
void				algo(t_struct *t, t_piece *p);
void				loop_algo(t_struct *t, t_piece *p);

#endif
