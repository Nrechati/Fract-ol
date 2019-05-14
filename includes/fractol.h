/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:01:13 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/14 11:27:24 by nrechati         ###   ########.fr       */
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
# define BLACK 0x000000
# define GREEN 0x006c26
# define BLUE 0x166fe7
# define ORANGE 0xff7f24
# define KEYPRESSMASK (1L << 0)
# define KEYPRESS 2

typedef struct	s_mlx
{
	int			c;
	int			h;
	int			w;
	double		x_pad;
	double		y_pad;
	double		zoom;
	double		iter;
	int			*img_str;
	int			img_size;
	void		*ptr;
	void		*img;
	void		*win;
}				t_mlx;

typedef struct	s_comp
{
	double	re;
	double	im;
}				t_comp;

int				is_mandelbrot(t_mlx *mlx, int x, int y);
int				draw_fractol(t_mlx *mlx, int flag);
void			draw_menu(t_mlx *mlx);
void			ft_close(t_mlx *mlx);
void			ft_zoom(t_mlx *mlx, int key);
void			ft_iterate(t_mlx *mlx, int key);
void			ft_move(t_mlx *mlx, int key);

#endif
