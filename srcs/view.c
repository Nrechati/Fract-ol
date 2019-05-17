/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:05:24 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/17 16:05:53 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_reset(t_mlx *mlx)
{
	mlx->x_pad = 0.5;
	mlx->y_pad = 0;
	mlx->zoom = 1;
	mlx->iter = 100;
	draw_fractol(mlx, TRUE, mlx->fractal);
}

void	ft_color(t_mlx *mlx)
{
	if (mlx->c == BLUE)
		mlx->c = GREEN;
	else if (mlx->c == GREEN)
		mlx->c = RED;
	else if (mlx->c == RED)
		mlx->c = BLUE;
	draw_fractol(mlx, TRUE, mlx->fractal);
}

void	ft_next(t_mlx *mlx)
{
	if (mlx->frac_nbr == MANDELBROT)
	{
		mlx->frac_nbr = JULIA;
		mlx->fractal = is_julia;
		init_scope(mlx);
	}
	else if (mlx->frac_nbr == JULIA)
	{
		mlx->frac_nbr = BURNING_SH;
		mlx->fractal = is_burning_ship;
		init_scope(mlx);
	}
	else if (mlx->frac_nbr == BURNING_SH)
	{
		mlx->frac_nbr = MANDELBROT;
		mlx->fractal = is_mandelbrot;
		init_scope(mlx);
	}
	draw_fractol(mlx, TRUE, mlx->fractal);
}
