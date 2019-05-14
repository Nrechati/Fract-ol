/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:31:22 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/13 15:49:10 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
static t_comp	square_z(t_comp z)
{
	int		re;

	re = z.re;
	z.re = pow(z.re, 2) - pow(z.im, 2);
	z.im = 2 * z.im * re;
	return (z);
}
*/
static int		iterate_mandelbrot(t_comp c, int iterations)
{
	int 	i;
	t_comp	z;
	t_comp	bk;

	i = 0;
	z.re = 0;
	z.im = 0;
	while (i < iterations)
	{
		bk.re = z.re;
		bk.im = z.im;
		z.re = bk.re * bk.re - bk.im * bk.im + c.re;
		z.im = 2 * bk.re * bk.im + c.im;
		if (z.re * z.re + z.im * z.im > 4)
			return (-1);
		i++;
	}
	return (0);
}

static int		is_mandelbrot(t_mlx *mlx, int x, int y, int iterations)
{
	int 	i;
	t_comp	c;

	i = 0;
	c.re = 1.5 * (x - mlx->w / 2) / (0.5 * 1 * mlx->w) - 0.5;
	c.im = (y - mlx->l / 2) / (0.5 * 1 * mlx->l) + 0;
	return (iterate_mandelbrot(c, iterations));
}

void	init_img(t_mlx *mlx)
{
	int bpp;
	int s_l;
	int endian;

	mlx->img = mlx_new_image(mlx->ptr, mlx->w, mlx->l);
	mlx->img_str = (int *)mlx_get_data_addr(mlx->img, &bpp, &s_l, &endian);
}

void	fill_pixel(t_mlx *mlx, int x, int y, int c)
{
//	int		index;

//	index = 0 + (y * mlx->w) + x;
	if (x >= 0 && y >= 0 && x < mlx->w && y < mlx->l)
		mlx->img_str[x + mlx->w * y] = c;
}

int				draw_fractol(t_mlx *mlx, t_map *map, int flag, char **av)
{
	int index_x;
	int index_y;
	(void)map;
	(void)flag;
	if (flag == 0)
		mlx_destroy_image(mlx->ptr, mlx->img);
	init_img(mlx);
	index_y = 0;
	while (index_y < mlx->l)
	{
		index_x = 0;
		while (index_x < mlx->w)
		{
			if ((is_mandelbrot(mlx, index_x, index_y, ft_atoi(av[1]))) == -1)
				fill_pixel(mlx, index_x, index_y, GREEN);
			else
				fill_pixel(mlx, index_x, index_y, ORANGE);

			index_x++;
		}
		index_y++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	draw_menu(mlx);
	return (1);
}
