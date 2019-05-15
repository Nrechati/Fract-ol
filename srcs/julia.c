/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 14:25:00 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/15 11:41:55 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		iterate_julia(t_mlx *mlx, t_comp pt)
{
	t_comp	z;
	double	re_sq;
	double	im_sq;

	mlx->i = 0;
	z.re = pt.re;
	z.im = pt.im;
	re_sq = 0;
	im_sq = 0;
	while (mlx->i <= mlx->iter && re_sq + im_sq <= 4)
	{
		re_sq = z.re * z.re;
		im_sq = z.im * z.im;
		z.im = (z.re + z.im) * (z.re + z.im) - re_sq - im_sq;
		z.im += mlx->julia.im;
		z.re = re_sq - im_sq + mlx->julia.re;
		mlx->i++;
	}
	if (mlx->i <= mlx->iter)
		return (SUCCESS);
	return (FAILURE);
}

int				is_julia(t_mlx *mlx, int x, int y)
{
	int 	i;
	t_comp	pt;

	i = 0;
	pt.re = 2 * (x - mlx->w2) / (mlx->zoom * mlx->w2) - mlx->x_pad;
	pt.im = (y - mlx->h2) / (mlx->zoom * mlx->h2) + mlx->y_pad;
	return (iterate_julia(mlx, pt));
}
