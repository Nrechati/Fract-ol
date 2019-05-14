/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:31:22 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/14 17:11:58 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		init_img(t_mlx *mlx)
{
	int bpp;
	int s_l;
	int endian;

	mlx->img = mlx_new_image(mlx->ptr, mlx->w, mlx->h);
	mlx->img_str = (int *)mlx_get_data_addr(mlx->img, &bpp, &s_l, &endian);
}

static void		fill_pixel(t_mlx *mlx, int x, int y, int c)
{
	if (x >= 0 && y >= 0 && x < mlx->w && y < mlx->h)
		mlx->img_str[x + mlx->w * y] = c;
}

int 			draw_fractol(t_mlx *mlx, int flag
						, int (*fractal)(t_mlx*, int, int))
{
	int x;
	int y;

	if (flag == TRUE)
		mlx_destroy_image(mlx->ptr, mlx->img);
	init_img(mlx);
	y = 0;
	while (y < mlx->h)
	{
		x = 0;
		while (x < mlx->w)
		{
			if ((*fractal)(mlx, x, y) == SUCCESS)
				fill_pixel(mlx, x, y, get_color(mlx));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	draw_menu(mlx);
	return (SUCCESS);
}
