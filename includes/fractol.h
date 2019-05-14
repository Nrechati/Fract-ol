/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:01:13 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/13 15:48:57 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
#include <limits.h>
# include "libft.h"
# define USAGE "usage : ./fractol [fractal_name]"
# define RED 0x353037
# define GREEN 0x006c26
# define BLUE 0x166fe7
# define ORANGE 0xff7f24
# define KEYPRESSMASK (1L << 0)
# define KEYPRESS 2

typedef struct	s_mlx
{
	int			c;
	int			l;
	int			w;
	int			*img_str;
	int			img_size;
	void		*ptr;
	void		*img;
	void		*win;
}				t_mlx;

typedef struct	s_map
{
	int			**tab;
	double		pad;
	double		w_xpad;
	double		w_ypad;
	double		hpad;
	int			row;
	int			col;
	t_mlx		*mlx;
}				t_map;

typedef struct	s_pt
{
	double		x;
	double		y;
}				t_pt;

typedef struct	s_dna
{
	double		len;
	double		dx;
	double		dy;
	double		x;
	double		y;
	double		i;
}				t_dna;

typedef struct	s_comp
{
	double	re;
	double	im;
}				t_comp;

void			init_mlx(t_mlx *mlx);
void			init_dna(t_dna *dna);
void			init_map(t_mlx *mlx, t_map *map);
void			init_view(t_map *map);
void			iso_project(t_pt *pt, t_map *map, int index_x, int index_y);
void			para_project(t_pt *pt, t_map *map, int index_x, int index_y);
int				draw_fractol(t_mlx *mlx, t_map *map, int flag, char **av);
void			draw_menu(t_mlx *mlx);
void			ft_close(t_map *map);
void			ft_zoom(t_map *map, int key);
void			ft_alt(t_map *map, int key);
void			ft_move(t_map *map, int key);
void			ft_proj(t_map *map);
void			ft_color(t_map *map);
void			ft_rotate(t_map *map, int key);
void			init_img(t_mlx *mlx);
void			fill_pixel(t_mlx *mlx, int x, int y, int c);

#endif
