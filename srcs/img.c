/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:51:42 by nrechati          #+#    #+#             */
/*   Updated: 2019/01/09 11:33:36 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_img(t_mlx *mlx)
{
	int bpp;
	int s_l;
	int endian;

	mlx->img = mlx_new_image(mlx->ptr, mlx->w, mlx->l);
	mlx->img_str = (int *)mlx_get_data_addr(mlx->img, &bpp, &s_l, &endian);
}

void	fill_pixel(t_mlx *mlx, int x, int y)
{
	int		index;

	index = 0 + (y * mlx->w) + x;
	if (x < mlx->w && x > 0 && index <= mlx->img_size && index >= 0)
		mlx->img_str[index] = mlx->c;
}
