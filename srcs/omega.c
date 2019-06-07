/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   omega.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:14:07 by nrechati          #+#    #+#             */
/*   Updated: 2019/06/07 10:23:09 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		iterate_omega(t_mlx *mlx, t_comp c)
{
	int		i;
	t_comp	z;
	double	re_sq;
	double	im_sq;

	i = 0;
	z.re = 0;
	z.im = 0;
	re_sq = 0;
	im_sq = 0;
	while (i <= mlx->iter && re_sq + im_sq <= 4)
	{
		re_sq = c.re * c.re;
		im_sq = c.im * c.im;
		c.im = 2 * c.re * c.im)
		c.re = re_sq - im_sq;
		z.re = sinh(z.re) + (1 / c.re);
		z.im = sinh(z.im) + (1 / c.im);
		i++;
	}
	if (i <= mlx->iter)
		return (i);
	return (FAILURE);
}

static void		compute_line_omega(t_thread *thd, int y, t_comp c)
{
	int		x;
	int		iter;

	iter = 0;
	x = 0;
	while (x < thd->mlx->w)
	{
		c.re = 2 * (x - thd->mlx->w2)
				/ (thd->mlx->zoom * thd->mlx->w2) - thd->mlx->x_pad;
		if ((iter = iterate_omega(thd->mlx, c)) != FAILURE)
			fill_pixel(thd->mlx, x, y, get_color(thd->mlx, iter));
		x++;
	}
}

void			*is_omega(void *arg)
{
	int			max;
	int			y;
	t_comp		c;
	t_thread	*thd;

	thd = (t_thread *)arg;
	y = thd->y;
	max = y + thd->mlx->h_th;
	while (y < max)
	{
		c.im = (y - thd->mlx->h2)
				/ (thd->mlx->zoom * thd->mlx->h2) + thd->mlx->y_pad;
		compute_line_omega(thd, y, c);
		y++;
	}
	return (NULL);
}
