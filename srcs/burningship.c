/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 15:18:51 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/15 14:45:19 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	iterate_burning_ship(t_mlx *mlx, t_comp c)
{
	t_comp	z;
	double	re_sq;
	double	im_sq;

	mlx->i = 0;
	z.re = 0;
	z.im = 0;
	re_sq = 0;
	im_sq = 0;
	while (mlx->i <= mlx->iter && re_sq + im_sq <= 4)
	{
		z.re = fabs(z.re);
		z.im = fabs(z.im);
		z.im = (z.re + z.im) * (z.re + z.im) - re_sq - im_sq;
		z.im += c.im;
		z.re = re_sq - im_sq + c.re;
		re_sq = z.re * z.re;
		im_sq = z.im * z.im;
		mlx->i++;
	}
	if (mlx->i <= mlx->iter)
		return (SUCCESS);
	return (FAILURE);
}

int			is_burning_ship(t_mlx *mlx, int x, int y)
{
	int i;
	t_comp c;

	i = 0;
	c.re = 2 * (x - mlx->w2) / (mlx->zoom * mlx->w2) - mlx->x_pad;
	c.im = (y - mlx->h2) / (mlx->zoom * mlx->h2) + mlx->y_pad;
	return (iterate_burning_ship(mlx, c));
}
