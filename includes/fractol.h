/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:01:13 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/15 10:46:06 by nrechati         ###   ########.fr       */
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
# include <limits.h>
# include "libft.h"
# define FAILURE -1
# define SUCCESS 0
# define FALSE 0
# define TRUE 1
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SH 3
# define BLACK 0x000000
# define WHITE 0xffffff
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define ORANGE 0xff7f24
# define KEYPRESSMASK (1L << 0)
# define KEYPRESS 2

typedef struct	s_comp
{
	double	re;
	double	im;
}				t_comp;

typedef struct	s_mlx
{
	int			c;
	int			h;
	int			h2;
	int			w;
	int			w2;
	int			*img_str;
	int			img_size;
	int			frac_nbr;
	int			i;
	double		x_pad;
	double		y_pad;
	double		zoom;
	double		iter;
	t_comp		julia;
	void		*ptr;
	void		*img;
	void		*win;
	void		*fractal;
}				t_mlx;

int				is_mandelbrot(t_mlx *mlx, int x, int y);
int				is_julia(t_mlx *mlx, int x, int y);
int				is_burning_ship(t_mlx *mlx, int x, int y);
int				draw_fractol(t_mlx *mlx, int flag
						, int (*fractal)(t_mlx*, int, int));
void			draw_menu(t_mlx *mlx);
int				usage(char *error);
void			init_mlx(t_mlx *mlx);
void			init_scope(t_mlx *mlx);
int				get_color(t_mlx *mlx);
void			ft_close(t_mlx *mlx);
void			ft_zoom(t_mlx *mlx, int key);
void			ft_iterate(t_mlx *mlx, int key);
void			ft_move(t_mlx *mlx, int key);
void			ft_reset(t_mlx *mlx);
void			ft_next(t_mlx *mlx);
void			ft_color(t_mlx *mlx);

#endif
