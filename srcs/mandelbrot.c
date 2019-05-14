/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 10:22:17 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/14 15:09:27 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		iterate_mandelbrot(t_mlx *mlx, t_comp c)
{
	int 	i;
	t_comp	z;
	t_comp	bk;

	i = 0;
	z.re = 0;
	z.im = 0;
	while (i < mlx->iter)
	{
		bk.re = z.re;
		bk.im = z.im;
		z.re = bk.re * bk.re - bk.im * bk.im + c.re;
		z.im = 2 * bk.re * bk.im + c.im;
		if (z.re * z.re + z.im * z.im > 4)
			return (SUCCESS);
		i++;
	}
	return (FAILURE);
}

int				is_mandelbrot(t_mlx *mlx, int x, int y)
{
	int 	i;
	t_comp	c;

	i = 0;
	c.re = 2 * (x - mlx->w2) / (mlx->zoom * mlx->w2) - mlx->x_pad;
	c.im = (y - mlx->h2) / (mlx->zoom * mlx->h2) + mlx->y_pad;
	return (iterate_mandelbrot(mlx, c));
}
