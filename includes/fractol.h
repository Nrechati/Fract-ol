/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:01:13 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/17 12:59:38 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <pthread.h>

# define FAILURE -1
# define SUCCESS 0
# define FALSE 0
# define TRUE 1
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SH 3
# define BLACK 0x000000
# define WHITE 0xffffff
# define RED 0xFF1001
# define BLUE 0x10FF01
# define GREEN 0x1001FF
# define ORANGE 0xff7f24
# define KEYPRESSMASK (1L << 0)
# define BUTTONPRESSMASK (1L << 2)
# define MOTIONNOTIFYMASK (1L << 6)
# define KEYPRESS 2
# define BUTTONPRESS 4
# define MOTIONNOTIFY 6
# define THREAD 30

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
	int			i;
	int			*img_str;
	int			img_size;
	int			frac_nbr;
	int			freeze;
	int			info;
	int			ret;
	int			ret_color;
	int			menu_color;
	int			h_th;
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

typedef struct	s_thread
{
	t_mlx		*mlx;
	pthread_t	id;
	int			y;
}				t_thread;

void			*is_mandelbrot(void *arg);
int				is_julia(t_mlx *mlx, int x, int y);
int				is_burning_ship(t_mlx *mlx, int x, int y);
int				draw_fractol(t_mlx *mlx, int flag
						, void *(*fractal)(void *));
void			draw_menu(t_mlx *mlx);
void			fill_pixel(t_mlx *mlx, int x, int y, int c);
int				usage(char *error);
void			init_mlx(t_mlx *mlx);
void			init_scope(t_mlx *mlx);
int				get_color(t_mlx *mlx, int iter);
void			ft_close(t_mlx *mlx);
void			ft_zoom(t_mlx *mlx, int key);
void			ft_iterate(t_mlx *mlx, int key);
void			ft_move(t_mlx *mlx, int key);
void			ft_reset(t_mlx *mlx);
void			ft_next(t_mlx *mlx);
void			ft_color(t_mlx *mlx);
int				ft_mouse_zoom(int key, int x, int y, t_mlx *mlx);
int				ft_mouse_julia(int x, int y, t_mlx *mlx);
void			ft_freeze_julia(t_mlx *mlx);
void			ft_info(t_mlx *mlx);
void			ft_menu_color(t_mlx *mlx);
void			ft_ret_color(t_mlx *mlx);

#endif
