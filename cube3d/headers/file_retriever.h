/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_retriever.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:24:23 by yaziz             #+#    #+#             */
/*   Updated: 2021/01/08 17:34:34 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_RETRIEVER_H
# define FILE_RETRIEVER_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include "../sources/libft/libft.h"
# include "mlx_keys.h"
# define MV_SPEED 8
# define TRN_SPEED 0.04
# define MAX_INT 2147483647
# define SCL 0.15
# define P M_PI_2

typedef struct	s_bmpmeta
{
	int		fsize;
	int		offset;
	int		size;
	int		bpp;
	char	*file;
}				t_bmpmeta;

typedef struct	s_frame
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_frame;

typedef struct	s_sprite
{
	int		xm;
	int		ym;
	float	x;
	float	y;
	float	dis;
	float	angle;
	float	size;
	float	xp;
	float	yp;
	int		v;
}				t_sprite;

typedef struct	s_file
{
	char	**map;
	int		map_w;
	int		map_h;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	int		win_x;
	int		win_y;
	int		floor;
	int		ceil;
	int		lwidth;
	int		mapread;
	int		mapend;
}				t_file;

typedef struct	s_txt
{
	t_frame fr;
}				t_txt;

typedef struct	s_pt
{
	float x;
	float y;
}				t_pt;

typedef struct	s_tkn
{
	char	map;
	char	no;
	char	so;
	char	we;
	char	ea;
	char	r;
	char	s;
	char	f;
	char	c;
}				t_tkn;

typedef struct	s_player
{
	float	x;
	float	y;
	float	dir;
}				t_player;

typedef struct	s_ray
{
	float	x;
	float	y;
	float	dis;
	float	dir;
	int		up;
	int		right;
	t_pt	hit;
	int		hh;
	int		wallface;
	int		offh;
	int		offv;
}				t_ray;

typedef struct	s_dists
{
	float ydis;
	float xdis;
}				t_dists;

typedef struct	s_config
{
	int		singsq;
	float	defsize;
	float	rayspace;
	float	pslice;
}				t_config;

typedef struct	s_windat
{
	void *mlx;
	void *winp;
}				t_windat;

typedef struct	s_motion
{
	int up;
	int down;
	int leftm;
	int leftt;
	int rightm;
	int rightt;
}				t_motion;

t_ray			*g_ray;
t_config		g_config;
t_tkn			g_tkn;
t_player		g_player;
t_file			g_file;
t_frame			g_frame;
t_windat		g_windat;
t_txt			g_txt[5];
t_sprite		*g_spr;
int				g_sprcount;
t_motion		g_mot;
int				g_save;
t_bmpmeta		g_bmp;

void			tozero_tkn(void);
int				gnl(char **line, int fd);
void			write_exit(char *s);
void			params_verif(int ac, char **av);
void			treat_no(char *s);
void			treat_so(char *s);
void			treat_we(char *s);
void			treat_ea(char *s);
void			treat_s(char *s);
void			treat_f(char *s);
void			treat_c(char *s);
void			treat_r(char *s);
int				bigger(int a, int b);
int				countline(int currval, char *str);
void			check_before_map();
void			treat_m(char *element);
int				skip_spaces(char *s);
void			treat_element(char *element);
void			treat_line(char *line);
int				empty_line(char *line);
void			fill_spaces(char *str, int n);
int				linelength(char *str);
void			adjust_map();
void			verify_map(char **map, int w, int h);
void			assignplayerdir(char c);
void			assignplayerpos(int x, int y);
void			verify_player(char **map, int w, int h);
void			addsprite(t_sprite to_add);
void			makesprite(int xmap, int ymap);
void			checksprites(char **map, int w, int h);
void			retrieve_from(char *fn);
void			read_file(int ac, char **av);
void			initenv();
void			initenv();
void			draw2d();
void			castrays();
void			dirreset(int i);
void			load_textures();
void			next_2dframe();
void			makeamove();
void			freethemap();
void			freethatgame();
void			setbmp();
int				existing_sprite(int xmap, int ymap);
void			addpxl(int x, int y, int color);
void			drawvertical(int x, int y, int distance, int color);
void			clrimage();
void			load_textures();
int				get_txt_color(int txt, int x, int y);
void			texturize(int i, int txt, int dis, int k);
void			drawslice();
int				redcross(int key, void *useless);
int				is_wall(int x, int y);
int				is_spr(int x, int y);
void			dirreset(int i);
float			normangle(float angle);
void			checkhit(int i);
void			rayassigndis(int i, t_pt a, t_pt b);
void			checkvisib(int x, int y);
t_pt			horizontalcast(int i);
t_pt			verticalcast(int i);
void			castrays();
void			spritenewdis();
void			sortsprites();
int				distwall_sprite(int ray, int sprite);
void			drawsingsp(int k);
void			drawsprites();
void			rendersprites();
void			next_2dframe();
void			move_forward();
void			move_backward();
void			move_leftward2();
void			move_rightward2();
void			move_leftward();
void			move_rightward();
void			makeamove();
int				handleentry(int key, void *useless);
int				stopmot(int key, void *useless);
int				skipwhitesp(char **s);
int				fileargend(char *s, int f);
void			shouldspace(char *s, int f);
void			shouldnumber(char *s, int f);
void			shouldspaceskip(char **s, int f);
void			treatcolors(int *r, int *g, int *b, char **s);
void			mapnewline(char ***temp, char **element);
int				is_map_element(char x);
int				is_zsp(char x);
int				is_spr(int x, int y);
int				is_p(char x);
char			*trimpath(char *s);

#endif
