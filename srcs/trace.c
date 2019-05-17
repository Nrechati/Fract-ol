/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:31:22 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/17 12:50:11 by nrechati         ###   ########.fr       */
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

void			fill_pixel(t_mlx *mlx, int x, int y, int c)
{
	if (x >= 0 && y >= 0 && x < mlx->w && y < mlx->h)
		mlx->img_str[x + mlx->w * y] = c;
}

int 			draw_fractol(t_mlx *mlx, int flag
						, void *(*fractal)(void *))
{
	int			i;
	t_thread	thd[THREAD];

	if (flag == TRUE)
		mlx_destroy_image(mlx->ptr, mlx->img);
	init_img(mlx);
	i = 0;
	while (i < THREAD)
	{
		thd[i].mlx = mlx;
		thd[i].y = i * mlx->h_th;
		pthread_create(&(thd[i].id), NULL, fractal, (void *)&(thd[i]));
		i++;
	}
	i = 0;
	while (i < THREAD)
	{
		pthread_join(thd[i].id, NULL);
		i++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	draw_menu(mlx);
	return (SUCCESS);
}
