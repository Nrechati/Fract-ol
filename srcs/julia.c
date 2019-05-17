/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 14:25:00 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/17 14:16:42 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		iterate_julia(t_mlx *mlx, t_comp pt)
{
	int		i;
	t_comp	z;
	double	re_sq;
	double	im_sq;

	i = 0;
	z.re = pt.re;
	z.im = pt.im;
	re_sq = 0;
	im_sq = 0;
	while (i <= mlx->iter && re_sq + im_sq <= 4)
	{
		re_sq = z.re * z.re;
		im_sq = z.im * z.im;
		z.im = (z.re + z.im) * (z.re + z.im) - re_sq - im_sq;
		z.im += mlx->julia.im;
		z.re = re_sq - im_sq + mlx->julia.re;
		i++;
	}
	if (i <= mlx->iter)
		return (i);
	return (FAILURE);
}

static void	compute_line_julia(t_thread *thd, int y, t_comp c)
{
	int		x;
	int		iter;

	iter = 0;
	x = 0;
	while (x < thd->mlx->w)
	{
		c.re = 2 * (x - thd->mlx->w2)
				/ (thd->mlx->zoom * thd->mlx->w2) - thd->mlx->x_pad;
		if ((iter = iterate_julia(thd->mlx, c)) != FAILURE)
			fill_pixel(thd->mlx, x, y, get_color(thd->mlx, iter));
		x++;
	}
}

void			*is_julia(void *arg)
{
	int max;
	int y;
	t_comp pt;
	t_thread *thd;

	thd = (t_thread *)arg;
	y = thd->y;
	max = y + thd->mlx->h_th;
	while (y < max)
	{
		pt.im = (y - thd->mlx->h2) / (thd->mlx->zoom * thd->mlx->h2) + thd->mlx->y_pad;
		compute_line_julia(thd, y, pt);
		y++;
	}
	return (NULL);
}
