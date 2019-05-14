/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 12:01:51 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/14 15:17:30 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		usage(char *error)
{
	ft_printf("\x1b[41mFractol: %s\n\x1b[0m", error);
	ft_printf("Usage: ./Fractol [fractal_name]\n");
	ft_printf("Possible choices:\n\t. -h [help]\n\t. Mandelbrot");
	ft_printf("\n\t. Julia\n\t. BurningShip\n");
	return (FAILURE);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->h = 720;
	mlx->h2 = mlx->h/2;
	mlx->w = 1280;
	mlx->w2 = mlx->w/2;
	mlx->c = BLUE;
	mlx->x_pad = 0.5;
	mlx->y_pad = 0;
	mlx->zoom = 1;
	mlx->iter = 100;
	mlx->img = NULL;
	mlx->img_str = NULL;
	mlx->img_size = mlx->w * mlx->h;
	mlx->ptr = mlx_init();
	mlx->julia.re = -0.8;
	mlx->julia.im = 0.156;
	mlx->win = mlx_new_window(mlx->ptr, mlx->w, mlx->h, "Fractol");
}
