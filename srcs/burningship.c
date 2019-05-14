/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 15:18:51 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/14 17:08:11 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	iterate_burning_ship(t_mlx *mlx, t_comp c)
{
	t_comp z;
	t_comp bk;

	mlx->i = 0;
	z.re = 0;
	z.im = 0;
	while (mlx->i < mlx->iter)
	{
		bk.re = fabs(z.re);
		bk.im = fabs(z.im);
		z.re = bk.re * bk.re - bk.im * bk.im + c.re;
		z.im = 2 * bk.re * bk.im + c.im;
		if (z.re * z.re + z.im * z.im > 4)
			return (SUCCESS);
		mlx->i++;
	}
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
