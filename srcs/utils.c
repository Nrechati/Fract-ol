/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 12:01:51 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/17 17:54:54 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_scope(t_mlx *mlx)
{
	if (mlx->frac_nbr == MANDELBROT)
	{
		mlx->x_pad = 0.5;
		mlx->y_pad = 0;
	}
	if (mlx->frac_nbr == JULIA)
	{
		mlx->x_pad = 0;
		mlx->y_pad = 0;
	}
	if (mlx->frac_nbr == BURNING_SH)
	{
		mlx->x_pad = 0.5;
		mlx->y_pad = -0.5;
	}
}

int		get_color(t_mlx *mlx, int iter)
{
	int		color;

	color = (1 - (iter / mlx->iter)) * mlx->c;
	return (color);
}

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
	mlx->h2 = mlx->h / 2;
	mlx->w = 1280;
	mlx->w2 = mlx->w / 2;
	mlx->c = GREEN;
	mlx->zoom = 1;
	mlx->iter = 100;
	mlx->img = NULL;
	mlx->img_str = NULL;
	mlx->img_size = mlx->w * mlx->h;
	mlx->ptr = mlx_init();
	mlx->julia.re = -0.8;
	mlx->julia.im = 0.156;
	mlx->freeze = FALSE;
	mlx->info = FALSE;
	mlx->ret = FALSE;
	mlx->ret_color = RED;
	mlx->menu_color = BLACK;
	mlx->h_th = mlx->h / THREAD;
	mlx->win = mlx_new_window(mlx->ptr, mlx->w, mlx->h, "Fractol");
}
