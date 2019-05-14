/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 14:25:00 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/14 16:18:04 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		iterate_julia(t_mlx *mlx, t_comp pt)
{
	int 	i;
	t_comp	z;
	t_comp	bk;

	i = 0;
	z.re = pt.re;
	z.im = pt.im;
	while (i < mlx->iter)
	{
		bk.re = z.re;
		bk.im = z.im;
		z.re = bk.re * bk.re - bk.im * bk.im + mlx->julia.re;
		z.im = 2 * bk.re * bk.im + mlx->julia.im;
		if (z.re * z.re + z.im * z.im > 4)
			return (SUCCESS);
		i++;
	}
	return (FAILURE);
}

int				is_julia(t_mlx *mlx, int x, int y)
{
	int 	i;
	t_comp	pt;

	i = 0;
	mlx->x_pad = 0;
	mlx->y_pad = 0;
	pt.re = 2 * (x - mlx->w2) / (mlx->zoom * mlx->w2) - mlx->x_pad;
	pt.im = (y - mlx->h2) / (mlx->zoom * mlx->h2) + mlx->y_pad;
	return (iterate_julia(mlx, pt));
}
