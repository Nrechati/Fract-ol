/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 10:17:51 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/14 15:46:15 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_move(t_mlx *mlx, int key)
{
	if ((key == 126 || key == 13) && mlx->y_pad > -10000)
		mlx->y_pad += 0.05 / mlx->zoom;
	else if ((key == 125 || key == 1) && mlx->y_pad < 10000)
		mlx-> y_pad -= 0.05 / mlx->zoom;
	else if ((key == 123 || key == 0) && mlx->x_pad > -10000)
		mlx->x_pad -= 0.05 / mlx->zoom;
	else if ((key == 124 || key == 2) && mlx->x_pad < 10000)
		mlx->x_pad += 0.05 / mlx->zoom;
	draw_fractol(mlx, TRUE, mlx->fractal);
}

void	ft_close(t_mlx *mlx)
{
	int		i;

	i = 0;
	mlx_destroy_image(mlx->ptr, mlx->img);
	exit(0);
}

void	ft_color(t_mlx *mlx)
{
	if (mlx->c == BLUE)
		mlx->c = GREEN;
	else if (mlx->c == GREEN)
		mlx->c = ORANGE;
	else if (mlx->c == ORANGE)
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
	}
	else if (mlx->frac_nbr == JULIA)
	{
		mlx->frac_nbr = BURNING_SH;
		mlx->fractal = is_burning_ship;
	}
	else if (mlx->frac_nbr == BURNING_SH)
	{
		mlx->frac_nbr = MANDELBROT;
		mlx->fractal = is_mandelbrot;
	}
	draw_fractol(mlx, TRUE, mlx->fractal);
}

void	ft_zoom(t_mlx *mlx, int key)
{
	if (key == 69 || key == 24)
		mlx->zoom += 0.1;
	else if (mlx->zoom > 1)
		mlx->zoom -= 0.1;
	draw_fractol(mlx, TRUE, mlx->fractal);
}

void	ft_iterate(t_mlx *mlx, int key)
{
	if (key == 47 && mlx->iter < INT_MAX - 100)
		mlx->iter += 100;
	else if (mlx->iter > 100)
		mlx->iter -= 100;
	draw_fractol(mlx, TRUE, mlx->fractal);
}

void	ft_reset(t_mlx *mlx)
{
	mlx->x_pad = 0.5;
	mlx->y_pad = 0;
	mlx->zoom = 1;
	mlx->iter = 100;
	draw_fractol(mlx, TRUE, mlx->fractal);
}
